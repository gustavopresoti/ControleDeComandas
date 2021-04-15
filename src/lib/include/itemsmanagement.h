#ifndef ITEMSMANAGEMENT_H
#define ITEMSMANAGEMENT_H

#include <QDialog>
#include "createitem.h"

namespace Ui {
class ItemsManagement;
}

class ItemsManagement : public QDialog
{
    Q_OBJECT

public:
    explicit ItemsManagement(QWidget *parent = nullptr, QString user_email="");
    ~ItemsManagement();

private slots:
    void on_pushButton_backToDashboard_clicked();

    void on_pushButton_createItem_clicked();

private:
    Ui::ItemsManagement *ui;
    CreateItem *createItem;
};

#endif // ITEMSMANAGEMENT_H
