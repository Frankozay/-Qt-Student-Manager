#include "stu_changepass.h"
#include "ui_stu_changepass.h"
#include "student.h"
#include "globle.h"
#include "mainwindow.h"
#include <QtDebug>
#include <QMessageBox>

stu_changepass::stu_changepass(QWidget *parent) : QWidget(parent),
    ui(new Ui::stu_changepass)
{
    ui->setupUi(this);
    ui->password_lineEdit->setEchoMode(QLineEdit::Password);
    setWindowTitle(designer);
}

stu_changepass::~stu_changepass()
{
    delete ui;
}


void stu_changepass::on_updateButton_clicked()
{
    QString new_pass = ui->password_lineEdit->text();

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
    query.exec("select Spassword from student where Sname = '"+username_now+"'");
    if(new_pass.compare("")==0){
        QMessageBox::information(this,tr("提示"),tr("请输入密码！"));
    }
    else{
        if(query.next()){
            QString pass = query.value(0).toString();
            if(pass.compare(new_pass)==0){
                QMessageBox::information(this,tr("提示"),tr("请输入不同的密码！"));
            }
            else{
                QString sql = QString("update student set Spassword = '%1' where Sname = '%2'").arg(new_pass).arg(username_now);
                QSqlQuery query;
                bool sc = query.exec(sql);
                if(sc)  QMessageBox::information(this,tr("提示"),tr("更改成功！"));
                else    QMessageBox::information(this,tr("提示"),tr("更改失败！"));
            }
        }
        else qDebug()<<"unknown error";
    }
}


void stu_changepass::on_backButton_clicked()
{
    this->hide();
    student *s = new student;
    s->show();
}
