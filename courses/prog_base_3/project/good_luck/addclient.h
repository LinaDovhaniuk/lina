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
                               QString login, QString password, QString finish,int type);
    int getType();
    int getMaxId();
private slots:
    void on_ok_clicked();
    void on_clientBox_clicked();
    void on_coachBox_clicked();
    void on_adminBox_clicked();
    void on_back_clicked();
    bool check_phone();
    bool check_name();
    bool check_finishTime();
    bool check_date();
    bool check_surname();
    bool check_login();
    bool check_password();

private:
    Ui::AddClient *ui;
    DataBase * db;
};

#endif // ADDCLIENT_H
