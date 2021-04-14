#ifndef CREATEORDERPAPER_H
#define CREATEORDERPAPER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class CreateOrderPaper;
}

class CreateOrderPaper : public QDialog
{
    Q_OBJECT

public:
    explicit CreateOrderPaper(QWidget *parent = nullptr);
    ~CreateOrderPaper();

private slots:
    void on_pushButton_orderPaperCreateCancel_clicked();

    void on_pushButton_orderPaperCreate_clicked();

    void on_pushButton_orderPaperNewItems_clicked();

private:
    Ui::CreateOrderPaper *ui;
};

#endif // CREATEORDERPAPER_H
