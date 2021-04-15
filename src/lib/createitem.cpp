#include "include/createitem.h"
#include "ui_createitem.h"
#include <QMessageBox>

CreateItem::CreateItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateItem)
{
    ui->setupUi(this);
}

CreateItem::~CreateItem()
{
    delete ui;
}

void CreateItem::on_pushButton_itemCreateCancel_clicked()
{
    this->close();
}

void CreateItem::on_pushButton_itemCreate_clicked()
{
    QString itemName = ui->lineEdit_itemName->text();
    QString itemDescription = ui->lineEdit_itemDescription->text();
    QString itemAmount = ui->lineEdit_itemAmount->text();
    QString itemValue = ui->lineEdit_itemValue->text();

    if(itemName == "" || itemDescription == "" || itemAmount == "" || itemValue == "") {
        QMessageBox::warning(this, "Criar Item/Produto", "Todos os campos devem ser preenchidos!");
        return;
    }

    QSqlQuery query;
    query.prepare("insert into tb_items (name_item, description_item, amount_item, value_item) values"
                  "('"+itemName+"','"+itemDescription+"','"+itemAmount+"','"+itemValue+"')");

    if(query.exec()) {
        QMessageBox::information(this, "Criar Item/Produto", "Item/Produto cadastrado com sucesso!");
        ui->lineEdit_itemName->clear();
        ui->lineEdit_itemDescription->clear();
        ui->lineEdit_itemAmount->clear();
        ui->lineEdit_itemValue->clear();
        ui->lineEdit_itemName->setFocus();
    }else {
        qDebug()<<"Erro ao criar item/produto. Tente novamente!";
    }
}
