#include "allstuinfor.h"
#include "ui_allstuinfor.h"
#include "globle.h"
#include "stuinfor_manage.h"

allstuinfor::allstuinfor(QWidget *parent) : QWidget(parent),
    ui(new Ui::allstuinfor)
{
    ui->setupUi(this);
    setWindowTitle(designer);
    for(int i=0;i<list_all_student.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        QStringList rowdata = list_all_student[i].toStringList();
        for(int j=0;j<rowdata.size();j++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row,j,item);
        }
    }
}

allstuinfor::~allstuinfor()
{
    delete ui;
}


void allstuinfor::on_backButton_clicked()
{
    this->hide();
    list_all_student.clear();
    ui->tableWidget->clear();
    stuinfor_manage *sm = new stuinfor_manage;
    sm->show();
}
