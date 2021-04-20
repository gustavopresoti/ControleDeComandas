#include "include/deleteuser.h"
#include "ui_deleteuser.h"
#include <QMessageBox>

DeleteUser::DeleteUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteUser)
{
    ui->setupUi(this);

    QSqlQuery query;
    query.prepare("select * from tb_users");

    if(query.exec()) {
        int cont = 0;

        ui->tableWidget_userDeleteFindShow->setColumnCount(3);

        while(query.next()) {
            ui->tableWidget_userDeleteFindShow->insertRow(cont);

            ui->tableWidget_userDeleteFindShow->setItem(cont, 0, new QTableWidgetItem(query.value(0).toString()));
            ui->tableWidget_userDeleteFindShow->setItem(cont, 1, new QTableWidgetItem(query.value(1).toString()));
            ui->tableWidget_userDeleteFindShow->setItem(cont, 2, new QTableWidgetItem(query.value(2).toString()));

            ui->tableWidget_userDeleteFindShow->setRowHeight(cont, 20);

            cont++;
        }

        ui->tableWidget_userDeleteFindShow->setSelectionBehavior(QAbstractItemView::SelectRows);
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao pesquisar na tabela de usuários.");
    }
}

DeleteUser::~DeleteUser()
{
    delete ui;
}

void DeleteUser::on_pushButton_userDeleteCancel_clicked()
{
    this->close();
}

void DeleteUser::on_pushButton_userDelete_clicked()
{
    int linha = ui->tableWidget_userDeleteFindShow->currentRow();
    int id = ui->tableWidget_userDeleteFindShow->item(linha, 0)->text().toInt();

    QSqlQuery query;
    query.prepare("delete from tb_users where id_user="+QString::number(id));

    if(query.exec()) {
        ui->tableWidget_userDeleteFindShow->removeRow(linha);
        QMessageBox::information(this, "Remover Usuário", "Usuário removido com sucesso!");
    }else {
        QMessageBox::warning(this, "ERRO", "Erro ao remover na tabela de usuários.");
    }
}
