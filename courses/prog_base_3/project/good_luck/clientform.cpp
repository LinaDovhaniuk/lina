#include "clientform.h"
#include "ui_clientform.h"
#include "abonnementform.h"
#include "login.h"
#include "connectedclient.h"

clientForm::clientForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientForm){
        ui->setupUi(this);

        getInfo();
    }

clientForm::~clientForm(){
    delete ui;
}

void clientForm::on_buyButton_clicked(){
    abonnementForm * abonForm = new abonnementForm();
    this->close();
    abonForm->show();
}

void clientForm:: getInfo(){
    ui->name->setText(us->user_getName());
    ui->surname->setText(us->user_getSurname());
    ui->birthday->setText(us->user_getBirthday());
    ui->phone->setText(us->user_getPhone());
}

void clientForm::on_clientExitButton_clicked(){
    Login * log = new Login();
    this->close();
    log->show();
}
