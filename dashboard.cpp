#include "dashboard.h"
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

    userManagement->show();
}
