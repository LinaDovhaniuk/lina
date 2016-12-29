/********************************************************************************
** Form generated from reading UI file 'addclient.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCLIENT_H
#define UI_ADDCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddClient
{
public:
    QWidget *centralwidget;
    QPushButton *ok;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *name;
    QLineEdit *surname;
    QLineEdit *phone;
    QLineEdit *birthday;
    QLineEdit *login;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout;
    QCheckBox *clientBox;
    QCheckBox *coachBox;
    QCheckBox *adminBox;
    QLineEdit *finish_time;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddClient)
    {
        if (AddClient->objectName().isEmpty())
            AddClient->setObjectName(QStringLiteral("AddClient"));
        AddClient->resize(453, 287);
        centralwidget = new QWidget(AddClient);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ok = new QPushButton(centralwidget);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(311, 72, 80, 16));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(118, 15, 174, 220));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        name = new QLineEdit(layoutWidget);
        name->setObjectName(QStringLiteral("name"));

        verticalLayout->addWidget(name);

        surname = new QLineEdit(layoutWidget);
        surname->setObjectName(QStringLiteral("surname"));

        verticalLayout->addWidget(surname);

        phone = new QLineEdit(layoutWidget);
        phone->setObjectName(QStringLiteral("phone"));

        verticalLayout->addWidget(phone);

        birthday = new QLineEdit(layoutWidget);
        birthday->setObjectName(QStringLiteral("birthday"));

        verticalLayout->addWidget(birthday);

        login = new QLineEdit(layoutWidget);
        login->setObjectName(QStringLiteral("login"));

        verticalLayout->addWidget(login);

        password = new QLineEdit(layoutWidget);
        password->setObjectName(QStringLiteral("password"));

        verticalLayout->addWidget(password);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        clientBox = new QCheckBox(layoutWidget);
        clientBox->setObjectName(QStringLiteral("clientBox"));

        horizontalLayout->addWidget(clientBox);

        coachBox = new QCheckBox(layoutWidget);
        coachBox->setObjectName(QStringLiteral("coachBox"));

        horizontalLayout->addWidget(coachBox);

        adminBox = new QCheckBox(layoutWidget);
        adminBox->setObjectName(QStringLiteral("adminBox"));

        horizontalLayout->addWidget(adminBox);


        verticalLayout->addLayout(horizontalLayout);

        finish_time = new QLineEdit(layoutWidget);
        finish_time->setObjectName(QStringLiteral("finish_time"));

        verticalLayout->addWidget(finish_time);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(23, 16, 78, 212));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        AddClient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddClient);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 453, 17));
        AddClient->setMenuBar(menubar);
        statusbar = new QStatusBar(AddClient);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AddClient->setStatusBar(statusbar);

        retranslateUi(AddClient);

        QMetaObject::connectSlotsByName(AddClient);
    } // setupUi

    void retranslateUi(QMainWindow *AddClient)
    {
        AddClient->setWindowTitle(QApplication::translate("AddClient", "MainWindow", 0));
        ok->setText(QApplication::translate("AddClient", "ok", 0));
        clientBox->setText(QApplication::translate("AddClient", "Client", 0));
        coachBox->setText(QApplication::translate("AddClient", "Coach", 0));
        adminBox->setText(QApplication::translate("AddClient", "Admin", 0));
        label->setText(QApplication::translate("AddClient", "Name", 0));
        label_2->setText(QApplication::translate("AddClient", "Surname", 0));
        label_3->setText(QApplication::translate("AddClient", "Phone", 0));
        label_4->setText(QApplication::translate("AddClient", "Birthday", 0));
        label_5->setText(QApplication::translate("AddClient", "Login", 0));
        label_6->setText(QApplication::translate("AddClient", "Password", 0));
        label_7->setText(QApplication::translate("AddClient", "Type", 0));
        label_8->setText(QApplication::translate("AddClient", "Finish time", 0));
    } // retranslateUi

};

namespace Ui {
    class AddClient: public Ui_AddClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCLIENT_H
