#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include "usermanagement.h"
#include "orderpapermanagement.h"
#include "clientmanagement.h"

namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr, QString user_email="", bool isAdmin=false);
    ~Dashboard();

private slots:
    void on_pushButton_systemExit_clicked();

    void on_pushButton_userManagement_clicked();

    void on_pushButton_orderPaperManagement_clicked();

    void on_pushButton_clientManagement_clicked();

private:
    Ui::Dashboard *ui;
    UserManagement *userManagement;
    OrderPaperManagement *orderPaperManagement;
    ClientManagement *clientManagement;
};

#endif // DASHBOARD_H
