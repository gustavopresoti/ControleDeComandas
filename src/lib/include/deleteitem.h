#ifndef DELETEITEM_H
#define DELETEITEM_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class DeleteItem;
}

class DeleteItem : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteItem(QWidget *parent = nullptr);
    ~DeleteItem();

private slots:
    void on_pushButton_itemDeleteCancel_clicked();

    void on_pushButton_itemDelete_clicked();

private:
    Ui::DeleteItem *ui;
};

#endif // DELETEITEM_H
