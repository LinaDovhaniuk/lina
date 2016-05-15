#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}

/* Методы для подключения к базе данных
 * */
void DataBase::connectToDataBase()
{
    /* Перед подключением к базе данных производим проверку на её существование.
     * В зависимости от результата производим открытие базы данных или её восстановление
     * */
    if(!QFile("D:/project/Gym_newVersion/LoginForm/db.db").exists()){
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

/* Методы восстановления базы данных
 * */
bool DataBase::restoreDataBase()
{
    if(this->openDataBase()){
        if(!this->createClientTable()){
            if(!this->createTrainingTable()){
                if(!this->createInventoryTable()){
                    if(!this->createAbonnementTable()){
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

/* Метод для открытия базы данных
 * */
bool DataBase::openDataBase()
{
    /* База данных открывается по заданному пути
     * и имени базы данных, если она существует
     * */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName("D:/project/Gym_newVersion/LoginForm/db.db");
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

/* Методы закрытия базы данных
 * */
void DataBase::closeDataBase()
{
    db.close();
}

/* Метод для создания таблицы устройств в базе данных
 * */
bool DataBase::createClientTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
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
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
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

bool DataBase::createInventoryTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
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

bool DataBase::createAbonnementTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
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

    if (query.exec("SELECT PASSWORD FROM CLIENTS WHERE LOGIN = '"+login+"';")){
        if (query.next()){
            if(query.value(0)== password){
                return true;
            }
        }
    }
    return false;
}

