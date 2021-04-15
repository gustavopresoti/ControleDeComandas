#include "include/report.h"
#include "ui_report.h"

Report::Report(QWidget *parent, QString user_email) :
    QDialog(parent),
    ui(new Ui::Report)
{
    ui->setupUi(this);

    ui->lineEdit_loggedAsUser->setText(user_email);
}

Report::~Report()
{
    delete ui;
}

void Report::on_pushButton_backToDashboard_clicked()
{
    this->close();
}

void Report::on_pushButton_showUsers_clicked()
{
    showUsers = new ShowUsers(this);

    showUsers->setModal(true);

    showUsers->exec();
}

void Report::on_pushButton_showItems_clicked()
{
    showItems = new ShowItems(this);

    showItems->setModal(true);

    showItems->exec();
}
