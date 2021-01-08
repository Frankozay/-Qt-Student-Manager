#include "user_changepassword.h"
#include "ui_user_changepassword.h"
#include "user_manage.h"
#include "mainwindow.h"
#include "globle.h"
#include <QMessageBox>
#include <QtDebug>


user_changepassword::user_changepassword(QWidget *parent) : QWidget(parent),
    ui(new Ui::user_changepassword)
{
    ui->setupUi(this);
    ui->old_passwordLineEdit->setEchoMode(QLineEdit::Password);
    ui->new_passwordLineEdit->setEchoMode(QLineEdit::Password);
    setWindowTitle(designer);
}

user_changepassword::~user_changepassword()
{
    delete ui;
}




void user_changepassword::on_changePushButton_clicked()
{
    QString old_p = ui->old_passwordLineEdit->text();
    QString new_p = ui->new_passwordLineEdit->text();

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
    sql = QString("select pass_word from admin where username = '%0'").arg(username_now);
    query.exec(sql);
    query.next();
    if(old_p.compare(query.value(0).toString())==0){
        if(new_p == NULL){
            QMessageBox::information(this,tr("提示"),tr("密码不能为空！"));
        }
        else if(new_p.compare(old_p)==0){
            QMessageBox::information(this,tr("提示"),tr("新旧密码不能相同！"));
        }
        else{
            sql = QString("update admin "
                          "set pass_word = '%0' "
                          "where username = '%1'").arg(new_p).arg(username_now);
            QSqlQuery query;
            bool sc = query.exec(sql);
            if(sc){
                QMessageBox::information(this,tr("提示"),tr("修改成功！"));
            }
            else{
                QMessageBox::information(this,tr("提示"),tr("修改失败！"));
            }
        }
    }
    else{
        QMessageBox::information(this,tr("提示"),tr("密码错误,请再次确认旧密码！"));
    }
}


void user_changepassword::on_backPushButton_clicked()
{
    this->hide();
    user_manage *um = new user_manage;
    um->show();
}
