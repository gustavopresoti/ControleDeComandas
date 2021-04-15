#ifndef SHOWITEMS_H
#define SHOWITEMS_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class ShowItems;
}

class ShowItems : public QDialog
{
    Q_OBJECT

public:
    explicit ShowItems(QWidget *parent = nullptr);
    ~ShowItems();

private:
    Ui::ShowItems *ui;
};

#endif // SHOWITEMS_H
