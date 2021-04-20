#ifndef USERMANAGEMENT_H
#define USERMANAGEMENT_H

#include <QDialog>
#include "createuser.h"
#include "finduser.h"
// #include "updateuser.h"
#include "deleteuser.h"

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

    void on_pushButton_findUser_clicked();

    void on_pushButton_deleteUser_clicked();

private:
    Ui::UserManagement *ui;
    CreateUser *createUser;
    FindUser *findUser;
    // UpdateUser *updateUser;
    DeleteUser *deleteUser;
};

#endif // USERMANAGEMENT_H
