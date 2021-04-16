#ifndef SHOWORDERPAPERS_H
#define SHOWORDERPAPERS_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class ShowOrderPapers;
}

class ShowOrderPapers : public QDialog
{
    Q_OBJECT

public:
    explicit ShowOrderPapers(QWidget *parent = nullptr);
    ~ShowOrderPapers();

private slots:
    void on_pushButton_searchPeriodOrderPapers_clicked();

private:
    Ui::ShowOrderPapers *ui;
};

#endif // SHOWORDERPAPERS_H
