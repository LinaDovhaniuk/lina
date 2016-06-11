#include "addclient.h"
#include "ui_addclient.h"

AddClient::AddClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);
}

AddClient::~AddClient(){
    delete ui;
}

void AddClient:: addPerson(QString name, QString surname,QString phone, QString birthday,
                           QString login, QString password, QString finish){
    QSqlQuery query;
    int client_id = 0;

    query.exec("INSERT INTO CLIETNS (name,surname,phone,birthday)"
                   "VALUES ('"+name+"','"+surname+"',"+phone+","+birthday+");");
    if(query.exec("SELECT MAX(id) FROM CLIETNS")){
        if (query.next()){
            client_id == query.value(0);
            query.exec("INSERT INTO ABONNEMENT (login,password,client_id,type,finish_time)"
                          "VALUES ('"+login+"','"+password+"',"+client_id+",'"+getType()+"',"+finish+");");
        }
    }

}


int AddClient::getType(){
    if(ui->clientBox->isChecked()){
        return 0;
    } else if(ui->coachBox->isChecked()){
        return 1;
    } else {
        return 2;
    }
}


void AddClient::on_ok_clicked(){
    addPerson(ui->name->text(),ui->surname->text(),ui->phone->text(),
              ui->birthday->text(),ui->login->text(),ui->password->text(),
              ui->finish_time->text());
    this->close();
}


void AddClient::on_clientBox_clicked(){
    ui->adminBox->setChecked(false);
    ui->coachBox ->setChecked(false);
    ui->clientBox->setChecked(true);
}

void AddClient::on_coachBox_clicked(){
    ui->adminBox->setChecked(false);
    ui->coachBox ->setChecked(true);
    ui->clientBox->setChecked(false);
}

void AddClient::on_adminBox_clicked(){
    ui->adminBox->setChecked(true);
    ui->coachBox ->setChecked(false);
    ui->clientBox->setChecked(false);
}
