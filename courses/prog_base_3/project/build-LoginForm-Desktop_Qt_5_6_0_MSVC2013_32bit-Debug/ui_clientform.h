/********************************************************************************
** Form generated from reading UI file 'clientform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTFORM_H
#define UI_CLIENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientForm
{
public:
    QWidget *centralwidget;
    QPushButton *buyButton;
    QPushButton *trainButton;
    QLabel *label;
    QPushButton *clientExitButton;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *photo;
    QLabel *name;
    QLabel *surname;
    QLabel *birthday;
    QLabel *phone;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *clientForm)
    {
        if (clientForm->objectName().isEmpty())
            clientForm->setObjectName(QStringLiteral("clientForm"));
        clientForm->resize(800, 600);
        centralwidget = new QWidget(clientForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        buyButton = new QPushButton(centralwidget);
        buyButton->setObjectName(QStringLiteral("buyButton"));
        buyButton->setGeometry(QRect(290, 240, 141, 31));
        QFont font;
        font.setFamily(QStringLiteral("MV Boli"));
        font.setPointSize(14);
        buyButton->setFont(font);
        trainButton = new QPushButton(centralwidget);
        trainButton->setObjectName(QStringLiteral("trainButton"));
        trainButton->setGeometry(QRect(140, 240, 141, 31));
        trainButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 451, 81));
        QFont font1;
        font1.setFamily(QStringLiteral("AR BLANCA"));
        font1.setPointSize(72);
        label->setFont(font1);
        clientExitButton = new QPushButton(centralwidget);
        clientExitButton->setObjectName(QStringLiteral("clientExitButton"));
        clientExitButton->setGeometry(QRect(10, 240, 101, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("MV Boli"));
        font2.setPointSize(16);
        clientExitButton->setFont(font2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 90, 81, 21));
        label_2->setFont(font2);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(150, 120, 81, 21));
        label_6->setFont(font2);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(150, 150, 81, 20));
        label_7->setFont(font2);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(150, 180, 81, 21));
        label_8->setFont(font2);
        photo = new QLabel(centralwidget);
        photo->setObjectName(QStringLiteral("photo"));
        photo->setGeometry(QRect(10, 90, 121, 121));
        photo->setPixmap(QPixmap(QString::fromUtf8("../../\320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\270/S69Hj4xCzpU.jpg")));
        name = new QLabel(centralwidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(240, 90, 111, 20));
        surname = new QLabel(centralwidget);
        surname->setObjectName(QStringLiteral("surname"));
        surname->setGeometry(QRect(240, 110, 111, 31));
        birthday = new QLabel(centralwidget);
        birthday->setObjectName(QStringLiteral("birthday"));
        birthday->setGeometry(QRect(240, 150, 101, 21));
        phone = new QLabel(centralwidget);
        phone->setObjectName(QStringLiteral("phone"));
        phone->setGeometry(QRect(240, 180, 111, 20));
        clientForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(clientForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        clientForm->setMenuBar(menubar);
        statusbar = new QStatusBar(clientForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        clientForm->setStatusBar(statusbar);

        retranslateUi(clientForm);

        QMetaObject::connectSlotsByName(clientForm);
    } // setupUi

    void retranslateUi(QMainWindow *clientForm)
    {
        clientForm->setWindowTitle(QApplication::translate("clientForm", "MainWindow", 0));
        buyButton->setText(QApplication::translate("clientForm", "Extend abonnement", 0));
        trainButton->setText(QApplication::translate("clientForm", "Training", 0));
        label->setText(QApplication::translate("clientForm", "   Client Page", 0));
        clientExitButton->setText(QApplication::translate("clientForm", "Exit", 0));
        label_2->setText(QApplication::translate("clientForm", "Name", 0));
        label_6->setText(QApplication::translate("clientForm", "Surname", 0));
        label_7->setText(QApplication::translate("clientForm", "Birthday", 0));
        label_8->setText(QApplication::translate("clientForm", "Phone", 0));
        photo->setText(QString());
        name->setText(QString());
        surname->setText(QString());
        birthday->setText(QString());
        phone->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class clientForm: public Ui_clientForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTFORM_H
