#include "include/createuser.h"
#include "ui_createuser.h"
#include <QMessageBox>

CreateUser::CreateUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateUser)
{
    ui->setupUi(this);
}

CreateUser::~CreateUser()
{
    delete ui;
}

void CreateUser::on_pushButton_userCreateCancel_clicked()
{
    this->close();
}

void CreateUser::on_pushButton_userCreate_clicked()
{
    QString userName = ui->lineEdit_userName->text();
    QString userEmail = ui->lineEdit_userEmail->text();
    QString userPassword = ui->lineEdit_userPassword->text();
    QString userType = ui->comboBox_userType->currentText();

    if(userName == "" || userEmail == "" || userPassword == "") {
        QMessageBox::warning(this, "Criar Usuário", "Todos os campos devem ser preenchidos!");
        return;
    }

    if(userType == "Administrador") {
        userType = "1";
    }else {
        userType = "0";
    }

    QSqlQuery query;
    query.prepare("insert into tb_users (name_user, email_user, password_user, isAdmin_user) values"
                  "('"+userName+"','"+userEmail+"','"+userPassword+"','"+userType+"')");

    if(query.exec()) {
        QMessageBox::information(this, "Criar Usuário", "Usuário cadastrado com sucesso!");
        ui->lineEdit_userName->clear();
        ui->lineEdit_userEmail->clear();
        ui->lineEdit_userPassword->clear();
        ui->comboBox_userType->setCurrentIndex(0);
        ui->lineEdit_userName->setFocus();
    }else {
        qDebug()<<"Erro ao criar usuário. Tente novamente!";
    }
}
