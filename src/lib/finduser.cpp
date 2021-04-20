#include "include/finduser.h"
#include "ui_finduser.h"
#include <QMessageBox>

FindUser::FindUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindUser)
{
    ui->setupUi(this);
}

FindUser::~FindUser()
{
    delete ui;
}

void FindUser::on_pushButton_userFind_clicked()
{
    ui->tableWidget_userFindShow->setRowCount(0);

    QSqlQuery query;
    query.prepare("select * from tb_users");

    if(query.exec()) {
        int cont = 0;

        ui->tableWidget_userFindShow->setColumnCount(3);

        while(query.next()) {
            if(query.value(2).toString() == ui->lineEdit_userFindEmail->text()) {
                ui->tableWidget_userFindShow->insertRow(cont);

                ui->tableWidget_userFindShow->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
                ui->tableWidget_userFindShow->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
                ui->tableWidget_userFindShow->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));

                ui->tableWidget_userFindShow->setRowHeight(cont, 20);

                cont++;
            }
        }

        if(cont == 0) {
            QMessageBox::warning(this, "Buscar Usuário", "Usuário não encontrado!");
        }
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de usuários.");
    }
}
