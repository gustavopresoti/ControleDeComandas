#include "include/findclient.h"
#include "ui_findclient.h"
#include <QMessageBox>

FindClient::FindClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindClient)
{
    ui->setupUi(this);
}

FindClient::~FindClient()
{
    delete ui;
}

void FindClient::on_pushButton_clientFind_clicked()
{
    ui->tableWidget_clientFindShow->setRowCount(0);

    QSqlQuery query;
    query.prepare("select * from tb_clients");

    if(query.exec()) {
        int cont = 0;

        ui->tableWidget_clientFindShow->setColumnCount(5);

        while(query.next()) {
            if((query.value(1).toString() == ui->lineEdit_clientFindNameEmail->text()) || (query.value(2).toString() == ui->lineEdit_clientFindNameEmail->text())) {
                ui->tableWidget_clientFindShow->insertRow(cont);

                ui->tableWidget_clientFindShow->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
                ui->tableWidget_clientFindShow->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
                ui->tableWidget_clientFindShow->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
                ui->tableWidget_clientFindShow->setItem(cont, 3, new QTableWidgetItem(query.value(3).toString()));
                ui->tableWidget_clientFindShow->setItem(cont, 4, new QTableWidgetItem(query.value(4).toString()));

                cont++;
            }
        }

        if(cont == 0) {
            QMessageBox::warning(this, "Buscar Cliente", "Cliente não encontrado!");
        }

        ui->tableWidget_clientFindShow->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
        ui->tableWidget_clientFindShow->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de clientes.");
    }
}
