#ifndef ORDERPAPERMANAGEMENT_H
#define ORDERPAPERMANAGEMENT_H

#include <QDialog>
#include "createorderpaper.h"
#include "createorderpaperitem.h"
#include "findorderpaper.h"
#include "deleteorderpaper.h"
#include "showactiveorderpapers.h"

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

    void on_pushButton_findOrderPaper_clicked();

    void on_pushButton_showActiveOrderPapers_clicked();

    void on_pushButton_deleteOrderPaper_clicked();

private:
    Ui::OrderPaperManagement *ui;
    CreateOrderPaper *createOrderPaper;
    FindOrderPaper *findOrderPaper;
    DeleteOrderPaper *deleteOrderPaper;
    ShowActiveOrderPapers *showActiveOrderPapers;
};

#endif // ORDERPAPERMANAGEMENT_H
