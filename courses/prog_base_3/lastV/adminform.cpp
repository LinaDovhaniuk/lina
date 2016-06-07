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


}

AdminForm::~AdminForm(){
    delete ui;
}


void AdminForm::on_addButton_clicked(){
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
    /* Инициализируем внешний вид таблицы с данными
     * */
    this->createUI();
}

void AdminForm::setupModel(const QString &tableName, const QStringList &headers){
    /* Производим инициализацию модели представления данных
     * */
    modelClients = new QSqlTableModel(this);
    modelClients->setTable(tableName);
    modelClients->select();
    /* Устанавливаем названия колонок в таблице с сортировкой данных
     * */
    for(int i = 0, j = 0; i < modelClients->columnCount()+1; i++, j++){
        modelClients->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
}

void AdminForm::slotUpdateModels(){
    modelClients->select();
}

void AdminForm::createUI(){
    ui->adminTable->setModel(modelClients);     // Устанавливаем модель на TableView
    ui->adminTable->setColumnHidden(0, true);    // Скрываем колонку с id записей
    // Разрешаем выделение строк
    ui->adminTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    ui->adminTable->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    ui->adminTable->resizeColumnsToContents();
    ui->adminTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->adminTable->horizontalHeader()->setStretchLastSection(true);

    connect(ui->adminTable, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slotEditRecord(QModelIndex)));
}
