#include "abonnementform.h"
#include "ui_abonnementform.h"
#include "adminform.h"
#include "clientform.h"
abonnementForm::abonnementForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::abonnementForm){
    ui->setupUi(this);
}

abonnementForm::~abonnementForm(){
    delete ui;
}

void abonnementForm::on_backBotton_clicked(){
    AdminForm * adm = new AdminForm();
    clientForm *clF = new clientForm();
    this->close();
    clF->show();
}

/*void abonnementForm::on_buyMonth_clicked(){
    QString name = ui->name->text();
    QString surname = ui->surname->text();
    QSqlQuery query;
    int id = query.exec("SELECT id FROM CLIETNS WHERE name = "+name+" AND surname = "+surname+";");

    query.exec("UPDATE ABONNEMENT SET finish_time=value1"
               "WHERE client_id ="+id+";");
}

void abonnementForm::on_buyYear_clicked(){
    QString name = ui->name->text();
    QString surname = ui->surname->text();
    QSqlQuery query;
    int id = query.exec("SELECT id FROM CLIETNS WHERE name = "+name+" AND surname = "+surname+";");

    query.exec("UPDATE ABONNEMENT SET finish_time=value1"
               "WHERE client_id ="+id+";");
}*/
