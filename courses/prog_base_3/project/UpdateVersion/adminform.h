#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QMainWindow>
#include <QSqlTableModel>
#include "addclient.h"
#include "database.h"

namespace Ui {
class AdminForm;
}

class AdminForm : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminForm(QWidget *parent = 0);
    ~AdminForm();

private slots:

    void on_addButton_clicked();
    void on_ClientReviewButton_clicked();
    void on_adminTable_activated(const QModelIndex &index);

    void slotUpdateModels();

private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();

private:
    Ui::AdminForm *ui;
    AddClient *addClient;
    DataBase *db;
    QSqlTableModel *modelClients;
};

#endif // ADMINFORM_H
