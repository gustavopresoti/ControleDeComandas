#ifndef ORDERPAPERMANAGEMENT_H
#define ORDERPAPERMANAGEMENT_H

#include <QDialog>
#include "createorderpaper.h"

namespace Ui {
class OrderPaperManagement;
}

class OrderPaperManagement : public QDialog
{
    Q_OBJECT

public:
    explicit OrderPaperManagement(QWidget *parent = nullptr, QString user_email="");
    ~OrderPaperManagement();

private slots:
    void on_pushButton_backToDashboard_clicked();

    void on_pushButton_createOrderPaper_clicked();

private:
    Ui::OrderPaperManagement *ui;
    CreateOrderPaper *createOrderPaper;
};

#endif // ORDERPAPERMANAGEMENT_H