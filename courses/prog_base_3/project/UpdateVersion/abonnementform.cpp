#include "abonnementform.h"
#include "ui_abonnementform.h"

abonnementForm::abonnementForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::abonnementForm)
{
    ui->setupUi(this);
}

abonnementForm::~abonnementForm()
{
    delete ui;
}
