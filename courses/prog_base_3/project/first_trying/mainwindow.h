#include <QDateTime>
#include <QFileDialog>

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
     MainWindow();
     ~MainWindow();

private:
     QAction *actionExit;
     QAction *actionAbout;
     QMenu *menuFile;
     QMenu *menuHelp;
     QLabel *labelMenu;
     QPushButton *butAdd;
     QPushButton *butDelete;
     QLineEdit *lineEdit;
     QSpinBox *spinBox;
     QVBoxLayout *vlayout;
     QHBoxLayout *hlayout;
     QWidget *mainWidget;
     QTableWidget *tableWidget;

     QSqlDatabase db;

     void RefreshTable();

private slots:
     void slotAdd();
     void slotDelete();
     void slotAbout();
};

#endif // MAINWINDOW_H
