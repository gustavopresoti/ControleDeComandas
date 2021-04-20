#include "include/orderpapermanagement.h"
#include "ui_orderpapermanagement.h"

OrderPaperManagement::OrderPaperManagement(QWidget *parent, QString user_email) :
    QDialog(parent),
    ui(new Ui::OrderPaperManagement)
{
    ui->setupUi(this);

    ui->lineEdit_loggedAsUser->setText(user_email);
}

OrderPaperManagement::~OrderPaperManagement()
{
    delete ui;
}

void OrderPaperManagement::on_pushButton_backToDashboard_clicked()
{
    this->close();
}

void OrderPaperManagement::on_pushButton_createOrderPaper_clicked()
{
    createOrderPaper = new CreateOrderPaper(this);

    createOrderPaper->setModal(true);

    createOrderPaper->exec();
}

void OrderPaperManagement::on_pushButton_findOrderPaper_clicked()
{
    findOrderPaper = new FindOrderPaper(this);

    findOrderPaper->setModal(true);

    findOrderPaper->exec();
}

void OrderPaperManagement::on_pushButton_showActiveOrderPapers_clicked()
{
    showActiveOrderPapers = new ShowActiveOrderPapers(this);

    showActiveOrderPapers->setModal(true);

    showActiveOrderPapers->exec();
}

void OrderPaperManagement::on_pushButton_deleteOrderPaper_clicked()
{
    deleteOrderPaper = new DeleteOrderPaper(this);

    deleteOrderPaper->setModal(true);

    deleteOrderPaper->exec();
}
