#include "include/createclient.h"
#include "ui_createclient.h"
#include <QMessageBox>

CreateClient::CreateClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateClient)
{
    ui->setupUi(this);

    ui->dateEdit_clientBirthDate->setDate(QDate::currentDate());
}

CreateClient::~CreateClient()
{
    delete ui;
}

void CreateClient::on_pushButton_clientCreateCancel_clicked()
{
    this->close();
}

void CreateClient::on_pushButton_clientCreate_clicked()
{
    QString clientName = ui->lineEdit_clientName->text();
    QString clientEmail = ui->lineEdit_clientEmail->text();
    QString clientBirthDate = ui->dateEdit_clientBirthDate->text();
    QString clientCPF = ui->lineEdit_clientCPF->text();

    if(clientName == "" || clientEmail == "") {
        QMessageBox::warning(this, "Criar Cliente", "Todos os campos marcados com (*) devem ser preenchidos!");
        return;
    }

    QSqlQuery query;
    query.prepare("insert into tb_clients (name_client, email_client, birthDate_client, cpf_client) values"
                  "('"+clientName+"','"+clientEmail+"','"+clientBirthDate+"','"+clientCPF+"')");

    if(query.exec()) {
        QMessageBox::information(this, "Criar Cliente", "Cliente cadastrado com sucesso!");
        ui->lineEdit_clientName->clear();
        ui->lineEdit_clientEmail->clear();
        ui->dateEdit_clientBirthDate->setDate(QDate::currentDate());
        ui->lineEdit_clientCPF->clear();
        ui->lineEdit_clientName->setFocus();
    }else {
        qDebug()<<"Erro ao criar cliente. Tente novamente!";
    }
}
