#include "manager.h"
#include "ui_manager.h"
#include "globle.h"
#include "mainwindow.h"
#include "user_manage.h"
#include "stuinfor_manage.h"
#include "course_manage.h"
#include "sc_manage.h"

manager::manager(QWidget *parent) : QWidget(parent),ui(new Ui::manager)
{
    ui->setupUi(this);
    QLabel *lab = ui->username;
    lab->setStyleSheet("color:#ff6600;");
    lab->setText("欢迎"+username_now);
    setWindowTitle(designer);
}

manager::~manager()

{
    delete ui;
}


void manager::on_backButton_clicked()
{
    this->hide();
    MainWindow *m = new MainWindow;
    m->show();
}


void manager::on_user_manageButton_clicked()
{
    this->hide();
    user_manage *um = new user_manage;
    um->show();
}

void manager::on_stu_manageButton_clicked()
{
    this->hide();
    stuinfor_manage *sm = new stuinfor_manage;
    sm->show();
}

void manager::on_course_manageButton_clicked()
{
    this->hide();
    course_manage *cm = new course_manage;
    cm->show();
}

void manager::on_score_manageButton_clicked()
{
    this->hide();
    sc_manage *sm = new sc_manage;
    sm->show();
}
