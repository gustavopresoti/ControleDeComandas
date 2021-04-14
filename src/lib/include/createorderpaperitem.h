#ifndef CREATEORDERPAPERITEM_H
#define CREATEORDERPAPERITEM_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class CreateOrderPaperItem;
}

class CreateOrderPaperItem : public QDialog
{
    Q_OBJECT

public:
    explicit CreateOrderPaperItem(QWidget *parent = nullptr);
    ~CreateOrderPaperItem();

private slots:
    void on_pushButton_orderPaperItemCreateCancel_clicked();

    void on_pushButton_orderPaperItemCreate_clicked();

private:
    Ui::CreateOrderPaperItem *ui;
};

#endif // CREATEORDERPAPERITEM_H
