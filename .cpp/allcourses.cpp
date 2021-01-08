#include "allcourses.h"
#include "ui_allcourses.h"
#include "globle.h"
#include "course_manage.h"

allcourses::allcourses(QWidget *parent) : QWidget(parent),
    ui(new Ui::allcourses)
{
    ui->setupUi(this);
    setWindowTitle(designer);
    for(int i=0;i<list_all_course.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        QStringList rowdata = list_all_course[i].toStringList();
        for(int j=0;j<rowdata.size();j++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row,j,item);
        }
    }
}

allcourses::~allcourses()
{
    delete ui;
}


void allcourses::on_backButton_clicked()
{
    this->hide();
    list_all_course.clear();
    ui->tableWidget->clear();
    course_manage *cm = new course_manage;
    cm->show();
}
