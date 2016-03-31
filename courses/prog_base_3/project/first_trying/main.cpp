#include <QApplication>
#include <QMainWindow>

#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *mw = new MainWindow();
    mw->setGeometry(200,200,600,400);
    mw->show();
    return app.exec();
}
