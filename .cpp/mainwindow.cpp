#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>
#include<globle.h>
#include "manager.h"
#include "student.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Login_password->setEchoMode(QLineEdit::Password);
    ui->userButton->setChecked(true);
    setWindowTitle(designer);
    if(ui->userButton->isChecked())
        ui->tips->setText("Tips：初始密码为学号！");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoginButton_clicked()
{
    QString username = ui->Login_username->text();
    QString password = ui->Login_password->text();
    qDebug()<<"用户名:"<<username<<"密码:"<<password;

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

    if(ui->adminButton->isChecked()){
        QSqlQuery query(db);
        query.exec("select username,pass_word from admin");
        bool T1 = false;
        while(query.next()){
            QString user = query.value(0).toString();
            QString pass = query.value(1).toString();
            qDebug() << user << pass;
            if(username.compare(user)==0 && password.compare(pass)==0){
                password_now = password;
                username_now = username;
                T1=true;
                this->hide();
                m = new manager;
                m->show();
            }
        }
        if(T1 == false)
            QMessageBox::information(this,"提示","用户名或密码错误！");
    }

    if(ui->userButton->isChecked()){
        QSqlQuery query(db);
        query.exec("select Sno,Sname,Spassword from student");
        bool T1 = false;
        while(query.next()){
            QString user = query.value(0).toString();
            QString pass = query.value(2).toString();
            qDebug() << user << pass;
            if(username.compare(user)==0 && password.compare(pass)==0){
                password_now = password;
                username_now = query.value(1).toString();
                T1=true;
                this->hide();
                s = new student;
                s->show();
            }
        }
        if(T1 == false)
            QMessageBox::information(this,"提示","用户名或密码错误！");
    }

}



void MainWindow::on_userButton_clicked()
{
    ui->tips->setText("Tips：初始密码为学号！");
}



void MainWindow::on_adminButton_clicked()
{
    ui->tips->clear();
}

void MainWindow::on_RemitButton_clicked()
{
    ui->Login_username->clear();
    ui->Login_password->clear();
}
