#include "sc_manage.h"
#include "ui_sc_manage.h"
#include "mainwindow.h"
#include "manager.h"
#include <QMessageBox>
#include "globle.h"
#include <QtDebug>
#include "allsc.h"

sc_manage::sc_manage(QWidget *parent) : QWidget(parent),
    ui(new Ui::sc_manage)
{
    ui->setupUi(this);
    setWindowTitle(designer);
}

sc_manage::~sc_manage()
{
    delete ui;
}

void sc_manage::update_pointNavg(QString sno)
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("student_project");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    if(!db.open())
        qDebug()<<"Failed to connect to root mysql admin";
    else
        qDebug()<<"success";

    QSqlQuery query(db);
    QString sql;
    sql = QString("select Cno,Grade from sc where Sno = '"+sno+"'");
    query.exec(sql);
    QVariantList g;
    QVariantList c;
    c.clear();
    g.clear();
    /*if(!query.next()){
        QSqlQuery queryt;
        queryt.exec("update student set Spoint=0 and Savg_grade=0 where Sno = '"+sno+"'");
        if(!queryt.next()){
            qDebug()<<"error";
        }
    }*/
    while(query.next()){
        double gt;
        QString ct;
        ct = query.value(0).toString();
        gt = query.value(1).toDouble();
        if(gt == -1)    continue;
        c.append(ct);
        g.append(gt);
    }

    int grade_list[11]={90,85,82,78,75,72,68,66,63,60,0};
    double point_list[11]={4.0,3.7,3.3,3,2.7,2.3,2.0,1.7,1.3,1,0};
    int count=g.size();
    double avg=0;
    double point_sum=0;
    double credit_sum=0;
    for(int i=0;i<g.size();i++){
        double credit=0;
        double point=0;
        double grade=g[i].toDouble();
        avg+=grade;

        QString cno= c[i].toString();
        QSqlQuery query;
        query.exec("select Ccredit from course where Cno='"+cno+"'");
        if(query.next()){
            credit = query.value(0).toDouble();
            credit_sum += credit;
        }
        else{
            qDebug()<<"unknown_error";
        }

        for(int j=0;j<11;j++){
            if(grade>=grade_list[j]){
                point = point_list[j];
                break;
            }
        }
        point_sum += point*credit;
    }
    avg/=count;
    double point = point_sum/credit_sum;
    QString avg_s=QString::number(avg,10,2);
    QString point_s = QString::number(point,10,2);
    QString sql1 = QString("update student "
                           "set Spoint = '%1',Savg_grade='%2' "
                           "where Sno = '%3'").arg(point_s).arg(avg_s).arg(sno);
    query.exec(sql1);
    if(query.next()){
        qDebug()<<"success";
    }
    else{
        qDebug()<<"fail";
    }
}

void sc_manage::on_searchButton_clicked()
{
    QString sno_search = ui->search_snoLineEdit->text();
    QString cno_search = ui->search_cnoLineEdit->text();
    ui->snoLineEdit->clear();
    ui->cnoLineEdit->clear();
    ui->gradeLineEdit->clear();

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("student_project");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    if(!db.open())
        qDebug()<<"Failed to connect to root mysql admin";
    else
        qDebug()<<"success";

    QSqlQuery query(db);
    QString sql;
    sql = QString("select Sno,Cno,Grade from sc where Sno = '%1' and Cno = '%2'").arg(sno_search).arg(cno_search);
    query.exec(sql);
    if(query.next()){
        ui->snoLineEdit->setText(query.value(0).toString());
        ui->cnoLineEdit->setText(query.value(1).toString());
        ui->gradeLineEdit->setText(query.value(2).toString());
    }
    else{
        if(sno_search.compare("")==0){
            QMessageBox::information(this,tr("提示"),tr("请输入学号"));
        }
        else if(cno_search.compare("")==0){
            QMessageBox::information(this,tr("提示"),tr("请输入课程号"));
        }
        else{
            QMessageBox::information(this,tr("提示"),tr("所查学号或课程号不存在！"));
        }
    }
}

void sc_manage::on_addButton_clicked()
{
    QString sno = ui->snoLineEdit->text();
    QString cno = ui->cnoLineEdit->text();
    QString grade = ui->gradeLineEdit->text();

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("student_project");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    if(!db.open())
        qDebug()<<"Failed to connect to root mysql admin";
    else
        qDebug()<<"success";

    QSqlQuery query(db);
    QString sql = QString("select Sno,Cno from sc where Sno ='%1' and Cno ='%2'").arg(sno).arg(cno);
    query.exec(sql);
    bool T=true;
    while(query.next()){
        QString sno_t=query.value(0).toString();
        QString cno_t=query.value(1).toString();
        if(sno.compare(sno_t)==0 && cno.compare(cno_t)==0){
            QMessageBox::information(this,tr("提示"),tr("已有此学生该科成绩！"));
            T=false;
        }
    }
    if(T==true){
        QString sql;
        if(grade.compare("")==0)    grade=QString("-1");
        sql = QString("insert into sc(Sno,Cno,Grade)"
                      " values('%1','%2','%3')")
                       .arg(sno).arg(cno).arg(grade);

        bool sc = query.exec(sql);
        if(sc){
            QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
            update_pointNavg(sno);
        }
        else{
            QMessageBox::information(this ,tr("提示") , tr("添加失败!"));
        }
    }
}

void sc_manage::on_updateButton_clicked()
{
    QString sno = ui->snoLineEdit->text();
    QString cno = ui->cnoLineEdit->text();
    QString grade = ui->gradeLineEdit->text();

    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("student_project");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    if(!db.open())
        qDebug()<<"Failed to connect to root mysql admin";
    else
        qDebug()<<"success";

    QSqlQuery query(db);
    QString sql = QString("select Sno,Cno,Grade from sc where Sno ='%1' and Cno ='%2'").arg(sno).arg(cno);
    query.exec(sql);
    bool T =true;
    while(query.next()){
        QString sno_t = query.value(0).toString();
        QString cno_t = query.value(1).toString();
        QString Grade_t = query.value(2).toString();
        if(sno_t.compare(sno)==0 && cno_t.compare(cno)==0){
            QString sql;
            if(grade.compare("")==0)    grade=QString("-1");
            if(grade.compare(Grade_t)==0)   break;
            sql = QString("update sc "
                          "set Grade = '%1' "
                          "where Sno='%2' and Cno = '%3'"
                          ).arg(grade).arg(sno).arg(cno);
            QSqlQuery query;
            bool sc = query.exec(sql);
            T=false;
            if(sc){
                QMessageBox::information(this ,tr("提示") , tr("更改成功!"));
                update_pointNavg(sno);
            }
            else{
                QMessageBox::information(this ,tr("提示") , tr("更改失败!"));
            }
        }
    }

    if(T==true){
        QMessageBox::information(this ,tr("提示") , tr("所改学号或课程号不存在!或成绩相同！"));
    }
}



void sc_manage::on_deleteButton_clicked()
{
    QString sno = ui->snoLineEdit->text();
    QString cno = ui->cnoLineEdit->text();
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("student_project");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    if(!db.open())
        qDebug()<<"Failed to connect to root mysql admin";
    else
        qDebug()<<"success";

    QSqlQuery query(db);
    query.exec("select Sno,Cno from sc");
    bool T=true;
    while(query.next()){
        QString sno_t = query.value(0).toString();
        QString cno_t = query.value(1).toString();
        if(sno_t.compare(sno)==0 && cno_t.compare(cno)==0){
            T = false;
            QString sql;
            sql = QString("delete from sc "
                          " where Sno = '%1' and Cno ='%2'").arg(sno).arg(cno);
            QSqlQuery query;
            bool sc = query.exec(sql);
            if(sc){
                QMessageBox::information(this ,tr("提示") , tr("删除成功!"));
                update_pointNavg(sno);
            }
            else{
                QMessageBox::information(this ,tr("提示") , tr("删除失败!"));
            }
        }
    }
    if(T==true){
        QMessageBox::information(this ,tr("提示") , tr("所删学号不存在!"));
    }
}

void sc_manage::on_backButton_clicked()
{
    this->hide();
    manager *m = new manager;
    m->show();
}





void sc_manage::on_allgradeLineEdit_clicked()
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("student_project");
    db.setUserName(sqluser);
    db.setPassword(sqlpass);
    if(!db.open())
        qDebug()<<"Failed to connect to root mysql admin";
    else
        qDebug()<<"success";

    QSqlQuery query(db);
    query.exec("select Sno,Cno,Grade "
               "from sc"
               );
    while(query.next()){
        QStringList q;
        q.clear();
        QString sno = query.value(0).toString();
        QString cno = query.value(1).toString();
        QString grade = query.value(2).toString();
        q<<sno<<cno<<grade;
        list_all_sc.append(q);
    }
    for(int i=0;i<list_all_sc.size();i++){
        qDebug()<<list_all_sc[i];
    }

    this->hide();
    allsc *a = new allsc;
    a->show();
}
