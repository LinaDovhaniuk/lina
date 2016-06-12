#include "findform.h"
#include "ui_findform.h"
#include <QtSql>
#include <QDebug>

/*
findForm::findForm(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::findForm){
    ui->setupUi(this);
}

findForm::~findForm()
{
    delete ui;
}

void findForm::on_ok_clicked(){
    QString name = ui->name->text();
    QString surname = ui->surname->text();

    QSqlQuery query;
    query.exec("SELECT FROM CLIETNS WHERE name='"+name+"' AND surname = '"+surname+"'");

    /*this->setupModel("CLIETNS",
                     QStringList() << trUtf8("ID")
                                         << trUtf8("Name")
                                         << trUtf8("Surname")
                                         << trUtf8("Birthday")
                                         << trUtf8("Phone")
       );
    this->setupModel("ABONNEMENT",QStringList()<< trUtf8("Abonnement"));

    this->createUI();
}*/
