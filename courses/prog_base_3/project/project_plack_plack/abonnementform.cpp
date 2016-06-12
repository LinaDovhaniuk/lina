#include "abonnementform.h"
#include "ui_abonnementform.h"
#include "adminform.h"
#include "clientform.h"
#include "connectedclient.h"
#include "database.h"
#include <QString>

abonnementForm::abonnementForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::abonnementForm){
    ui->setupUi(this);
    db = new DataBase();

    getInfo();
}

abonnementForm::~abonnementForm(){
    delete ui;
}

void abonnementForm:: getInfo(){
    db->connectToDataBase();
    QSqlQuery * query = new QSqlQuery(db->getDB());
    QString id = QString::number(us->user_getId());

    if(query->exec("SELECT finish_time FROM ABONNEMENT WHERE client_id = "+ id +";")){
        if(query->next()){
            QString finish = query->value(0).toString();
            ui->finish->setText(finish);
        }

    }

    db->closeDataBase();
}

void abonnementForm::on_backBotton_clicked(){
    clientForm *clF = new clientForm();
    this->close();
    clF->show();
}

void abonnementForm::on_buyMonth_clicked(){

    QString id = QString::number(us->user_getId());

    db->connectToDataBase();
    QSqlQuery  query;// = new QSqlQuery(db->getDB());
    query.exec("SELECT finish_time FROM ABONNEMENT WHERE client_id ="+ id +";");

    if(query.next()){
        query.exec("UPDATE ABONNEMENT SET finish_time=DATE(finish_time, '+1 months') WHERE client_id  = "+ id +";");

    }

    db->closeDataBase();
    on_backBotton_clicked();
}

void abonnementForm::on_buyYear_clicked(){
    QString id = QString::number(us->user_getId());

    db->connectToDataBase();
    QSqlQuery  query;// = new QSqlQuery(db->getDB());
    query.exec("SELECT finish_time FROM ABONNEMENT WHERE client_id ="+ id +";");

    if(query.next()){
        query.exec("UPDATE ABONNEMENT SET finish_time=DATE(finish_time, '+1 years') WHERE client_id  = "+ id +";");

    }

    db->closeDataBase();
    on_backBotton_clicked();
}
