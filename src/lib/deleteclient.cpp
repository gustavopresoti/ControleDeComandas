#include "include/deleteclient.h"
#include "ui_deleteclient.h"
#include <QMessageBox>

DeleteClient::DeleteClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteClient)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_clients");

    if(query.exec()) {
        int cont = 0;

        ui->tableWidget_clientDeleteFindShow->setColumnCount(5);

        while(query.next()) {
            ui->tableWidget_clientDeleteFindShow->insertRow(cont);

            ui->tableWidget_clientDeleteFindShow->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_clientDeleteFindShow->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_clientDeleteFindShow->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget_clientDeleteFindShow->setItem(cont, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget_clientDeleteFindShow->setItem(cont, 4, new QTableWidgetItem(query.value(4).toString()));

            ui->tableWidget_clientDeleteFindShow->setRowHeight(cont, 20);

            cont++;
        }

        ui->tableWidget_clientDeleteFindShow->setSelectionBehavior(QAbstractItemView::SelectRows);
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de clientes.");
    }
}

DeleteClient::~DeleteClient()
{
    delete ui;
}

void DeleteClient::on_pushButton_clientDeleteCancel_clicked()
{
    this->close();
}

void DeleteClient::on_pushButton_clientDelete_clicked()
{
    int linha = ui->tableWidget_clientDeleteFindShow->currentRow();
    int id = ui->tableWidget_clientDeleteFindShow->item(linha, 0)->text().toInt();

    QSqlQuery query;
    query.prepare("delete from tb_clients where id_client="+QString::number(id));

    if(query.exec()) {
        ui->tableWidget_clientDeleteFindShow->removeRow(linha);
        QMessageBox::information(this, "Remover Cliente", "Cliente removido com sucesso!");
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao remover na tabela de clientes.");
    }
}
