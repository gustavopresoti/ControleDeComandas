#include "include/itemsmanagement.h"
#include "ui_itemsmanagement.h"

ItemsManagement::ItemsManagement(QWidget *parent, QString user_email) :
    QDialog(parent),
    ui(new Ui::ItemsManagement)
{
    ui->setupUi(this);

    ui->lineEdit_loggedAsUser->setText(user_email);
}

ItemsManagement::~ItemsManagement()
{
    delete ui;
}

void ItemsManagement::on_pushButton_backToDashboard_clicked()
{
    this->close();
}

void ItemsManagement::on_pushButton_createItem_clicked()
{
    createItem = new CreateItem(this);

    createItem->setModal(true);

    createItem->exec();
}

void ItemsManagement::on_pushButton_deleteItem_clicked()
{
    deleteItem = new DeleteItem(this);

    deleteItem->setModal(true);

    deleteItem->exec();
}
