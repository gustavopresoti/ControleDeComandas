#ifndef CREATECLIENT_H
#define CREATECLIENT_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class CreateClient;
}

class CreateClient : public QDialog
{
    Q_OBJECT

public:
    explicit CreateClient(QWidget *parent = nullptr);
    ~CreateClient();

private slots:
    void on_pushButton_clientCreateCancel_clicked();

    void on_pushButton_clientCreate_clicked();

private:
    Ui::CreateClient *ui;
};

#endif // CREATECLIENT_H
