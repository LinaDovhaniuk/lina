#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QMainWindow>
#include <QSqlTableModel>

namespace Ui {
class table;
}

class table : public QWidget
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = 0);
    ~table();

private slots:
    void on_addClientButton_clicked();
    void slotUpdateModels();
    void slotEditRecord(QModelIndex index);

private:
    Ui::table *ui;
//    DataBase                    *db;
    QSqlTableModel              *modelClients;

private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};

#endif // TABLE_H
