#ifndef CREATEUSER_H
#define CREATEUSER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class CreateUser;
}

class CreateUser : public QDialog
{
    Q_OBJECT

public:
    explicit CreateUser(QWidget *parent = nullptr);
    ~CreateUser();

private slots:
    void on_pushButton_userCreateCancel_clicked();

    void on_pushButton_userCreate_clicked();

private:
    Ui::CreateUser *ui;
};

#endif // CREATEUSER_H
