#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login){

    //admForm = new MainWindow();
    ui->setupUi(this);

    adminForm = new AdminForm();
    db = new DataBase();
    db->connectToDataBase();

    /*mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("D:/project/Gym_newVersion/LoginForm/db.db");

        if(!(mydb.open())){
            ui->status->setText("Failed to open the db");
        }
        else ui->status->setText("Connected...");*/
    }

Login::~Login()
{
    delete ui;
}


void Login::on_pushButton_clicked(){
    if(db->authorization(ui->loginLineEdit->text(),ui->passwordLineEdit->text())){
        this->close();
        adminForm->show();
    }
}
