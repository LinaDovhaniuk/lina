#ifndef ABONNEMENTFORM_H
#define ABONNEMENTFORM_H

#include <QMainWindow>
#include "addclient.h"

namespace Ui {
class abonnementForm;
}

class abonnementForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit abonnementForm(QWidget *parent = 0);
    ~abonnementForm();

private slots:
    void on_backBotton_clicked();

    void on_buyMonth_clicked();

    void on_buyYear_clicked();
    void getInfo();

private:
    Ui::abonnementForm *ui;
    DataBase * db;
};

#endif // ABONNEMENTFORM_H
