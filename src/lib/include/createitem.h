#ifndef CREATEITEM_H
#define CREATEITEM_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class CreateItem;
}

class CreateItem : public QDialog
{
    Q_OBJECT

public:
    explicit CreateItem(QWidget *parent = nullptr);
    ~CreateItem();

private slots:
    void on_pushButton_itemCreateCancel_clicked();

    void on_pushButton_itemCreate_clicked();

private:
    Ui::CreateItem *ui;
};

#endif // CREATEITEM_H
