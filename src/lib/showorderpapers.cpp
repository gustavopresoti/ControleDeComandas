#include "include/showorderpapers.h"
#include "ui_showorderpapers.h"
#include <QMessageBox>

ShowOrderPapers::ShowOrderPapers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowOrderPapers)
{
    ui->setupUi(this);

    ui->dateTimeEdit_toDate->setDateTime(QDateTime::currentDateTime());
}

ShowOrderPapers::~ShowOrderPapers()
{
    delete ui;
}

void ShowOrderPapers::on_pushButton_searchPeriodOrderPapers_clicked()
{
    ui->tableWidget_showOrderPapers->setRowCount(0);

    QSqlQuery query;
    query.prepare("select * from tb_ordersPaper");

    if(query.exec()) {
        int cont = 0;

        while(query.next()) {
            if((query.value(3).toString() >= ui->dateTimeEdit_fromDate->text()) && (query.value(3).toString() <= ui->dateTimeEdit_toDate->text())) {
                ui->tableWidget_showOrderPapers->insertRow(cont);

                ui->tableWidget_showOrderPapers->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
                ui->tableWidget_showOrderPapers->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
                ui->tableWidget_showOrderPapers->setItem(cont, 2, new QTableWidgetItem(query.value(3).toString()));
                ui->tableWidget_showOrderPapers->setItem(cont, 3, new QTableWidgetItem(query.value(4).toString()));
                ui->tableWidget_showOrderPapers->setItem(cont, 4, new QTableWidgetItem(query.value(7).toString()));

                ui->tableWidget_showOrderPapers->setRowHeight(cont, 20);

                cont++;
            }
        }
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de comandas.");
    }
}
