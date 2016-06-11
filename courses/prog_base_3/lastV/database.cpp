#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

void DataBase::connectToDataBase(){

    if(!QFile("D:/Download/lina-master/courses/prog_base_3/lastV/db.sqlite").exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool DataBase::restoreDataBase(){
    if(this->openDataBase()){
        if(this->createClientTable()){
                if(this->createInventoryTable()){
                    if(this->createAbonnementTable()){
                        if(this->createTrainingTable()){
                        return false;
                    }
                }
            }
        } else {
            return true;
        }

    } else {
        qDebug() << "Не удалось восстановить базу данных";
        return false;
    }
    return false;
}

bool DataBase::openDataBase(){

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("D:/Download/lina-master/courses/prog_base_3/lastV/db.sqlite");
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase::closeDataBase(){
    db.close();
}


bool DataBase::createClientTable(){

    QSqlQuery query;
    if(!query.exec( "CREATE TABLE CLIETNS ("
                        "id integer PRIMARY KEY,"
                        "name varchar(16) NOT NULL,"
                        "surname varchar(16) NOT NULL,"
                        "birthday numeric NOT NULL,"
                        "phone integer NOT NULL"
                    ");"
                    )){
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::createTrainingTable(){

    QSqlQuery query;
    if(!query.exec( "CREATE TABLE TRAINING ("
                        "id integer PRIMARY KEY NOT NULL,"
                        "coach_id integer NOT NULL,"
                        "client_id integer NOT NULL,"
                        "isPrivate boolean NOT NULL,"
                        "start_time numeric NOT NULL,"
                        "FOREIGN KEY(coach_id) REFERENCES CLIENTS(id),"
                        "FOREIGN KEY(client_id) REFERENCES CLIENTS(id)"
                    ");"

                    )){
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::createInventoryTable(){

    QSqlQuery query;
    if(!query.exec( "CREATE TABLE INVENTORY ("
                        "id integer PRIMARY KEY NOT NULL,"
                        "name varchar(16) NOT NULL,"
                        "price integer NOT NULL"
                    ");"
                    )){
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase::createAbonnementTable(){

    QSqlQuery query;
    if(!query.exec( "CREATE TABLE ABONNEMENT ("
                        "login varchar(16) PRIMARY KEY NOT NULL,"
                        "password varchar(16) NOT NULL,"
                        "client_id integer NOT NULL,"
                        "type integer NOT NULL,"
                        "finish_time date NOT NULL,"
                        "FOREIGN KEY(client_id) REFERENCES CLIENTS(id)"
                    ");"
                    )){
        return false;
    } else {
        return true;
    }
    return false;
}

bool DataBase:: authorization(QString login, QString password){
    QSqlQuery query;

    if (query.exec("SELECT PASSWORD FROM ABONNEMENT WHERE LOGIN = '"+login+"';")){
        if (query.next()){
            if(query.value(0)== password){
                return true;
            }
        }
    }
    return false;
}

