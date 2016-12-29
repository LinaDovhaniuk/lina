/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QWidget *centralWidget;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *loginLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(641, 635);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy);
        Login->setMinimumSize(QSize(641, 635));
        Login->setMaximumSize(QSize(641, 635));
        Login->setBaseSize(QSize(641, 635));
        Login->setAutoFillBackground(false);
        Login->setIconSize(QSize(400, 300));
        centralWidget = new QWidget(Login);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(641, 570));
        centralWidget->setMaximumSize(QSize(641, 570));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(12, 143, 111, 31));
        QFont font;
        font.setFamily(QStringLiteral("MV Boli"));
        font.setPointSize(18);
        label_2->setFont(font);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(6, 187, 133, 31));
        label_3->setFont(font);
        loginLineEdit = new QLineEdit(centralWidget);
        loginLineEdit->setObjectName(QStringLiteral("loginLineEdit"));
        loginLineEdit->setGeometry(QRect(151, 144, 191, 31));
        passwordLineEdit = new QLineEdit(centralWidget);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(153, 186, 191, 31));
        passwordLineEdit->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(272, 225, 112, 39));
        QFont font1;
        font1.setFamily(QStringLiteral("MV Boli"));
        font1.setPointSize(14);
        pushButton->setFont(font1);
        pushButton->setAutoFillBackground(true);
        pushButton->setStyleSheet(QStringLiteral("background-color:rgb(206, 235, 233)"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, -9, 672, 592));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../../../project/\320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\270/Work_it_Kitty_1.jpg")));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 555, 121, 16));
        label->setOpenExternalLinks(true);
        label->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(531, 551, 105, 20));
        Login->setCentralWidget(centralWidget);
        label_4->raise();
        label_2->raise();
        label_3->raise();
        loginLineEdit->raise();
        passwordLineEdit->raise();
        pushButton->raise();
        label->raise();
        label_5->raise();
        menuBar = new QMenuBar(Login);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 641, 26));
        Login->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Login);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Login->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Login);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Login->setStatusBar(statusBar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Login", 0));
        label_2->setText(QApplication::translate("Login", "Login", 0));
        label_3->setText(QApplication::translate("Login", "Password", 0));
        pushButton->setText(QApplication::translate("Login", "Log in", 0));
        label_4->setText(QString());
        label->setText(QApplication::translate("Login", "<html><head/><body><p><A HREF= 'http://www.kulturologia.ru/blogs/110913/18822/'>About our club</A></p></body></html>", 0));
        label_5->setText(QApplication::translate("Login", "<html><head></head><body><p><A HREF= 'https://youtu.be/APGku9p7Xa0'>My main coach</A></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
