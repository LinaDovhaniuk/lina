#include "adminform.h"
#include "ui_adminform.h"

AdminForm::AdminForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminForm)
{
    ui->setupUi(this);

    addClient = new AddClient();
    db = new DataBase();
    db->connectToDataBase();

    this->setupModel("CLIETNS",
                     QStringList() << trUtf8("ID")
                                         << trUtf8("Name")
                                         << trUtf8("Surname")
                                         << trUtf8("Phone")
                                         << trUtf8("Birthday")
                                         << trUtf8("Abonnement")
               );
    /* Инициализируем внешний вид таблицы с данными
     * */
    this->createUI();
}

AdminForm::~AdminForm(){
    delete ui;
}


void AdminForm::on_addButton_clicked(){
    addClient->show();
}

void AdminForm::on_ClientReviewButton_clicked(){

}

void AdminForm::setupModel(const QString &tableName, const QStringList &headers){
    /* Производим инициализацию модели представления данных
     * */
    modelClients = new QSqlTableModel(this);
    modelClients->setTable(tableName);
    modelClients->select();
    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    for(int i = 0, j = 0; i < modelClients->columnCount(); i++, j++){
        modelClients->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
}

void AdminForm::slotUpdateModels(){
    modelClients->select();
}




void AdminForm::on_adminTable_activated(const QModelIndex &index){

}
