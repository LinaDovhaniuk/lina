#include "adminform.h"
#include "ui_adminform.h"
#include "addclient.h"
#include "database.h"
#include "abonnementform.h"
#include "login.h"
#include "findform.h"

AdminForm::AdminForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminForm){
    ui->setupUi(this);


    db = new DataBase();



}

AdminForm::~AdminForm(){
    delete ui;
}

void AdminForm::on_addButton_clicked(){
    AddClient * addClient = new AddClient();
    addClient->show();
}

void AdminForm::on_ClientReviewButton_clicked(){

    QSqlQueryModel * model = new QSqlQueryModel();

    db->connectToDataBase();
    QSqlQuery * query = new QSqlQuery(db->getDB());

    query->prepare("SELECT login,name,surname,phone,birthday,finish_time FROM ABONNEMENT, CLIETNS WHERE ((ABONNEMENT.type == 0) AND (ABONNEMENT.client_id == CLIETNS.id));");

    query->exec();
    model->setQuery(*query);
    ui->adminTable->setModel(model);
    ui->adminTable->show();
}

void AdminForm::setupModel(const QString &tableName, const QStringList &headers){
    modelClients = new QSqlTableModel(this);
    modelClients->setTable(tableName);
    modelClients->select();

    for(int i = 0, j = 0; i < modelClients->columnCount(); i++, j++){
        modelClients->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
}

void AdminForm::slotUpdateModels(){
    modelClients->select();
}

void AdminForm::createUI(){
    ui->adminTable->setModel(modelClients);
    ui->adminTable->setColumnHidden(0, true);
    ui->adminTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->adminTable->setSelectionMode(QAbstractItemView::SingleSelection);

    ui->adminTable->resizeColumnsToContents();
    ui->adminTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->adminTable->horizontalHeader()->setStretchLastSection(true);

    connect(ui->adminTable, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditRecord(QModelIndex)));
}

void AdminForm::on_CoachReviewButton_clicked(){
    QSqlQueryModel * model = new QSqlQueryModel();

    db->connectToDataBase();
    QSqlQuery * query = new QSqlQuery(db->getDB());

    query->prepare("SELECT login,name,surname,phone,birthday,finish_time FROM ABONNEMENT, CLIETNS WHERE ((ABONNEMENT.type == 1) AND (ABONNEMENT.client_id == CLIETNS.id));");

    query->exec();
    model->setQuery(*query);
    ui->adminTable->setModel(model);
    ui->adminTable->show();
}

void AdminForm::on_InventReviewButton_clicked(){
    QSqlQueryModel * model = new QSqlQueryModel();

    db->connectToDataBase();
    QSqlQuery * query = new QSqlQuery(db->getDB());

    query->prepare("SELECT * FROM INVENTORY;");

    query->exec();
    model->setQuery(*query);
    ui->adminTable->setModel(model);
    ui->adminTable->show();
}

void AdminForm::on_TrainReviewButton_clicked(){
    QSqlQueryModel * model = new QSqlQueryModel();

    db->connectToDataBase();
    QSqlQuery * query = new QSqlQuery(db->getDB());

    query->prepare("SELECT * FROM TRAINING;");

    query->exec();
    model->setQuery(*query);
    ui->adminTable->setModel(model);
    ui->adminTable->show();
}


void AdminForm::on_AdminExitButton_clicked(){
    Login * log = new Login();
    this->close();
    log->show();
}


void AdminForm::on_findBotton_clicked(){
   QString findLog = ui->findLog->text();
   db->connectToDataBase();
   QSqlQuery* query = new QSqlQuery(db->getDB());


   qDebug() << "SELECT id FROM CLIETNS WHERE name = '"+ findLog +"';";
   query->exec("SELECT login,name,surname,birthday,phone,finish_time FROM CLIETNS,ABONNEMENT WHERE (login = '"+ findLog +"' AND client_id = id);");
   QSqlQueryModel * model = new QSqlQueryModel();

   query->exec();
   model->setQuery(*query);
   ui->adminTable->setModel(model);
   ui->adminTable->show();
   db->closeDataBase();
}

void AdminForm::on_pushButton_clicked(){
    QModelIndexList data = ui->adminTable->selectionModel()->selectedRows();
    QString findLog = data.value(0).data().toString();
    db->connectToDataBase();
    QSqlQuery* query = new QSqlQuery(db->getDB());

    query->exec("SELECT client_id FROM ABONNEMENT WHERE login =='"+ findLog +"';");
    int id = query->value(0).toInt();
    query->prepare("DELETE FROM ABONNEMENT WHERE login == '"+findLog+"';");
    query->exec();
    query->prepare("DELETE FROM CLIETNS WHERE id = "+ QString::number(id) +";");
    query->exec();
    ui->adminTable->show();
    db->closeDataBase();
}
