#include "include/clientmanagement.h"
#include "ui_clientmanagement.h"

ClientManagement::ClientManagement(QWidget *parent, QString user_email) :
    QDialog(parent),
    ui(new Ui::ClientManagement)
{
    ui->setupUi(this);

    ui->lineEdit_loggedAsUser->setText(user_email);
}

ClientManagement::~ClientManagement()
{
    delete ui;
}

void ClientManagement::on_pushButton_backToDashboard_clicked()
{
    this->close();
}

void ClientManagement::on_pushButton_createClient_clicked()
{
    createClient = new CreateClient(this);

    createClient->setModal(true);

    createClient->exec();
}
