#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "mainwindow.h"

#include "database.h"

namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();

private slots:
    void on_pushButton_clicked();


    void on_passwordLineEdit_returnPressed();

private:
    Ui::Login *ui;
    DataBase *db;
};

#endif // LOGIN_H
