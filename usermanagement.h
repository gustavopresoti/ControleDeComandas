#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QDialog>

namespace Ui {
class UserManagement;
}

class UserManagement : public QDialog
{
    Q_OBJECT

public:
    explicit UserManagement(QWidget *parent = nullptr, QString user_email="");
    ~UserManagement();

private slots:
    void on_pushButton_backToDashboard_clicked();

    void on_pushButton_createUser_clicked();

private:
    Ui::UserManagement *ui;
};

#endif // USERMANAGEMENT_H
