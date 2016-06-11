#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QMainWindow>
#include "database.h"

namespace Ui {
class AddClient;
}

class AddClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddClient(QWidget *parent = 0);
    ~AddClient();

private:
    void addPerson(QString name, QString surname,QString phone, QString birthday,
                               QString login, QString password, QString finish);
    int getType();

private slots:
    void on_ok_clicked();
    void on_clientBox_clicked();

    void on_coachBox_clicked();

    void on_adminBox_clicked();

private:
    Ui::AddClient *ui;
};

#endif // ADDCLIENT_H
