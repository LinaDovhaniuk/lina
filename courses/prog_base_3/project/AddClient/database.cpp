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
    if(!QFile("D:\project\SportClub\AddCoach\coachDB.db").exists()){
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
        if(!this->createDeviceTable()){
            return false;
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
    db.setDatabaseName("D:\project\SportClub\AddCoach\coachDB.db");
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
bool DataBase::createDeviceTable()
{
    /* В данном случае используется формирование сырого SQL-запроса
     * с последующим его выполнением.
     * */
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " COACH " ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                            SURNAME "VARCHAR(255)    NOT NULL,"
                            NAME    " VARCHAR(16)     NOT NULL,"
                            BIRTHDAY "VARCHAR(12)   NOT NULL"
                            PHONE    " INTEGER     NOT NULL"
                        " )"
                    )){
        qDebug() << "DataBase: error of create " << COACH;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}

/* Метод для вставки записи в таблицу устройств
 * */
bool DataBase::inserIntoDeviceTable(const QVariantList &data)
{
    /* Запрос SQL формируется из QVariantList,
     * в который передаются данные для вставки в таблицу.
     * */
    QSqlQuery query;
    /* В начале SQL запрос формируется с ключами,
     * которые потом связываются методом bindValue
     * для подстановки данных из QVariantList
     * */
    query.prepare("INSERT INTO " COACH "("
                          SURNAME ", "
                          NAME ", "
                          BIRTHDAY ", "
                          PHONE
                          " ) "
                  "VALUES (:SURNAME, :NAME, :BIRTHDAY, :PHONE )");
    query.bindValue(":SURNAME",    data[0].toString());
    query.bindValue(":NAME",          data[1].toString());
    query.bindValue(":BIRTHDAY",         data[2].toString());
    query.bindValue(":PHONE",         data[3].toString());
    // После чего выполняется запросом методом exec()
    if(!query.exec()){
        qDebug() << "error insert into " << COACH;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
    return false;
}


