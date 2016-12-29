#include "addclient.h"
#include "ui_addclient.h"
#include "string.h"
#include "cstdlib"
#include <ctype.h>
#include <QMessageBox>

AddClient::AddClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);
    db = new DataBase();
    db->connectToDataBase();
}

AddClient::~AddClient(){
    delete ui;
}

void AddClient:: addPerson(QString name, QString surname,QString phone, QString birthday,
                           QString login, QString password, QString finish,int type){
    QSqlQuery query;
    int client_id;

    if(db->isUnique(login)){

        query.exec("INSERT INTO CLIETNS (name,surname,phone,birthday)"
                       "VALUES ('"+name+"','"+surname+"','"+phone+"','"+birthday+"');");

        client_id = getMaxId();
        qDebug()<< client_id;

        if(client_id != -1){
            qDebug()<< client_id;
            query.exec("INSERT INTO ABONNEMENT (login,password,client_id,type,finish_time)"
                          "VALUES ('"+login+"','"+password+"',"+ QString::number(client_id) +","+QString::number(type)+",'"+finish+"');");
        }
    }
    else QMessageBox::warning(this,tr("Error"),tr("Sorry, client with this login already exist, try again"));
    db->closeDataBase();
}


int AddClient:: getMaxId(){
    QSqlQuery query;

    if(query.exec("SELECT MAX(id) FROM CLIETNS")){
        if(query.next())
            qDebug() << query.value(0);
            return query.value(0).toInt();
    }

    return -1;
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

bool AddClient:: check_phone(){
    for(int i =0 ; i < ui->phone->text().length(); i++){
        if(!isdigit(ui->phone->text()[i].toLatin1())){
            QMessageBox::warning(this,tr("Error"),tr("Incorrect phone! Please, try again"));
            return false;
        }
    }
    return true;
}

bool AddClient:: check_name(){
    for(int i =0 ; i < ui->name->text().length(); i++){
            if(!isalpha(ui->name->text()[i].toLatin1())){
                QMessageBox::warning(this,tr("Error"),tr("Incorrect name! Please, try again"));
                return false;
            }
            else if((ui->name->text().length() == 0) || (ui->name->text().length() > 25)){
                QMessageBox::warning(this,tr("Error"),tr("Incorrect name! Please, try again"));
                return false;
            }
        }
    return true;
}

bool AddClient:: check_finishTime(){
    char st_finish[25];
    strcpy(st_finish,ui->finish_time->text().toStdString().c_str());
    int year, month, day;
    int finish_scanned = sscanf(st_finish, "%4d-%2d-%2d", &year, &month, &day);
    if(finish_scanned != 3){
        QMessageBox::warning(this,tr("Error"),tr("Incorrect finish_time! Please, try again"));
        return false;
     }
    return true;
}

bool AddClient:: check_date(){
    char st_date[25];
    strcpy(st_date, ui->birthday->text().toStdString().c_str());
    int year, month, day;
    int date_scanned = sscanf(st_date, "%4d-%2d-%2d", &year, &month, &day);
    if(date_scanned != 3){
        QMessageBox::warning(this,tr("Error"),tr("Incorrect birthday! Please, try again"));
        return false;
    }
    return true;
}

bool AddClient:: check_surname(){
    for(int i =0 ; i < ui->surname->text().length(); i++){
                if(!isalpha(ui->surname->text()[i].toLatin1())){
                    QMessageBox::warning(this,tr("Error"),tr("Incorrect surname! Please, try again"));
                    return false;
                }
                else if((ui->surname->text().length() == 0) || (ui->surname->text().length() > 25)){
                    QMessageBox::warning(this,tr("Error"),tr("Incorrect surname! Please, try again"));
                    return false;
                }
     }
        return true;

}

bool AddClient:: check_login(){
    if((ui->login->text().length() == 0) || (ui->login->text().length() > 25)){
        QMessageBox::warning(this,tr("Error"),tr("Incorrect login! Please, try again"));
        return false;
    }
    return true;
}

bool AddClient:: check_password(){
    if((ui->password->text().length() == 0) || (ui->password->text().length() > 25)){
        QMessageBox::warning(this,tr("Error"),tr("Incorrect password! Please, try again"));
        return false;
    }
    return true;
}

void AddClient::on_ok_clicked(){
    if(check_password()&&check_login()&&check_surname()&&check_name()&&check_phone()&&check_date()&&check_finishTime()){
        addPerson(ui->name->text(),ui->surname->text(),ui->phone->text(),
                  ui->birthday->text(),ui->login->text(),ui->password->text(),
                  ui->finish_time->text(),getType());
    }
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


void AddClient::on_back_clicked(){
    this->close();
}
