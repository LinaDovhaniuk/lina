#include "adminform.h"
#include "ui_adminform.h"
#include "addclient.h"
#include "database.h"
#include "abonnementform.h"
#include "login.h"
//#include "findform.h"

AdminForm::AdminForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminForm){
    ui->setupUi(this);


    DataBase * db = new DataBase();
    db->connectToDataBase();


}

AdminForm::~AdminForm(){
    delete ui;
}

void AdminForm::on_addButton_clicked(){
    AddClient * addClient = new AddClient();
    addClient->show();
}

void AdminForm::on_ClientReviewButton_clicked(){
    this->setupModel("CLIETNS",
                     QStringList() << trUtf8("ID")
                                         << trUtf8("Name")
                                         << trUtf8("Surname")
                                         << trUtf8("Birthday")
                                         << trUtf8("Phone")
                                         << trUtf8("Abonnement")
               );

    this->createUI();
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
    this->setupModel("CLIETNS",
                     QStringList() << trUtf8("ID")
                                         << trUtf8("Name")
                                         << trUtf8("Surname")
                                         << trUtf8("Birthday")
                                         << trUtf8("Phone")
       );
    this->setupModel("ABONNEMENT",QStringList()<< trUtf8("Abonnement"));

    this->createUI();
}

void AdminForm::on_InventReviewButton_clicked(){
    this->setupModel("INVENTORY",
                     QStringList() << trUtf8("ID")
                                   << trUtf8("Name")
                                   << trUtf8("Price")
               );
    this->createUI();
}

void AdminForm::on_TrainReviewButton_clicked(){
    this->setupModel("TRAINING",
                     QStringList() << trUtf8("ID")
                                   << trUtf8("Name")
                                   << trUtf8("Price")
               );

    this->createUI();
}

/* Метод для активации диалога добавления записей в режиме редактирования
 * с передачей индекса выбранной строки
 * */
/*void AdminForm::slotEditRecord(QModelIndex index){
    /* Также создаем диалог и подключаем его сигнал завершения работы
     * к слоту обновления вида модели представления данных, но передаём
     * в качестве параметров строку записи
     * *
    AddClient * addClientDialog = new AddClient(index.row());
    connect(addClientDialog, SIGNAL(signalReady()), this, SLOT(slotUpdateModels()));

    /* Выполняем запуск диалогового окна
     * *
    addClientDialog->setWindowTitle(trUtf8("Edit Client"));
    addClientDialog->exec();
}*/


void AdminForm::on_AdminExitButton_clicked(){
    Login * log = new Login();
    this->close();
    log->show();
}

void AdminForm::on_abonnementButton_clicked(){
    abonnementForm * abonForm = new abonnementForm();
    this->close();
    abonForm->show();
}

void AdminForm::on_findBotton_clicked(){
    /*findForm * find = new findForm();
    this->close();
    find->show();*/
}
