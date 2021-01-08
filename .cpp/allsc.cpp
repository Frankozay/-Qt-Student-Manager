#include "allsc.h"
#include "ui_allsc.h"
#include "globle.h"
#include "sc_manage.h"

allsc::allsc(QWidget *parent) : QWidget(parent),
    ui(new Ui::allsc)
{
    ui->setupUi(this);
    setWindowTitle(designer);
    for(int i=0;i<list_all_sc.size();i++){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        QStringList rowdata = list_all_sc[i].toStringList();
        for(int j=0;j<rowdata.size();j++){
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(rowdata.at(j));
            ui->tableWidget->setItem(row,j,item);
        }
    }
}

allsc::~allsc()
{
    delete ui;
}

void allsc::on_backButton_clicked()
{
    this->hide();
    list_all_sc.clear();
    ui->tableWidget->clear();
    sc_manage *sm = new sc_manage;
    sm->show();
}
