#include "user_manage.h"
#include "ui_user_manage.h"
#include "manager.h"
#include "globle.h"
#include "user_insert.h"
#include "user_delete.h"
#include "user_changepassword.h"
#include "user_stupass.h"

user_manage::user_manage(QWidget *parent) : QWidget(parent),ui(new Ui::user_manage)
{
    ui->setupUi(this);
    setWindowTitle(designer);
}

user_manage::~user_manage()
{
    delete ui;
}

void user_manage::on_createPushButton_clicked()
{
    this->hide();
    user_insert *in = new user_insert;
    in->show();
}

void user_manage::on_backPushButton_clicked()
{
    this->hide();
    manager *m = new manager;
    m->show();
}

void user_manage::on_deletePushButton_clicked()
{
    this->hide();
    user_delete *ud = new user_delete;
    ud->show();
}

void user_manage::on_changePushButton_clicked()
{
    this->hide();
    user_changepassword *uc = new user_changepassword;
    uc->show();
}

void user_manage::on_stu_passwordButton_clicked()
{
    this->hide();
    user_stupass *us = new user_stupass;
    us->show();
}
