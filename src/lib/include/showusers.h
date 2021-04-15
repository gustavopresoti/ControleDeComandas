#ifndef SHOWUSERS_H
#define SHOWUSERS_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class ShowUsers;
}

class ShowUsers : public QDialog
{
    Q_OBJECT

public:
    explicit ShowUsers(QWidget *parent = nullptr);
    ~ShowUsers();

private:
    Ui::ShowUsers *ui;
};

#endif // SHOWUSERS_H
