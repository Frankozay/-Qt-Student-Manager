#include "all_stucourses.h"
#include "globle.h"
#include "stu_coursequery.h"
#include "mainwindow.h"
#include "ui_all_stucourses.h"


all_stucourses::all_stucourses(QWidget *parent) : QWidget(parent),
    ui(new Ui::all_stucourses)
{
    ui->setupUi(this);
    setWindowTitle(designer);
    for(int i=0;i<list_course.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        QStringList rowdata = list_course[i].toStringList();
        for(int j=0;j<rowdata.size();j++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row,j,item);
        }
    }
}

all_stucourses::~all_stucourses()
{
    delete ui;
}



void all_stucourses::on_backButton_clicked()
{
    this->hide();
    list_course.clear();
    ui->tableWidget->clear();
    stu_coursequery *sc = new stu_coursequery;
    sc->show();
}
