#ifndef ADMINFORM_H
#define ADMINFORM_H

#include <QMainWindow>
#include <QSqlTableModel>



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

    void slotUpdateModels();

    void on_CoachReviewButton_clicked();

    void on_InventReviewButton_clicked();

    void on_TrainReviewButton_clicked();
 //   void slotEditRecord(QModelIndex index);

    void on_AdminExitButton_clicked();

    void on_abonnementButton_clicked();

    void on_findBotton_clicked();

private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();

private:
    Ui::AdminForm *ui;
    QSqlTableModel *modelClients;
};

#endif // ADMINFORM_H
