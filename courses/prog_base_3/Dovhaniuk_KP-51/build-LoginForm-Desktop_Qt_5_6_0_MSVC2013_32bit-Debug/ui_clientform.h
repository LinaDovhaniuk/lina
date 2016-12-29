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
    QLabel *label;
    QPushButton *clientExitButton;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *name;
    QLabel *surname;
    QLabel *birthday;
    QLabel *phone;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *clientForm)
    {
        if (clientForm->objectName().isEmpty())
            clientForm->setObjectName(QStringLiteral("clientForm"));
        clientForm->resize(597, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(clientForm->sizePolicy().hasHeightForWidth());
        clientForm->setSizePolicy(sizePolicy);
        clientForm->setMinimumSize(QSize(597, 600));
        clientForm->setMaximumSize(QSize(597, 600));
        clientForm->setBaseSize(QSize(597, 600));
        centralwidget = new QWidget(clientForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        buyButton = new QPushButton(centralwidget);
        buyButton->setObjectName(QStringLiteral("buyButton"));
        buyButton->setGeometry(QRect(342, 512, 246, 31));
        QFont font;
        font.setFamily(QStringLiteral("AR JULIAN"));
        font.setPointSize(14);
        buyButton->setFont(font);
        buyButton->setStyleSheet(QStringLiteral("backgroung-color:rgb(121, 140, 173)"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-28, 9, 601, 100));
        QFont font1;
        font1.setFamily(QStringLiteral("AR JULIAN"));
        font1.setPointSize(48);
        label->setFont(font1);
        clientExitButton = new QPushButton(centralwidget);
        clientExitButton->setObjectName(QStringLiteral("clientExitButton"));
        clientExitButton->setGeometry(QRect(13, 511, 101, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("AR JULIAN"));
        font2.setPointSize(16);
        clientExitButton->setFont(font2);
        clientExitButton->setStyleSheet(QStringLiteral("background-color: rgb(98, 120, 159);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(68, 142, 163, 68));
        QFont font3;
        font3.setFamily(QStringLiteral("MV Boli"));
        font3.setPointSize(20);
        label_2->setFont(font3);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(66, 196, 161, 67));
        label_6->setFont(font3);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(68, 254, 179, 78));
        label_7->setFont(font3);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(68, 328, 165, 76));
        label_8->setFont(font3);
        name = new QLabel(centralwidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(405, 153, 177, 52));
        name->setFont(font2);
        name->setAutoFillBackground(false);
        surname = new QLabel(centralwidget);
        surname->setObjectName(QStringLiteral("surname"));
        surname->setGeometry(QRect(403, 211, 178, 56));
        surname->setFont(font2);
        surname->setAutoFillBackground(false);
        birthday = new QLabel(centralwidget);
        birthday->setObjectName(QStringLiteral("birthday"));
        birthday->setGeometry(QRect(410, 333, 179, 57));
        birthday->setFont(font2);
        birthday->setAutoFillBackground(false);
        phone = new QLabel(centralwidget);
        phone->setObjectName(QStringLiteral("phone"));
        phone->setGeometry(QRect(407, 269, 180, 56));
        phone->setFont(font2);
        phone->setAutoFillBackground(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-3, -1, 601, 555));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../../../project/\320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\270/1316617074_yoga-dlya-zhivotnyh-3.jpg")));
        clientForm->setCentralWidget(centralwidget);
        label_3->raise();
        buyButton->raise();
        label->raise();
        clientExitButton->raise();
        label_2->raise();
        label_6->raise();
        label_7->raise();
        label_8->raise();
        name->raise();
        surname->raise();
        birthday->raise();
        phone->raise();
        menubar = new QMenuBar(clientForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 597, 26));
        clientForm->setMenuBar(menubar);
        statusbar = new QStatusBar(clientForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        clientForm->setStatusBar(statusbar);

        retranslateUi(clientForm);

        QMetaObject::connectSlotsByName(clientForm);
    } // setupUi

    void retranslateUi(QMainWindow *clientForm)
    {
        clientForm->setWindowTitle(QApplication::translate("clientForm", "Client", 0));
        buyButton->setText(QApplication::translate("clientForm", "Extend abonnement", 0));
        label->setText(QApplication::translate("clientForm", "   Client Page", 0));
        clientExitButton->setText(QApplication::translate("clientForm", "Exit", 0));
        label_2->setText(QApplication::translate("clientForm", "Name", 0));
        label_6->setText(QApplication::translate("clientForm", "Surname", 0));
        label_7->setText(QApplication::translate("clientForm", "Birthday", 0));
        label_8->setText(QApplication::translate("clientForm", "Phone", 0));
        name->setText(QString());
        surname->setText(QString());
        birthday->setText(QString());
        phone->setText(QString());
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class clientForm: public Ui_clientForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTFORM_H
