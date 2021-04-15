#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QDialog>
#include "itemsmanagement.h"
#include "usermanagement.h"
#include "orderpapermanagement.h"
#include "clientmanagement.h"
#include "report.h"

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

    void on_pushButton_report_clicked();

    void on_pushButton_itemManagement_clicked();

private:
    Ui::Dashboard *ui;
    ItemsManagement *itemsManagement;
    UserManagement *userManagement;
    OrderPaperManagement *orderPaperManagement;
    ClientManagement *clientManagement;
    Report *report;
};

#endif // DASHBOARD_H
