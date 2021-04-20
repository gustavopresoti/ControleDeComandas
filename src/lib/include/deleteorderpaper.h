#ifndef DELETEORDERPAPER_H
#define DELETEORDERPAPER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class DeleteOrderPaper;
}

class DeleteOrderPaper : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteOrderPaper(QWidget *parent = nullptr);
    ~DeleteOrderPaper();

private slots:
    void on_pushButton_orderPaperDeleteCancel_clicked();

    void on_pushButton_orderPaperDelete_clicked();

private:
    Ui::DeleteOrderPaper *ui;
};

#endif // DELETEORDERPAPER_H
