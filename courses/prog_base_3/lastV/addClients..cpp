#include "adminabonnement.h"
#include "ui_adminabonnement.h"

AdminAbonnement::AdminAbonnement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminAbonnement)
{
    ui->setupUi(this);
}

AdminAbonnement::~AdminAbonnement()
{
    delete ui;
}
