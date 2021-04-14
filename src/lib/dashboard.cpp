#include "include/dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent, QString user_email, bool isAdmin) :
    QDialog(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    ui->lineEdit_loggedAsDashboard->setText(user_email);

    if(!isAdmin) {
        ui->pushButton_itemManagement->setEnabled(false);
        ui->pushButton_clientManagement->setEnabled(false);
        ui->pushButton_userManagement->setEnabled(false);
    }
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::on_pushButton_systemExit_clicked()
{
    this->close();
}

void Dashboard::on_pushButton_userManagement_clicked()
{
    QString activeUser = ui->lineEdit_loggedAsDashboard->text();

    userManagement = new UserManagement(this, activeUser);

    userManagement->setModal(true);

    userManagement->exec();
}

void Dashboard::on_pushButton_orderPaperManagement_clicked()
{
    QString activeUser = ui->lineEdit_loggedAsDashboard->text();

    orderPaperManagement = new OrderPaperManagement(this, activeUser);

    orderPaperManagement->setModal(true);

    orderPaperManagement->exec();
}

void Dashboard::on_pushButton_clientManagement_clicked()
{
    QString activeUser = ui->lineEdit_loggedAsDashboard->text();

    clientManagement = new ClientManagement(this, activeUser);

    clientManagement->setModal(true);

    clientManagement->exec();
}
