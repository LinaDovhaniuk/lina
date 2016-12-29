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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddClient
{
public:
    QWidget *centralwidget;
    QPushButton *ok;
    QLabel *label_9;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_8;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *finish_time;
    QCheckBox *coachBox;
    QLineEdit *surname;
    QCheckBox *clientBox;
    QLineEdit *birthday;
    QCheckBox *adminBox;
    QLineEdit *password;
    QLineEdit *phone;
    QLineEdit *login;
    QLineEdit *name;
    QLabel *status;
    QPushButton *back;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddClient)
    {
        if (AddClient->objectName().isEmpty())
            AddClient->setObjectName(QStringLiteral("AddClient"));
        AddClient->resize(747, 661);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AddClient->sizePolicy().hasHeightForWidth());
        AddClient->setSizePolicy(sizePolicy);
        AddClient->setMinimumSize(QSize(747, 661));
        AddClient->setMaximumSize(QSize(747, 661));
        AddClient->setBaseSize(QSize(747, 661));
        AddClient->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(AddClient);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(747, 610));
        centralwidget->setMaximumSize(QSize(747, 610));
        ok = new QPushButton(centralwidget);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(43, 37, 150, 41));
        QFont font;
        font.setFamily(QStringLiteral("AR JULIAN"));
        font.setPointSize(26);
        ok->setFont(font);
        ok->setStyleSheet(QStringLiteral("background-color:rgb(90, 120, 131)"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(-21, -59, 772, 682));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(772, 682));
        label_9->setMaximumSize(QSize(772, 682));
        label_9->setBaseSize(QSize(772, 682));
        label_9->setPixmap(QPixmap(QString::fromUtf8("../../../../../project/\320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\270/8fUw9HBs5Qo.jpg")));
        label_9->setScaledContents(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(412, 341, 110, 32));
        QFont font1;
        font1.setFamily(QStringLiteral("AR JULIAN"));
        font1.setPointSize(12);
        label->setFont(font1);
        label->setAutoFillBackground(false);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(411, 495, 110, 30));
        label_4->setFont(font1);
        label_4->setAutoFillBackground(false);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(412, 558, 110, 32));
        label_8->setFont(font1);
        label_8->setAutoFillBackground(false);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(412, 434, 110, 33));
        label_6->setFont(font1);
        label_6->setAutoFillBackground(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(413, 372, 109, 29));
        label_2->setFont(font1);
        label_2->setAutoFillBackground(false);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(411, 525, 110, 33));
        label_7->setFont(font1);
        label_7->setAutoFillBackground(false);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(412, 400, 110, 35));
        label_5->setFont(font1);
        label_5->setAutoFillBackground(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(412, 465, 109, 30));
        label_3->setFont(font1);
        label_3->setAutoFillBackground(false);
        finish_time = new QLineEdit(centralwidget);
        finish_time->setObjectName(QStringLiteral("finish_time"));
        finish_time->setGeometry(QRect(523, 561, 207, 23));
        coachBox = new QCheckBox(centralwidget);
        coachBox->setObjectName(QStringLiteral("coachBox"));
        coachBox->setGeometry(QRect(594, 533, 75, 24));
        QFont font2;
        font2.setFamily(QStringLiteral("AR JULIAN"));
        font2.setPointSize(10);
        coachBox->setFont(font2);
        surname = new QLineEdit(centralwidget);
        surname->setObjectName(QStringLiteral("surname"));
        surname->setGeometry(QRect(520, 371, 213, 31));
        clientBox = new QCheckBox(centralwidget);
        clientBox->setObjectName(QStringLiteral("clientBox"));
        clientBox->setGeometry(QRect(513, 531, 78, 24));
        clientBox->setFont(font2);
        birthday = new QLineEdit(centralwidget);
        birthday->setObjectName(QStringLiteral("birthday"));
        birthday->setGeometry(QRect(521, 494, 209, 29));
        adminBox = new QCheckBox(centralwidget);
        adminBox->setObjectName(QStringLiteral("adminBox"));
        adminBox->setGeometry(QRect(668, 533, 74, 24));
        adminBox->setFont(font2);
        password = new QLineEdit(centralwidget);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(520, 435, 211, 28));
        password->setEchoMode(QLineEdit::Password);
        phone = new QLineEdit(centralwidget);
        phone->setObjectName(QStringLiteral("phone"));
        phone->setGeometry(QRect(520, 465, 210, 29));
        login = new QLineEdit(centralwidget);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(520, 404, 212, 29));
        name = new QLineEdit(centralwidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(519, 339, 214, 31));
        status = new QLabel(centralwidget);
        status->setObjectName(QStringLiteral("status"));
        status->setGeometry(QRect(44, 92, 230, 52));
        back = new QPushButton(centralwidget);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(7, 558, 147, 43));
        sizePolicy.setHeightForWidth(back->sizePolicy().hasHeightForWidth());
        back->setSizePolicy(sizePolicy);
        back->setFont(font);
        back->setStyleSheet(QStringLiteral("background-color:rgb(46, 82, 96)"));
        AddClient->setCentralWidget(centralwidget);
        label_9->raise();
        ok->raise();
        name->raise();
        label->raise();
        surname->raise();
        phone->raise();
        birthday->raise();
        login->raise();
        password->raise();
        finish_time->raise();
        label_8->raise();
        label_7->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        clientBox->raise();
        coachBox->raise();
        adminBox->raise();
        status->raise();
        back->raise();
        menubar = new QMenuBar(AddClient);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 747, 26));
        AddClient->setMenuBar(menubar);
        statusbar = new QStatusBar(AddClient);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AddClient->setStatusBar(statusbar);

        retranslateUi(AddClient);

        QMetaObject::connectSlotsByName(AddClient);
    } // setupUi

    void retranslateUi(QMainWindow *AddClient)
    {
        AddClient->setWindowTitle(QApplication::translate("AddClient", "Add Client", 0));
        ok->setText(QApplication::translate("AddClient", "Add", 0));
        label_9->setText(QString());
        label->setText(QApplication::translate("AddClient", "Name", 0));
        label_4->setText(QApplication::translate("AddClient", "Birthday", 0));
        label_8->setText(QApplication::translate("AddClient", "Finish time", 0));
        label_6->setText(QApplication::translate("AddClient", "Password", 0));
        label_2->setText(QApplication::translate("AddClient", "Surname", 0));
        label_7->setText(QApplication::translate("AddClient", "Type", 0));
        label_5->setText(QApplication::translate("AddClient", "Login", 0));
        label_3->setText(QApplication::translate("AddClient", "Phone", 0));
        finish_time->setText(QApplication::translate("AddClient", "1998-06-10", 0));
        coachBox->setText(QApplication::translate("AddClient", "Coach", 0));
        surname->setText(QApplication::translate("AddClient", "surname", 0));
        clientBox->setText(QApplication::translate("AddClient", "Client", 0));
        birthday->setText(QApplication::translate("AddClient", "1998-06-10", 0));
        adminBox->setText(QApplication::translate("AddClient", "Admin", 0));
        password->setText(QApplication::translate("AddClient", "password", 0));
        phone->setText(QApplication::translate("AddClient", "0937195161", 0));
        login->setText(QApplication::translate("AddClient", "login", 0));
        name->setText(QApplication::translate("AddClient", "name", 0));
        status->setText(QString());
        back->setText(QApplication::translate("AddClient", "Back", 0));
    } // retranslateUi

};

namespace Ui {
    class AddClient: public Ui_AddClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCLIENT_H
