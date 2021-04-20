#ifndef FINDCLIENT_H
#define FINDCLIENT_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class FindClient;
}

class FindClient : public QDialog
{
    Q_OBJECT

public:
    explicit FindClient(QWidget *parent = nullptr);
    ~FindClient();

private slots:
    void on_pushButton_clientFind_clicked();

private:
    Ui::FindClient *ui;
};

#endif // FINDCLIENT_H
