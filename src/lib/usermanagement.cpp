#include "include/usermanagement.h"
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
    createUser = new CreateUser(this);

    createUser->setModal(true);

    createUser->exec();
}

void UserManagement::on_pushButton_findUser_clicked()
{
    findUser = new FindUser(this);

    findUser->setModal(true);

    findUser->exec();
}

void UserManagement::on_pushButton_deleteUser_clicked()
{
    deleteUser = new DeleteUser(this);

    deleteUser->setModal(true);

    deleteUser->exec();
}
