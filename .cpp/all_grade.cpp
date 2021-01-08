#include "all_grade.h"
#include "globle.h"
#include "stu_scorequery.h"
#include "mainwindow.h"
#include "ui_all_grade.h"


all_grade::all_grade(QWidget *parent) : QWidget(parent),
    ui(new Ui::all_grade)
{
    ui->setupUi(this);
    setWindowTitle(designer);
    for(int i=0;i<list_grade.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        QStringList rowdata = list_grade[i].toStringList();
        for(int j=0;j<rowdata.size();j++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row,j,item);
        }
    }
}

all_grade::~all_grade()
{
    delete ui;
}



void all_grade::on_backButton_clicked()
{
    this->hide();
    list_grade.clear();
    ui->tableWidget->clear();
    stu_scorequery *ss = new stu_scorequery;
    ss->show();
}
