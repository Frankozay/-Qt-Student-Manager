#include "allpassword.h"
#include "globle.h"
#include "user_stupass.h"
#include "ui_allpassword.h"
#include "mainwindow.h"

allpassword::allpassword(QWidget *parent) : QWidget(parent),
    ui(new Ui::allpassword)
{
    ui->setupUi(this);
    setWindowTitle(designer);
    for(int i=0;i<list_all_password.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        QStringList rowdata = list_all_password[i].toStringList();
        for(int j=0;j<rowdata.size();j++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row,j,item);
        }
    }
}

allpassword::~allpassword()
{
    delete ui;
}



void allpassword::on_backButton_clicked()
{
    this->hide();
    list_all_password.clear();
    ui->tableWidget->clear();
    user_stupass *us = new user_stupass;
    us->show();
}
