#ifndef SHOWTOTALREVENUES_H
#define SHOWTOTALREVENUES_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class ShowTotalRevenues;
}

class ShowTotalRevenues : public QDialog
{
    Q_OBJECT

public:
    explicit ShowTotalRevenues(QWidget *parent = nullptr);
    ~ShowTotalRevenues();

private slots:
    void on_pushButton_searchPeriodTotalRevenues_clicked();

private:
    Ui::ShowTotalRevenues *ui;
};

#endif // SHOWTOTALREVENUES_H
