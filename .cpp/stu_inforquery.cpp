#include "stu_inforquery.h"
#include "ui_stu_inforquery.h"
#include "globle.h"
#include "student.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QtDebug>

stu_inforquery::stu_inforquery(QWidget *parent) : QWidget(parent),
    ui(new Ui::stu_inforquery)
{
    ui->setupUi(this);
    setWindowTitle(designer);
    ui->ageLabel->clear();
    ui->avgLabel->clear();
    ui->nameLabel->clear();
    ui->noLabel->clear();
    ui->deptLabel->clear();
    ui->pointLabel->clear();
    ui->classLabel->clear();
    ui->sexLabel->clear();
}

stu_inforquery::~stu_inforquery()
{
    delete ui;
}


void stu_inforquery::on_sno_pushButton_clicked()
{
    QString sno = ui->sno_lineEdit->text();

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
    query.exec("select Sno,Sname,Ssex,Sage,Sdept,Sclass,Spoint,Savg_grade from student where Sno='"+sno+"'");
    if(query.next()){
        QString no=query.value(0).toString();
        QString name=query.value(1).toString();
        QString sex=query.value(2).toString();
        QString age=query.value(3).toString();
        QString dept=query.value(4).toString();
        QString clas=query.value(5).toString();
        QString point=query.value(6).toString();
        QString avg=query.value(7).toString();
        ui->noLabel->setText(no);
        ui->nameLabel->setText(name);
        ui->sexLabel->setText(sex);
        ui->ageLabel->setText(age);
        ui->deptLabel->setText(dept);
        ui->classLabel->setText(clas);
        ui->pointLabel->setText(point);
        ui->avgLabel->setText(avg);
    }
    else{
        if(sno.compare("")==0)  QMessageBox::information(this,tr("提示"),tr("请输入学号！"));
        else QMessageBox::information(this,tr("提示"),tr("所查学号不存在！"));
    }
}

void stu_inforquery::on_sname_pushButton_clicked()
{
    QString sname = ui->sname_lineEdit->text();

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
    query.exec("select Sno,Sname,Ssex,Sage,Sdept,Sclass,Spoint,Savg_grade from student where Sname='"+sname+"'");
    if(query.next()){
        QString no=query.value(0).toString();
        QString name=query.value(1).toString();
        QString sex=query.value(2).toString();
        QString age=query.value(3).toString();
        QString dept=query.value(4).toString();
        QString clas=query.value(5).toString();
        QString point=query.value(6).toString();
        QString avg=query.value(7).toString();
        ui->noLabel->setText(no);
        ui->nameLabel->setText(name);
        ui->sexLabel->setText(sex);
        ui->ageLabel->setText(age);
        ui->deptLabel->setText(dept);
        ui->classLabel->setText(clas);
        ui->pointLabel->setText(point);
        ui->avgLabel->setText(avg);
    }
    else{
        if(sname.compare("")==0)  QMessageBox::information(this,tr("提示"),tr("请输入姓名！"));
        else QMessageBox::information(this,tr("提示"),tr("所查姓名不存在！"));
    }
}



void stu_inforquery::on_backButton_clicked()
{
    this->hide();
    student *s = new student;
    s->show();
}
