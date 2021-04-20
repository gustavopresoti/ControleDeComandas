#include "include/deleteitem.h"
#include "ui_deleteitem.h"
#include <QMessageBox>

DeleteItem::DeleteItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteItem)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_items");

    if(query.exec()) {
        int cont = 0;

        ui->tableWidget_itemDeleteFindShow->setColumnCount(5);

        while(query.next()) {
            ui->tableWidget_itemDeleteFindShow->insertRow(cont);

            ui->tableWidget_itemDeleteFindShow->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_itemDeleteFindShow->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_itemDeleteFindShow->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget_itemDeleteFindShow->setItem(cont, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget_itemDeleteFindShow->setItem(cont, 4, new QTableWidgetItem(query.value(4).toString()));

            ui->tableWidget_itemDeleteFindShow->setRowHeight(cont, 20);

            cont++;
        }

        ui->tableWidget_itemDeleteFindShow->setSelectionBehavior(QAbstractItemView::SelectRows);
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de itens/produtos.");
    }
}

DeleteItem::~DeleteItem()
{
    delete ui;
}

void DeleteItem::on_pushButton_itemDeleteCancel_clicked()
{
    this->close();
}

void DeleteItem::on_pushButton_itemDelete_clicked()
{
    int linha = ui->tableWidget_itemDeleteFindShow->currentRow();
    int id = ui->tableWidget_itemDeleteFindShow->item(linha, 0)->text().toInt();

    QSqlQuery query;
    query.prepare("delete from tb_items where id_item="+QString::number(id));

    if(query.exec()) {
        ui->tableWidget_itemDeleteFindShow->removeRow(linha);
        QMessageBox::information(this, "Remover Item/Produto", "Item/Produto removido com sucesso!");
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao remover na tabela de itens/produtos.");
    }
}
