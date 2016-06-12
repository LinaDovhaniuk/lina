#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "adminform.h"
#include "database.h"
#include "clientform.h"
#include "connectedclient.h"


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login){

    ui->setupUi(this);

    db = new DataBase();

    }

Login::~Login(){
    delete ui;
}


void Login::on_pushButton_clicked(){
    db->connectToDataBase();

    QSqlQuery query;
    if(db->authorization(ui->loginLineEdit->text(),ui->passwordLineEdit->text())){
        if(query.exec("SELECT type FROM ABONNEMENT WHERE client_id = '"+ QString::number(us->user_getId()) +"';")){
            if(query.next()){
                if(query.value(0).toInt() == 0 || query.value(0).toInt() == 1){
                    clientForm *clF = new clientForm();
                    this->close();
                    clF->show();
                } else {
                    AdminForm *adminForm = new AdminForm();
                    this->close();
                    adminForm->show();
                }
            }
        }
    }

    db->closeDataBase();

}
