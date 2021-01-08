#include "student.h"
#include "mainwindow.h"
#include "globle.h"
#include "ui_student.h"
#include "stu_changepass.h"
#include "stu_inforquery.h"
#include "stu_scorequery.h"
#include "stu_coursequery.h"

student::student(QWidget *parent) : QWidget(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);
    QLabel *lab = ui->username;
    lab->setStyleSheet("color:#ff6600;");
    lab->setText("欢迎"+username_now);
    setWindowTitle(designer);
}

student::~student()
{
    delete ui;
}

void student::on_backButton_clicked()
{
    this->hide();
    MainWindow *m = new MainWindow;
    m->show();
}

void student::on_passwordButton_clicked()
{
    this->hide();
    stu_changepass *sc = new stu_changepass;
    sc->show();
}

void student::on_stu_queryButton_clicked()
{
    this->hide();
    stu_inforquery *si = new stu_inforquery;
    si->show();
}

void student::on_score_queryButton_clicked()
{
    this->hide();
    stu_scorequery *ss = new stu_scorequery;
    ss->show();
}

void student::on_course_queryButton_clicked()
{
    this->hide();;
    stu_coursequery *sc = new stu_coursequery;
    sc->show();
}
