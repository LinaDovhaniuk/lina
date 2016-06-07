#ifndef ABONNEMENTFORM_H
#define ABONNEMENTFORM_H

#include <QMainWindow>

namespace Ui {
class abonnementForm;
}

class abonnementForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit abonnementForm(QWidget *parent = 0);
    ~abonnementForm();

private:
    Ui::abonnementForm *ui;
};

#endif // ABONNEMENTFORM_H
