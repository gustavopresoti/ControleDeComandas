#ifndef FINDUSER_H
#define FINDUSER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class FindUser;
}

class FindUser : public QDialog
{
    Q_OBJECT

public:
    explicit FindUser(QWidget *parent = nullptr);
    ~FindUser();

private slots:
    void on_pushButton_userFind_clicked();

private:
    Ui::FindUser *ui;
};

#endif // FINDUSER_H
