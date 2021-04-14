#include "include/createorderpaperitem.h"
#include "ui_createorderpaperitem.h"

CreateOrderPaperItem::CreateOrderPaperItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateOrderPaperItem)
{
    ui->setupUi(this);
}

CreateOrderPaperItem::~CreateOrderPaperItem()
{
    delete ui;
}

void CreateOrderPaperItem::on_pushButton_orderPaperItemCreateCancel_clicked()
{
    this->close();
}

void CreateOrderPaperItem::on_pushButton_orderPaperItemCreate_clicked()
{

}
