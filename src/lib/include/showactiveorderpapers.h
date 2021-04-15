#ifndef SHOWACTIVEORDERPAPERS_H
#define SHOWACTIVEORDERPAPERS_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class ShowActiveOrderPapers;
}

class ShowActiveOrderPapers : public QDialog
{
    Q_OBJECT

public:
    explicit ShowActiveOrderPapers(QWidget *parent = nullptr);
    ~ShowActiveOrderPapers();

private:
    Ui::ShowActiveOrderPapers *ui;
};

#endif // SHOWACTIVEORDERPAPERS_H
