#include "include/findorderpaper.h"
#include "ui_findorderpaper.h"
#include <QMessageBox>

FindOrderPaper::FindOrderPaper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindOrderPaper)
{
    ui->setupUi(this);
}

FindOrderPaper::~FindOrderPaper()
{
    delete ui;
}

void FindOrderPaper::on_pushButton_orderPaperFindFind_clicked()
{
    ui->tableWidget_orderPaperFindShow->setRowCount(0);

    QSqlQuery query;
    query.prepare("select * from tb_ordersPaper");

    if(query.exec()) {
        int cont = 0;

        ui->tableWidget_orderPaperFindShow->setColumnCount(9);

        while(query.next()) {
            if(query.value(1).toString() == ui->lineEdit_orderPaperFindClientName->text()) {
                ui->tableWidget_orderPaperFindShow->insertRow(cont);

                ui->tableWidget_orderPaperFindShow->setItem(cont, 0, new QTableWidgetItem(query.value(8).toString()));
                ui->tableWidget_orderPaperFindShow->setItem(cont, 1, new QTableWidgetItem(query.value(0).toString()));
                ui->tableWidget_orderPaperFindShow->setItem(cont, 2, new QTableWidgetItem(query.value(1).toString()));
                ui->tableWidget_orderPaperFindShow->setItem(cont, 3, new QTableWidgetItem(query.value(2).toString()));
                ui->tableWidget_orderPaperFindShow->setItem(cont, 4, new QTableWidgetItem(query.value(3).toString()));
                ui->tableWidget_orderPaperFindShow->setItem(cont, 5, new QTableWidgetItem(query.value(4).toString()));
                ui->tableWidget_orderPaperFindShow->setItem(cont, 6, new QTableWidgetItem(query.value(5).toString()));
                ui->tableWidget_orderPaperFindShow->setItem(cont, 7, new QTableWidgetItem(query.value(6).toString()));
                ui->tableWidget_orderPaperFindShow->setItem(cont, 8, new QTableWidgetItem(query.value(7).toString()));

                cont++;
            }
        }

        if(cont == 0) {
            QMessageBox::warning(this, "Buscar Comanda", "Comanda não encontrada!");
        }

        ui->tableWidget_orderPaperFindShow->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
        ui->tableWidget_orderPaperFindShow->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de comandas.");
    }
}
