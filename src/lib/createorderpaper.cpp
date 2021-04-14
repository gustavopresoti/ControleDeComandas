#include "include/createorderpaper.h"
#include "ui_createorderpaper.h"
#include <QMessageBox>

CreateOrderPaper::CreateOrderPaper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateOrderPaper)
{
    ui->setupUi(this);

    ui->dateTimeEdit_orderPaperTimestamp->setDateTime(QDateTime::currentDateTime());
}

CreateOrderPaper::~CreateOrderPaper()
{
    delete ui;
}

void CreateOrderPaper::on_pushButton_orderPaperCreateCancel_clicked()
{
    this->close();
}

void CreateOrderPaper::on_pushButton_orderPaperCreate_clicked()
{
    QString clientName = ui->lineEdit_orderPaperClientName->text();
    QString clientAge = ui->lineEdit_orderPaperClientAge->text();
    QString timeStamp = ui->dateTimeEdit_orderPaperTimestamp->text();
    QString orderItems = ui->plainTextEdit_orderPaperItems->toPlainText();
    QString additionalValue = ui->lineEdit_orderPaperAdditionalValue->text();
    QString discountValue = ui->lineEdit_orderPaperDiscountValue->text();
    QString totalValue = ui->lineEdit_orderPaperTotalValue->text();

    if(clientName == "" || timeStamp == "" || orderItems == "" || totalValue == "") {
        QMessageBox::warning(this, "Criar Comanda", "Todos os campos marcados com um (*) devem ser preenchidos!");
        return;
    }

    QSqlQuery query;
    query.prepare("insert into tb_ordersPaper (clientName_orderPaper, clientAge_orderPaper, timestamp_orderPaper, orders_orderPaper, additionalValue_orderPaper, discountValue_orderPaper, totalValue_orderPaper, status_orderPaper) values"
                  "('"+clientName+"','"+clientAge+"','"+timeStamp+"','"+orderItems+"','"+additionalValue+"','"+discountValue+"','"+totalValue+"', 'Aberta')");

    if(query.exec()) {
        QMessageBox::information(this, "Criar Comanda", "Comanda cadastrada com sucesso!");
        ui->lineEdit_orderPaperClientName->clear();
        ui->lineEdit_orderPaperClientAge->clear();
        ui->dateTimeEdit_orderPaperTimestamp->setDateTime(QDateTime::currentDateTime());
        ui->plainTextEdit_orderPaperItems->clear();
        ui->lineEdit_orderPaperAdditionalValue->clear();
        ui->lineEdit_orderPaperDiscountValue->clear();
        ui->lineEdit_orderPaperTotalValue->clear();
        ui->lineEdit_orderPaperClientName->setFocus();
    }else {
        qDebug()<<"Erro ao criar comanda. Tente novamente!";
    }
}

void CreateOrderPaper::on_pushButton_orderPaperNewItems_clicked()
{

}
