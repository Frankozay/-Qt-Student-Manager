#include "stu_scorequery.h"
#include "ui_stu_scorequery.h"
#include "globle.h"
#include "mainwindow.h"
#include "student.h"
#include <QtDebug>
#include <QMessageBox>
#include "all_grade.h"

stu_scorequery::stu_scorequery(QWidget *parent) : QWidget(parent),
    ui(new Ui::stu_scorequery)
{
    ui->setupUi(this);
    setWindowTitle(designer);
}

stu_scorequery::~stu_scorequery()
{
    delete ui;
}



void stu_scorequery::on_snoButton_clicked()
{
    QString no = ui->sno_lineEdit->text();

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
    query.exec("select sc.Sno,Sname,sc.Cno,Cname,Grade,Ccredit,CTeacher from sc,student,course where "
               "sc.Sno = student.Sno and sc.Cno = course.Cno and student.Sno = '"+no+"'");
    bool T = false;
    while(query.next()){
        T = true;
        QStringList q;
        q.clear();
        QString sno = query.value(0).toString();
        QString sname = query.value(1).toString();
        QString cno = query.value(2).toString();
        QString cname = query.value(3).toString();
        QString grade = query.value(4).toString();
        QString credit = query.value(5).toString();
        QString teacher = query.value(6).toString();
        if(grade.compare("-1")==0)  continue;
        q<<sno<<sname<<cno<<cname<<grade<<credit<<teacher;
        list_grade.append(q);
    }
    if(T==true){
        for(int i=0;i<list_grade.size();i++){
            qDebug()<<list_grade[i];
        }

        this->hide();
        all_grade *a = new all_grade;
        a->show();
    }
    else{
        if(no.compare("")==0)    QMessageBox::information(this,tr("提示"),tr("请输入学号！"));
        else    QMessageBox::information(this,tr("提示"),tr("不存在所查学号或不存在其成绩信息"));
    }

}

void stu_scorequery::on_snameButton_clicked()
{
    QString name = ui->sname_lineEdit->text();

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
    query.exec("select sc.Sno,Sname,sc.Cno,Cname,Grade,Ccredit,CTeacher from sc,student,course where "
               "sc.Sno = student.Sno and sc.Cno = course.Cno and student.Sname = '"+name+"'");
    bool T = false;
    while(query.next()){
        T = true;
        QStringList q;
        q.clear();
        QString sno = query.value(0).toString();
        QString sname = query.value(1).toString();
        QString cno = query.value(2).toString();
        QString cname = query.value(3).toString();
        QString grade = query.value(4).toString();
        QString credit = query.value(5).toString();
        QString teacher = query.value(6).toString();
        if(grade.compare("-1")==0)  continue;
        q<<sno<<sname<<cno<<cname<<grade<<credit<<teacher;
        list_grade.append(q);
    }
    if(T==true){
        for(int i=0;i<list_grade.size();i++){
            qDebug()<<list_grade[i];
        }

        this->hide();
        all_grade *a = new all_grade;
        a->show();
    }
    else{
        if(name.compare("")==0)    QMessageBox::information(this,tr("提示"),tr("请输入姓名！"));
        else    QMessageBox::information(this,tr("提示"),tr("不存在所查姓名或不存在其成绩信息"));
    }
}

void stu_scorequery::on_backButton_clicked()
{
    this->hide();
    student *s = new student;
    s->show();
}
