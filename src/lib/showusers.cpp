#include "include/showusers.h"
#include "ui_showusers.h"
#include <QMessageBox>

ShowUsers::ShowUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowUsers)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_users");

    if(query.exec()) {
        int cont = 0;

        ui->tableWidget_showUsers->setColumnCount(3);

        while(query.next()) {
            ui->tableWidget_showUsers->insertRow(cont);

            ui->tableWidget_showUsers->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_showUsers->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_showUsers->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));

            ui->tableWidget_showUsers->setRowHeight(cont, 20);

            cont++;
        }
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de usuários.");
    }
}

ShowUsers::~ShowUsers()
{
    delete ui;
}
