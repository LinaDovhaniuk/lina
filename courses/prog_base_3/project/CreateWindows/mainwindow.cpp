#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Инициализируем второе окно
    sWindow = new AnotherWindow();
    // подключаем к слоту запуска главного окна по кнопке во втором окне
    connect(sWindow, &AnotherWindow::firstWindow, this, &MainWindow::show);

    // Инициализируем третье окно
    thirdWindow = new AnotherWindow();
    // подключаем к слоту запуска главного окна по кнопке в третьем окне
    connect(thirdWindow, &AnotherWindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    sWindow->show();  // Показываем второе окно
    this->close();    // Закрываем основное окно
}

void MainWindow::on_pushButton_2_clicked()
{
    thirdWindow->show();  // Показываем третье окно
    this->close();    // Закрываем основное окно
}
