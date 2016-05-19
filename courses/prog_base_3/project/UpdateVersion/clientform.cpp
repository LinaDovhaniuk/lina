#include "clientform.h"
#include "ui_clientform.h"

clientForm::clientForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientForm)
{
    ui->setupUi(this);
}

clientForm::~clientForm()
{
    delete ui;
}
