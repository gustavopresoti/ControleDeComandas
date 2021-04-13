#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

QSqlDatabase dataBase = QSqlDatabase::addDatabase("QSQLITE");

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);

    dataBase.setDatabaseName("C:/Users/gusta/Desktop/UFOP/20.1/BCC322/TrabalhoGrupo/SistemaDeControleDeComandas/ControleComandas/db/db_cdc.db");

    if(!dataBase.open()) {
        QMessageBox::warning(this, "Login", "Erro de conexão ao banco de dados. Tente novamente!");
    }
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_pushButton_Login_clicked()
{
    QString email = ui->lineEdit_Email->text();
    QString password = ui->lineEdit_Password->text();

    if(!dataBase.isOpen()) {
        qDebug()<<"Banco de dados não está aberto";
        return;
    }

    QSqlQuery query;
    if(query.exec("select * from tb_users where email='"+email+"' and password='"+password+"'")){
        int cont = 0;
        bool isAdmin = false;

        while(query.next()) {
            isAdmin = query.value(4).toBool();
            cont++;
        }

        if(cont > 0) {
            this->close();

            dashboard = new Dashboard(this, email, isAdmin);

            dashboard->show();
        }else {
            QMessageBox::warning(this, "Login", "Credenciais inválidas!");

            ui->lineEdit_Email->clear();
            ui->lineEdit_Password->clear();
            ui->lineEdit_Email->setFocus();
        }
    }

}
