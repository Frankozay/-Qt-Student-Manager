#include "stuinfor_manage.h"
#include "mainwindow.h"
#include "ui_stuinfor_manage.h"
#include <QMessageBox>
#include "globle.h"
#include <QtDebug>
#include "allstuinfor.h"

stuinfor_manage::stuinfor_manage(QWidget *parent) : QWidget(parent),
    ui(new Ui::stuinfor_manage)
{
    ui->setupUi(this);
    setWindowTitle(designer);
    ui->grade_Label->setText("0");
    ui->point_label->setText("0");
}

stuinfor_manage::~stuinfor_manage()
{
    delete ui;
}



void stuinfor_manage::on_search_Button_clicked()
{
    QString sno_search=ui->search_LineEdit->text();
    ui->sage_LineEdit->clear();
    ui->sno_LineEdit->clear();
    ui->ssex_LineEdit->clear();
    ui->sdept_LineEdit->clear();
    ui->sclass_LineEdit->clear();
    ui->sname_LineEdit->clear();
    ui->point_label->clear();
    ui->grade_Label->clear();


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
    query.exec("select Sno,Sname,Ssex,Sage,Sdept,Sclass,Spoint,Savg_grade "
               "from student where Sno = '"+sno_search+"'");

    if(query.next()){
        ui->sno_LineEdit->setText(query.value(0).toString());
        ui->sname_LineEdit->setText(query.value(1).toString());
        ui->ssex_LineEdit->setText(query.value(2).toString());
        ui->sage_LineEdit->setText(query.value(3).toString());
        ui->sdept_LineEdit->setText(query.value(4).toString());
        ui->sclass_LineEdit->setText(query.value(5).toString());
        ui->point_label->setText(query.value(6).toString());
        ui->grade_Label->setText(query.value(7).toString());
    }

    else{
        if(sno_search.compare("")==0)
            QMessageBox::information(this, "提示", "请输入学号");
        else
            QMessageBox::information(this, "提示", "所查学号不存在！");
    }
}



void stuinfor_manage::on_add_Button_clicked()
{
    QString no = ui->sno_LineEdit->text();
    QString name = ui->sname_LineEdit->text();
    QString sex = ui->ssex_LineEdit->text();
    QString age = ui->sage_LineEdit->text();
    QString dept = ui->sdept_LineEdit->text();
    QString clas = ui->sclass_LineEdit->text();

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
    query.exec("select Sno from student");
    bool T = true;
    while(query.next()){
        if(no.compare(query.value(0).toString())==0){
            QMessageBox::information(this ,tr("提示") , tr("该学号已存在"));
            T=false;
        }
    }
    if(T==true){
        QString sql;
        sql = QString("insert into student(Sno,Sname,Ssex,Sage,Sdept,Sclass,Spassword)"
                      " values('%1','%2','%3','%4','%5','%6','%7')")
                       .arg(no).arg(name).arg(sex).arg(age).arg(dept).arg(clas).arg(no);

        bool sc = query.exec(sql);
        if(sc){
            QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
        }
        else{
            QMessageBox::information(this ,tr("提示") , tr("添加失败!"));
        }
    }
}



void stuinfor_manage::on_deleteButton_clicked()
{
    QString sno=ui->sno_LineEdit->text();

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
    query.exec("select Sno from student");
    bool T=true;
    while(query.next()){
        QString sno_t = query.value(0).toString();

        if(sno_t.compare(sno)==0){
            T = false;
            QString sql;
            sql = QString("delete from student "
                          " where Sno = '%1'").arg(sno);
            QSqlQuery query;
            bool sc = query.exec(sql);
            if(sc){
                QMessageBox::information(this ,tr("提示") , tr("删除成功!"));
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



void stuinfor_manage::on_updateButton_clicked()
{
    QString no = ui->sno_LineEdit->text();
    QString name = ui->sname_LineEdit->text();
    QString sex = ui->ssex_LineEdit->text();
    QString age = ui->sage_LineEdit->text();
    QString dept = ui->sdept_LineEdit->text();
    QString clas = ui->sclass_LineEdit->text();

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
    query.exec("select Sno from student");
    bool T=true;
    while(query.next()){
        QString sno = query.value(0).toString();

        if(sno.compare(no)==0){
            QString sql;
            sql = QString("update student "
                          "set Sname = '%1',Ssex = '%2',Sage = '%3', Sdept = '%4', Sclass = '%5' "
                          "where Sno='%6'"
                          ).arg(name).arg(sex).arg(age).arg(dept).arg(clas).arg(no);
            QSqlQuery query;
            bool sc = query.exec(sql);
            T=false;
            if(sc){
                QMessageBox::information(this ,tr("提示") , tr("更改成功!"));
            }
            else{
                QMessageBox::information(this ,tr("提示") , tr("更改失败!"));
            }
        }
    }

    if(T==true){
        QMessageBox::information(this ,tr("提示") , tr("所改学号不存在!"));
    }
}

void stuinfor_manage::on_backButton_clicked()
{
    this->hide();
    manager *m=new manager;
    m->show();
}





void stuinfor_manage::on_seeallButton_clicked()
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
    query.exec("select Sno,Sname,Ssex,Sage,Sdept,Sclass,Spoint,Savg_grade "
               "from student"
               );
    while(query.next()){
        QStringList q;
        q.clear();
        QString no = query.value(0).toString();
        QString name = query.value(1).toString();
        QString sex = query.value(2).toString();
        QString age = query.value(3).toString();
        QString dept = query.value(4).toString();
        QString clas = query.value(5).toString();
        QString point = query.value(6).toString();
        QString grade = query.value(7).toString();
        q<<no<<name<<sex<<age<<dept<<clas<<point<<grade;
        list_all_student.append(q);
    }
    for(int i=0;i<list_all_student.size();i++){
        qDebug()<<list_all_student[i];
    }

    this->hide();
    allstuinfor *a = new allstuinfor;
    a->show();
}
