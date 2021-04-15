#include "include/showactiveorderpapers.h"
#include "ui_showactiveorderpapers.h"
#include <QMessageBox>

ShowActiveOrderPapers::ShowActiveOrderPapers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowActiveOrderPapers)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_ordersPaper where status_orderPaper='Aberta'");

    if(query.exec()) {
        int cont = 0;

        ui->tableWidget_showActiveOrderPapers->setColumnCount(5);

        while(query.next()) {
            ui->tableWidget_showActiveOrderPapers->insertRow(cont);

            ui->tableWidget_showActiveOrderPapers->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_showActiveOrderPapers->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_showActiveOrderPapers->setItem(cont, 2, new QTableWidgetItem(query.value(3).toString()));
            ui->tableWidget_showActiveOrderPapers->setItem(cont, 3, new QTableWidgetItem(query.value(4).toString()));
            ui->tableWidget_showActiveOrderPapers->setItem(cont, 4, new QTableWidgetItem(query.value(7).toString()));

            ui->tableWidget_showActiveOrderPapers->setRowHeight(cont, 20);

            cont++;
        }
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de usuários.");
    }
}

ShowActiveOrderPapers::~ShowActiveOrderPapers()
{
    delete ui;
}
