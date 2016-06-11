#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "adminform.h"
#include "database.h"
#include "clientform.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login){

    ui->setupUi(this);



    }

Login::~Login(){
    delete ui;
}
QString Login :: getLogin(){
    return ui->loginLineEdit->text();
}

void Login::on_pushButton_clicked(){
    QSqlQuery query;
    AdminForm *adminForm = new AdminForm();
    clientForm *clF = new clientForm();
    db = new DataBase();
    db->connectToDataBase();

    QString log = getLogin();
    query.exec("SELECT type FROM ABONNEMENT WHERE login = '"+log+"'';");

    if(db->authorization(log,ui->passwordLineEdit->text())){
        if(query.value(0) == 0 || query.value(0) == 1){
            this->close();
            clF->show();
        }
    else{
        this->close();
        adminForm->show();
    }
    }
    db->closeDataBase();
}
