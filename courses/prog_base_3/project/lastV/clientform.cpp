#include "clientform.h"
#include "ui_clientform.h"
#include "abonnementform.h"
#include "login.h"

clientForm::clientForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::clientForm){
    ui->setupUi(this);

    }

clientForm::~clientForm(){
    delete ui;
}

void clientForm::on_buyButton_clicked(){
    abonnementForm * abonForm = new abonnementForm();
    this->close();
    abonForm->show();
}

/*void clientForm:: getInfo(){
    QSqlQuery query;
    Login * l = new Login();
    QString login = l->getLogin();

    int id = query.exec("SELECT client_id FROM ABONNEMENT WHERE login = '"+login+"';");
    QString name = query.exec("SELECT name FROM CLIETNS WHERE id = "+id+";");
    QString surname = query.exec("SELECT surname FROM CLIETNS WHERE id = "+id+";");
    QString phone = query.exec("SELECT phone FROM CLIETNS WHERE id = "+id+";");
    QString birthday = query.exec("SELECT birthday FROM CLIETNS WHERE id = "+id+";");

    ui->name->text() = name;
    ui->surname->text() = surname;
    ui->birthday->text() = birthday;
    ui->phone->text() = phone;

}*/

void clientForm::on_clientExitButton_clicked(){
    Login * log = new Login();
    this->close();
    log->show();
}
