#include "usermanagement.h"
#include "ui_usermanagement.h"

UserManagement::UserManagement(QWidget *parent, QString user_email) :
    QDialog(parent),
    ui(new Ui::UserManagement)
{
    ui->setupUi(this);

    ui->lineEdit_loggedAsUser->setText(user_email);
}

UserManagement::~UserManagement()
{
    delete ui;
}

void UserManagement::on_pushButton_backToDashboard_clicked()
{
    this->close();
}

void UserManagement::on_pushButton_createUser_clicked()
{

}
