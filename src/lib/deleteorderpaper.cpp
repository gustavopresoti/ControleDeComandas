#include "include/deleteorderpaper.h"
#include "ui_deleteorderpaper.h"
#include <QMessageBox>

DeleteOrderPaper::DeleteOrderPaper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteOrderPaper)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_ordersPaper");

    if(query.exec()) {
        int cont = 0;

        ui->tableWidget_orderPaperFindShow->setColumnCount(3);

        while(query.next()) {
            ui->tableWidget_orderPaperFindShow->insertRow(cont);

            ui->tableWidget_orderPaperFindShow->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_orderPaperFindShow->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_orderPaperFindShow->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget_orderPaperFindShow->setItem(cont, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget_orderPaperFindShow->setItem(cont, 4, new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget_orderPaperFindShow->setItem(cont, 5, new QTableWidgetItem(query.value(5).toString()));
            ui->tableWidget_orderPaperFindShow->setItem(cont, 6, new QTableWidgetItem(query.value(6).toString()));
            ui->tableWidget_orderPaperFindShow->setItem(cont, 7, new QTableWidgetItem(query.value(7).toString()));
            ui->tableWidget_orderPaperFindShow->setItem(cont, 8, new QTableWidgetItem(query.value(8).toString()));

            ui->tableWidget_orderPaperFindShow->setRowHeight(cont, 20);

            cont++;
        }

        ui->tableWidget_orderPaperFindShow->setSelectionBehavior(QAbstractItemView::SelectRows);
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de comandas.");
    }
}

DeleteOrderPaper::~DeleteOrderPaper()
{
    delete ui;
}

void DeleteOrderPaper::on_pushButton_orderPaperDeleteCancel_clicked()
{
    this->close();
}

void DeleteOrderPaper::on_pushButton_orderPaperDelete_clicked()
{
    int linha = ui->tableWidget_orderPaperFindShow->currentRow();
    int id = ui->tableWidget_orderPaperFindShow->item(linha, 0)->text().toInt();

    QSqlQuery query;
    query.prepare("delete from tb_ordersPaper where id_orderPaper="+QString::number(id));

    if(query.exec()) {
        ui->tableWidget_orderPaperFindShow->removeRow(linha);
        QMessageBox::information(this, "Remover Comanda", "Comanda removida com sucesso!");
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao remover na tabela de comandas.");
    }
}
