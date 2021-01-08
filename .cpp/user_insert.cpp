#include "user_insert.h"
#include "ui_user_insert.h"
#include <QMessageBox>
#include "globle.h"
#include <QtDebug>
#include "user_manage.h"
#include "mainwindow.h"

user_insert::user_insert(QWidget *parent) : QWidget(parent),
    ui(new Ui::user_insert)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    setWindowTitle(designer);
}

user_insert::~user_insert(){
    delete ui;
}

void user_insert::on_addPushButton_clicked()
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
    bool T = true;
    while(query.next()){
        QString username1 = query.value(0).toString();
        if(username1.compare(username)==0){
            QMessageBox::information(this,tr("提示"), tr("用户名已存在！"));
            T=false;
        }
    }
    if(T==true){
        QString sql;
        sql = QString("insert into admin(username,pass_word)"
                      " values('%1','%2' )").arg(username).arg(password);
        bool sc = query.exec(sql);
        if(sc){
            QMessageBox::information(this ,tr("提示") , tr("添加成功!"));
        }
        else
        {
          QMessageBox::information(this ,tr("提示") , tr("添加失败!"));
        }
    }

}

void user_insert::on_backPushButton_clicked()
{
    this->hide();
    user_manage *um = new user_manage;
    um->show();
}
