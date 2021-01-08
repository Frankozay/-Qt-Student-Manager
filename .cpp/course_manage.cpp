#include "course_manage.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "globle.h"
#include <QtDebug>
#include "ui_course_manage.h"
#include "manager.h"
#include "allcourses.h"

course_manage::course_manage(QWidget *parent) : QWidget(parent),
    ui(new Ui::course_manage)
{
    ui->setupUi(this);
    setWindowTitle(designer);
}

course_manage::~course_manage()
{
    delete ui;
}


void course_manage::on_searchpushButton_clicked()
{
    QString cno_search=ui->searchlineEdit->text();
    ui->cnamelineEdit->clear();
    ui->ccreditlineEdit->clear();
    ui->cteacherlineEdit->clear();
    ui->cplacelineEdit->clear();
    ui->cnoLineEdit->clear();

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
    query.exec("select Cno,Cname,Ccredit,CTeacher,Cplace "
               "from course where Cno = '"+cno_search+"'");

    if(query.next()){
        ui->cnoLineEdit->setText(query.value(0).toString());
        ui->cnamelineEdit->setText(query.value(1).toString());
        ui->ccreditlineEdit->setText(query.value(2).toString());
        ui->cteacherlineEdit->setText(query.value(3).toString());
        ui->cplacelineEdit->setText(query.value(4).toString());
    }

    else{
        if(cno_search.compare("")==0)
            QMessageBox::information(this, "提示", "请输入课程号");
        else
        QMessageBox::information(this, "提示", "所查课程号不存在！");
    }
}

void course_manage::on_addPushButton_clicked()
{
    QString no = ui->cnoLineEdit->text();
    QString name = ui->cnamelineEdit->text();
    QString credit = ui->ccreditlineEdit->text();
    QString teacher = ui->cteacherlineEdit->text();
    QString place = ui->cplacelineEdit->text();

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
    query.exec("select Cno from course");
    bool T = true;
    while(query.next()){
        if(no.compare(query.value(0).toString())==0){
            QMessageBox::information(this ,tr("提示") , tr("该课程号已存在"));
            T=false;
        }
    }
    if(T==true){
        QString sql;
        sql = QString("insert into course(Cno,Cname,Ccredit,CTeacher,Cplace) "
                      "values('%1','%2','%3','%4','%5')")
                       .arg(no).arg(name).arg(credit).arg(teacher).arg(place);

        bool sc = query.exec(sql);
        if(sc){
            QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
        }
        else{
            QMessageBox::information(this ,tr("提示") , tr("添加失败!"));
        }
    }
}


void course_manage::on_deletePushButton_clicked()
{
    QString cno=ui->cnoLineEdit->text();

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
    query.exec("select Cno from course");
    bool T=true;
    while(query.next()){
        QString cno_t = query.value(0).toString();

        if(cno_t.compare(cno)==0){
            T = false;
            QString sql;
            sql = QString("delete from course "
                          " where Cno = '%1'").arg(cno);
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
        QMessageBox::information(this ,tr("提示") , tr("所删课程号不存在!"));
    }
}

void course_manage::on_updatePushButton_clicked()
{
    QString no = ui->cnoLineEdit->text();
    QString name = ui->cnamelineEdit->text();
    QString credit = ui->ccreditlineEdit->text();
    QString teacher = ui->cteacherlineEdit->text();
    QString place = ui->cplacelineEdit->text();

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
    query.exec("select Cno from course");
    bool T=true;
    while(query.next()){
        QString cno = query.value(0).toString();

        if(cno.compare(no)==0){
            QString sql;
            sql = QString("update course "
                          "set Cname = '%1',Ccredit = '%2',Cteacher = '%3', Cplace = '%4' "
                          "where Cno='%5'"
                          ).arg(name).arg(credit).arg(teacher).arg(place).arg(no);
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
        QMessageBox::information(this ,tr("提示") , tr("所改课程号不存在!"));
    }
}




void course_manage::on_backPushButton_clicked()
{
    this->hide();
    manager *m=new manager;
    m->show();
}



void course_manage::on_allCoursePushButton_clicked()
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
    query.exec("select Cno,Cname,Ccredit,CTeacher,Cplace "
               "from course"
               );
    while(query.next()){
        QStringList q;
        q.clear();
        QString no = query.value(0).toString();
        QString name = query.value(1).toString();
        QString credit = query.value(2).toString();
        QString teacher = query.value(3).toString();
        QString place = query.value(4).toString();
        q<<no<<name<<credit<<teacher<<place;
        list_all_course.append(q);
    }
    for(int i=0;i<list_all_course.size();i++){
        qDebug()<<list_all_course[i];
    }

    this->hide();
    allcourses *a = new allcourses;
    a->show();
}
