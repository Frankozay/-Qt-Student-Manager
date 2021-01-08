#include "user_stupass.h"
#include "user_manage.h"
#include "mainwindow.h"
#include "globle.h"
#include <QtDebug>
#include <QMessageBox>
#include "ui_user_stupass.h"
#include "allpassword.h"

user_stupass::user_stupass(QWidget *parent) : QWidget(parent),
    ui(new Ui::user_stupass)
{
   ui->setupUi(this);
   setWindowTitle(designer);
}

user_stupass::~user_stupass()
{
    delete ui;
}



void user_stupass::on_searchButton_clicked()
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
    query.exec("select Spassword from student where Sno = '"+sno+"'");
    if(query.next()){
        QString password = query.value(0).toString();
        ui->password_lineEdit->setText(password);
    }
    else{
        QMessageBox::information(this,tr("提示"),tr("不存在该学号！"));
    }
}


void user_stupass::on_updateButton_clicked()
{
    QString sno=ui->sno_lineEdit->text();
    QString password = ui->password_lineEdit->text();

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
    query.exec("select Spassword from student where Sno = '"+sno+"'");
    if(query.next()){
        QString password_t = query.value(0).toString();
        if(password_t.compare(password)==0){
            QMessageBox::information(this,tr("提示"),tr("请输入不同密码！"));
        }
        else{
            QSqlQuery query;
            QString sql;
            sql = QString("update student set Spassword = '%1' where Sno = '%2'").arg(password).arg(sno);
            query.exec(sql);
            if(query.next()){
                QMessageBox::information(this,tr("提示"),tr("修改成功！"));
            }

            else    qDebug()<<"error";
        }
    }
    else{
        QMessageBox::information(this,tr("提示"),tr("不存在该学号！"));
    }
}

void user_stupass::on_backButton_clicked()
{
    this->hide();
    user_manage *um = new user_manage;
    um->show();
}


void user_stupass::on_allpasswordButton_clicked()
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
    query.exec("select Sno,Spassword "
               "from student"
               );
    while(query.next()){
        QStringList q;
        q.clear();
        QString sno = query.value(0).toString();
        QString password = query.value(1).toString();
        q<<sno<<password;
        list_all_password.append(q);
    }
    for(int i=0;i<list_all_password.size();i++){
        qDebug()<<list_all_password[i];
    }

    this->hide();
    allpassword *a =new allpassword;
    a->show();
}
