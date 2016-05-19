/********************************************************************************
** Form generated from reading UI file 'adminform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINFORM_H
#define UI_ADMINFORM_H

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
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminForm
{
public:
    QWidget *centralwidget;
    QPushButton *ClientReviewButton;
    QPushButton *CoachReviewButton;
    QPushButton *InventReviewButton;
    QLabel *label;
    QTableView *adminTable;
    QPushButton *AdminExitButton;
    QPushButton *TrainReviewButton;
    QPushButton *abonnementButton;
    QPushButton *addButton;
    QPushButton *findBotton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminForm)
    {
        if (AdminForm->objectName().isEmpty())
            AdminForm->setObjectName(QStringLiteral("AdminForm"));
        AdminForm->resize(489, 387);
        centralwidget = new QWidget(AdminForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ClientReviewButton = new QPushButton(centralwidget);
        ClientReviewButton->setObjectName(QStringLiteral("ClientReviewButton"));
        ClientReviewButton->setGeometry(QRect(20, 90, 121, 21));
        QFont font;
        font.setFamily(QStringLiteral("MV Boli"));
        font.setPointSize(16);
        ClientReviewButton->setFont(font);
        CoachReviewButton = new QPushButton(centralwidget);
        CoachReviewButton->setObjectName(QStringLiteral("CoachReviewButton"));
        CoachReviewButton->setGeometry(QRect(20, 130, 121, 20));
        CoachReviewButton->setFont(font);
        InventReviewButton = new QPushButton(centralwidget);
        InventReviewButton->setObjectName(QStringLiteral("InventReviewButton"));
        InventReviewButton->setGeometry(QRect(20, 170, 121, 21));
        InventReviewButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 441, 81));
        QFont font1;
        font1.setFamily(QStringLiteral("AR BLANCA"));
        font1.setPointSize(72);
        label->setFont(font1);
        adminTable = new QTableView(centralwidget);
        adminTable->setObjectName(QStringLiteral("adminTable"));
        adminTable->setGeometry(QRect(170, 90, 301, 181));
        AdminExitButton = new QPushButton(centralwidget);
        AdminExitButton->setObjectName(QStringLiteral("AdminExitButton"));
        AdminExitButton->setGeometry(QRect(20, 290, 91, 20));
        AdminExitButton->setFont(font);
        TrainReviewButton = new QPushButton(centralwidget);
        TrainReviewButton->setObjectName(QStringLiteral("TrainReviewButton"));
        TrainReviewButton->setGeometry(QRect(20, 210, 121, 21));
        TrainReviewButton->setFont(font);
        abonnementButton = new QPushButton(centralwidget);
        abonnementButton->setObjectName(QStringLiteral("abonnementButton"));
        abonnementButton->setGeometry(QRect(20, 250, 121, 20));
        abonnementButton->setFont(font);
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(270, 290, 91, 21));
        addButton->setFont(font);
        findBotton = new QPushButton(centralwidget);
        findBotton->setObjectName(QStringLiteral("findBotton"));
        findBotton->setGeometry(QRect(380, 290, 91, 21));
        findBotton->setFont(font);
        AdminForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 489, 17));
        AdminForm->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AdminForm->setStatusBar(statusbar);

        retranslateUi(AdminForm);

        QMetaObject::connectSlotsByName(AdminForm);
    } // setupUi

    void retranslateUi(QMainWindow *AdminForm)
    {
        AdminForm->setWindowTitle(QApplication::translate("AdminForm", "MainWindow", 0));
        ClientReviewButton->setText(QApplication::translate("AdminForm", "Clients", 0));
        CoachReviewButton->setText(QApplication::translate("AdminForm", "Coaches", 0));
        InventReviewButton->setText(QApplication::translate("AdminForm", "Inventory", 0));
        label->setText(QApplication::translate("AdminForm", "   Admin Page", 0));
        AdminExitButton->setText(QApplication::translate("AdminForm", "Exit", 0));
        TrainReviewButton->setText(QApplication::translate("AdminForm", "Training", 0));
        abonnementButton->setText(QApplication::translate("AdminForm", "Abonnement", 0));
        addButton->setText(QApplication::translate("AdminForm", "Add", 0));
        findBotton->setText(QApplication::translate("AdminForm", "Find", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminForm: public Ui_AdminForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINFORM_H
