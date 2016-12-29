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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QPushButton *backBotton;
    QPushButton *buyMonth;
    QLabel *label;
    QPushButton *buyYear;
    QLabel *finish;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *abonnementForm)
    {
        if (abonnementForm->objectName().isEmpty())
            abonnementForm->setObjectName(QStringLiteral("abonnementForm"));
        abonnementForm->resize(586, 411);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(abonnementForm->sizePolicy().hasHeightForWidth());
        abonnementForm->setSizePolicy(sizePolicy);
        abonnementForm->setMinimumSize(QSize(586, 411));
        abonnementForm->setMaximumSize(QSize(586, 411));
        centralwidget = new QWidget(abonnementForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        backBotton = new QPushButton(centralwidget);
        backBotton->setObjectName(QStringLiteral("backBotton"));
        backBotton->setGeometry(QRect(17, 310, 101, 31));
        QFont font;
        font.setFamily(QStringLiteral("AR JULIAN"));
        font.setPointSize(16);
        backBotton->setFont(font);
        buyMonth = new QPushButton(centralwidget);
        buyMonth->setObjectName(QStringLiteral("buyMonth"));
        buyMonth->setGeometry(QRect(37, 202, 196, 48));
        QFont font1;
        font1.setFamily(QStringLiteral("AR JULIAN"));
        font1.setPointSize(14);
        buyMonth->setFont(font1);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(6, -7, 521, 91));
        QFont font2;
        font2.setFamily(QStringLiteral("AR DELANEY"));
        font2.setPointSize(48);
        label->setFont(font2);
        buyYear = new QPushButton(centralwidget);
        buyYear->setObjectName(QStringLiteral("buyYear"));
        buyYear->setGeometry(QRect(265, 202, 202, 49));
        buyYear->setFont(font1);
        finish = new QLabel(centralwidget);
        finish->setObjectName(QStringLiteral("finish"));
        finish->setGeometry(QRect(264, 121, 207, 52));
        sizePolicy.setHeightForWidth(finish->sizePolicy().hasHeightForWidth());
        finish->setSizePolicy(sizePolicy);
        finish->setMinimumSize(QSize(207, 52));
        finish->setMaximumSize(QSize(207, 52));
        finish->setFont(font1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(21, 118, 239, 55));
        label_2->setFont(font1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(-125, -32, 727, 415));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../../../project/\320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\270/bumaga_myatyy_svetlyy_ten_35117_1920x1080.jpg")));
        abonnementForm->setCentralWidget(centralwidget);
        label_3->raise();
        backBotton->raise();
        buyMonth->raise();
        label->raise();
        buyYear->raise();
        finish->raise();
        label_2->raise();
        menubar = new QMenuBar(abonnementForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 586, 26));
        abonnementForm->setMenuBar(menubar);
        statusbar = new QStatusBar(abonnementForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        abonnementForm->setStatusBar(statusbar);

        retranslateUi(abonnementForm);

        QMetaObject::connectSlotsByName(abonnementForm);
    } // setupUi

    void retranslateUi(QMainWindow *abonnementForm)
    {
        abonnementForm->setWindowTitle(QApplication::translate("abonnementForm", "Abonnement", 0));
        backBotton->setText(QApplication::translate("abonnementForm", "Back", 0));
        buyMonth->setText(QApplication::translate("abonnementForm", "Buy for month", 0));
        label->setText(QApplication::translate("abonnementForm", "  Abonnement", 0));
        buyYear->setText(QApplication::translate("abonnementForm", " Buy for year", 0));
        finish->setText(QString());
        label_2->setText(QApplication::translate("abonnementForm", "  Your abonnement :", 0));
        label_3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class abonnementForm: public Ui_abonnementForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABONNEMENTFORM_H
