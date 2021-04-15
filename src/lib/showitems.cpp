#include "include/showitems.h"
#include "ui_showitems.h"
#include <QMessageBox>

ShowItems::ShowItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowItems)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_items");

    if(query.exec()) {
        int cont = 0;

        ui->tableWidget_showItems->setColumnCount(5);

        while(query.next()) {
            ui->tableWidget_showItems->insertRow(cont);

            ui->tableWidget_showItems->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_showItems->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_showItems->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));
            ui->tableWidget_showItems->setItem(cont, 3, new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget_showItems->setItem(cont, 4, new QTableWidgetItem(query.value(4).toString()));

            ui->tableWidget_showItems->setRowHeight(cont, 20);

            cont++;
        }
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de itens/produtos.");
    }
}

ShowItems::~ShowItems()
{
    delete ui;
}
