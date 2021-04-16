#include "include/showtotalrevenues.h"
#include "ui_showtotalrevenues.h"
#include <QMessageBox>

ShowTotalRevenues::ShowTotalRevenues(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowTotalRevenues)
{
    ui->setupUi(this);

    ui->dateTimeEdit_toDate->setDateTime(QDateTime::currentDateTime());

    ui->tableWidget_showTotalRevenues->setColumnCount(1);
    ui->tableWidget_showTotalRevenues->insertRow(0);
    ui->tableWidget_showTotalRevenues->setRowHeight(0, 20);
}

ShowTotalRevenues::~ShowTotalRevenues()
{
    delete ui;
}

void ShowTotalRevenues::on_pushButton_searchPeriodTotalRevenues_clicked()
{
    QSqlQuery query;
    query.prepare("select * from tb_ordersPaper");

    if(query.exec()) {
        float soma = 0.0;

        while(query.next()) {
            if((query.value(3).toString() >= ui->dateTimeEdit_fromDate->text()) && (query.value(3).toString() <= ui->dateTimeEdit_toDate->text())) {
                soma += query.value(7).toFloat();

                ui->tableWidget_showTotalRevenues->setItem(0, 0, new QTableWidgetItem(QString::number(soma)));
            }else {
                ui->tableWidget_showTotalRevenues->setItem(0, 0, new QTableWidgetItem(QString::number(soma)));
            }
        }
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de comandas.");
    }
}
