#ifndef FINDORDERPAPER_H
#define FINDORDERPAPER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class FindOrderPaper;
}

class FindOrderPaper : public QDialog
{
    Q_OBJECT

public:
    explicit FindOrderPaper(QWidget *parent = nullptr);
    ~FindOrderPaper();

private slots:
    void on_pushButton_orderPaperFindFind_clicked();

private:
    Ui::FindOrderPaper *ui;
};

#endif // FINDORDERPAPER_H
