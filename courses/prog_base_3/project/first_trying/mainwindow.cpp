#include "mainwindow.h"

MainWindow::MainWindow(){
     QTextCodec *codec = QTextCodec::codecForName("UTF8");
     QTextCodec::setCodecForTr(codec);

     actionExit = new QAction(tr("В&ыход"), this);
     actionExit->setStatusTip(tr("Выход из программы"));
     actionExit->setShortcut(tr("Ctrl+Q"));
     connect(actionExit, SIGNAL(triggered()), qApp, SLOT(quit()));

     actionAbout = new QAction(tr("&О программе"), this);
     actionAbout->setStatusTip(tr("Сведения о программе"));
     connect(actionAbout, SIGNAL(triggered()), this, SLOT(slotAbout()));

     menuFile = menuBar()->addMenu(tr("&Файл"));
     menuFile->addAction(actionExit);
     menuFile = menuBar()->addMenu(tr("&Справка"));
     menuFile->addAction(actionAbout);

     labelMenu = new QLabel(statusBar());

     statusBar()->setSizeGripEnabled(true);
     statusBar()->addWidget(labelMenu, 1);

     mainWidget = new QWidget();
     setCentralWidget(mainWidget);

     tableWidget = new QTableWidget();
     tableWidget->setColumnCount(4);
     tableWidget->setColumnWidth(0,200);
     tableWidget->setColumnWidth(1,200);
     tableWidget->setColumnWidth(2,50);
     tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem(tr("ID")));
     tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem(tr("DateTime")));
     tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem(tr("String")));
     tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem(tr("Integer")));
     tableWidget->setShowGrid(true);
     tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
     tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
     tableWidget->setColumnHidden(0, true);

     butAdd = new QPushButton(tr("Добавить"));
     butAdd->setStatusTip(tr("Дабавить данные"));
     connect(butAdd, SIGNAL(clicked()), this, SLOT(slotAdd()));

     butDelete = new QPushButton(tr("Удалить"));
     butDelete->setStatusTip(tr("Удалить данные"));
     connect(butDelete, SIGNAL(clicked()), this, SLOT(slotDelete()));

     lineEdit = new QLineEdit();

     spinBox = new QSpinBox();

     vlayout = new QVBoxLayout;
     hlayout = new QHBoxLayout;

     vlayout->addWidget(tableWidget);
     hlayout->addWidget(lineEdit);
     hlayout->addWidget(spinBox);
     hlayout->addStretch(1);
     hlayout->addWidget(butAdd);
     hlayout->addWidget(butDelete);
     vlayout->addLayout(hlayout);
     mainWidget->setLayout(vlayout);

     db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName(QFileDialog::getOpenFileName(0, tr("Открыть файл"), QDir::currentPath()));
     if (!db.open())
     {
         QMessageBox::warning( 0 , "Ошибка!", db.lastError().databaseText());
     }

     RefreshTable();
}

MainWindow::~MainWindow(){
     db.close();
     db.removeDatabase(db.connectionName());

     delete(hlayout);
     delete(vlayout);
     delete(spinBox);
     delete(lineEdit);
     delete(butDelete);
     delete(butAdd);
     delete(tableWidget);
     delete(mainWidget);
     delete(labelMenu);
     delete(actionAbout);
     delete(actionExit);
}

void MainWindow::RefreshTable(){
     int n = tableWidget->rowCount();
     for( int i = 0; i < n; i++ ) tableWidget->removeRow( 0 );

     QSqlQuery query;
     query.exec("SELECT * FROM tabMain;");

     while (query.next()){
          tableWidget->insertRow(0);
          tableWidget->setItem(0, 0, new QTableWidgetItem(query.value(0).toString()));
          tableWidget->setItem(0, 1, new QTableWidgetItem(query.value(1).toDateTime().toString()));
          tableWidget->setItem(0, 2, new QTableWidgetItem(query.value(2).toString()));
          tableWidget->setItem(0, 3, new QTableWidgetItem(query.value(3).toString()));
          tableWidget->setRowHeight(0, 20);
     }
}

void MainWindow::slotAdd(){
     QSqlQuery query;
     query.prepare("INSERT INTO tabMain VALUES (null , :datetime, :string, :int);");
     query.bindValue(":datetime", QDateTime::currentDateTime());
     query.bindValue(":string", lineEdit->text());
     query.bindValue(":int", spinBox->value());
     query.exec();

     RefreshTable();
}

void MainWindow::slotDelete(){
     if(tableWidget->currentIndex().row() >= 0)
     {
          QSqlQuery query;
          query.prepare("DELETE FROM tabMain WHERE ID = :id;");
          query.bindValue(":id", tableWidget->item(tableWidget->currentIndex().row(), 0)->text());
          query.exec();

          RefreshTable();
     }
}

void MainWindow::slotAbout(){
     QMessageBox::about( 0 , tr("О программе..."), tr("©2009 Dmitry <a href='http://example.com'>http://example.com</a>
Специально для <a href='http://open-life.org'>OpenLife</a>"));
}
