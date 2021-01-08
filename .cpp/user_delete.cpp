#include "user_delete.h"
#include "user_manage.h"
#include "mainwindow.h"
#include "ui_user_delete.h"
#include "globle.h"
#include <QMessageBox>
#include <QtDebug>

user_delete::user_delete(QWidget *parent) : QWidget(parent),
    ui(new Ui::user_delete)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    setWindowTitle(designer);
}

user_delete::~user_delete()
{
    delete ui;
}

void user_delete::on_deletePushButton_clicked()
{
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();
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
    query.exec("select username from admin");
    bool T = false;
    bool admin = false;
    if(username.compare("admin")==0){
        T=true;
        admin=true;
    }
    if(!admin){
        while(query.next()){
            QString username1 = query.value(0).toString();
            if(username1.compare(username)==0){
                QString sql;
                sql = QString("delete from admin "
                              " where username = '%1'").arg(username);
                QSqlQuery query;
                bool sc = query.exec(sql);
                if(sc){
                    QMessageBox::information(this,tr("提示"),tr("删除成功"));
                    T=true;
                }
                else{
                    QMessageBox::information(this,tr("提示"),tr("删除失败"));
                    T=true;
                }
            }
        }
    }
    else{
        QMessageBox::information(this ,tr("提示") , tr("无法删除初始用户"));
    }
    if(T == false){
        QMessageBox::information(this ,tr("提示") , tr("该用户名不存在"));
    }
}


void user_delete::on_backPushButton_clicked()
{
    this->hide();
    user_manage *um = new user_manage;
    um->show();
}
