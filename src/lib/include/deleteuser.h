#ifndef DELETEUSER_H
#define DELETEUSER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class DeleteUser;
}

class DeleteUser : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteUser(QWidget *parent = nullptr);
    ~DeleteUser();

private slots:
    void on_pushButton_userDeleteCancel_clicked();

    void on_pushButton_userDelete_clicked();

private:
    Ui::DeleteUser *ui;
};

#endif // DELETEUSER_H
