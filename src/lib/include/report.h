#ifndef REPORT_H
#define REPORT_H

#include <QDialog>
#include "showusers.h"
#include "showitems.h"

namespace Ui {
class Report;
}

class Report : public QDialog
{
    Q_OBJECT

public:
    explicit Report(QWidget *parent = nullptr, QString user_email="");
    ~Report();

private slots:
    void on_pushButton_backToDashboard_clicked();

    void on_pushButton_showUsers_clicked();

    void on_pushButton_showItems_clicked();

private:
    Ui::Report *ui;
    ShowUsers *showUsers;
    ShowItems *showItems;
};

#endif // REPORT_H
