/********************************************************************************
** Form generated from reading UI file 'abonnementform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABONNEMENTFORM_H
#define UI_ABONNEMENTFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_abonnementForm
{
public:
    QWidget *centralwidget;
    QLineEdit *name;
    QLineEdit *surname;
    QPushButton *backBotton;
    QPushButton *buyMonth;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QCalendarWidget *calendarWidget;
    QPushButton *buyYeqr;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *abonnementForm)
    {
        if (abonnementForm->objectName().isEmpty())
            abonnementForm->setObjectName(QStringLiteral("abonnementForm"));
        abonnementForm->resize(800, 600);
        centralwidget = new QWidget(abonnementForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        name = new QLineEdit(centralwidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(140, 80, 151, 21));
        surname = new QLineEdit(centralwidget);
        surname->setObjectName(QStringLiteral("surname"));
        surname->setGeometry(QRect(140, 110, 151, 21));
        backBotton = new QPushButton(centralwidget);
        backBotton->setObjectName(QStringLiteral("backBotton"));
        backBotton->setGeometry(QRect(10, 250, 81, 20));
        QFont font;
        font.setFamily(QStringLiteral("MV Boli"));
        font.setPointSize(16);
        backBotton->setFont(font);
        buyMonth = new QPushButton(centralwidget);
        buyMonth->setObjectName(QStringLiteral("buyMonth"));
        buyMonth->setGeometry(QRect(20, 160, 111, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("MV Boli"));
        font1.setPointSize(14);
        buyMonth->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 0, 401, 71));
        QFont font2;
        font2.setFamily(QStringLiteral("AR BLANCA"));
        font2.setPointSize(72);
        label->setFont(font2);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 80, 111, 20));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 110, 111, 21));
        label_3->setFont(font);
        calendarWidget = new QCalendarWidget(centralwidget);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(320, 80, 141, 121));
        buyYeqr = new QPushButton(centralwidget);
        buyYeqr->setObjectName(QStringLiteral("buyYeqr"));
        buyYeqr->setGeometry(QRect(150, 160, 111, 21));
        buyYeqr->setFont(font1);
        abonnementForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(abonnementForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
        abonnementForm->setMenuBar(menubar);
        statusbar = new QStatusBar(abonnementForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        abonnementForm->setStatusBar(statusbar);

        retranslateUi(abonnementForm);

        QMetaObject::connectSlotsByName(abonnementForm);
    } // setupUi

    void retranslateUi(QMainWindow *abonnementForm)
    {
        abonnementForm->setWindowTitle(QApplication::translate("abonnementForm", "MainWindow", 0));
        backBotton->setText(QApplication::translate("abonnementForm", "Back", 0));
        buyMonth->setText(QApplication::translate("abonnementForm", "Buy for month", 0));
        label->setText(QApplication::translate("abonnementForm", "  Abonnement", 0));
        label_2->setText(QApplication::translate("abonnementForm", "Name", 0));
        label_3->setText(QApplication::translate("abonnementForm", "Surname", 0));
        buyYeqr->setText(QApplication::translate("abonnementForm", " Buy for year", 0));
    } // retranslateUi

};

namespace Ui {
    class abonnementForm: public Ui_abonnementForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABONNEMENTFORM_H
