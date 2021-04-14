#ifndef CLIENTMANAGEMENT_H
#define CLIENTMANAGEMENT_H

#include <QDialog>
#include "createclient.h"

namespace Ui {
class ClientManagement;
}

class ClientManagement : public QDialog
{
    Q_OBJECT

public:
    explicit ClientManagement(QWidget *parent = nullptr, QString user_email="");
    ~ClientManagement();

private slots:
    void on_pushButton_backToDashboard_clicked();

    void on_pushButton_createClient_clicked();

private:
    Ui::ClientManagement *ui;
    CreateClient *createClient;
};

#endif // CLIENTMANAGEMENT_H
