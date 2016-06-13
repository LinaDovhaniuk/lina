#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

/* Директивы имен таблицы, полей таблицы и базы данных */
#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "DataBase.db"

class DataBase : public QObject
{
    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();

    void connectToDataBase();
    bool authorization(QString login, QString password);
    void closeDataBase();
    bool isUnique(QString login);
    QSqlDatabase getDB();

private:

    QSqlDatabase    db;


private:
    void getUser(QString id, QString login);
    bool openDataBase();
    bool restoreDataBase();
    bool createClientTable();
    bool createTrainingTable();
    bool createInventoryTable();
    bool createAbonnementTable();
};




#endif // DATABASE_H
