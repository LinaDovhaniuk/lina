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
#include <QtWidgets/QLineEdit>
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
    QLabel *label;
    QTableView *adminTable;
    QPushButton *AdminExitButton;
    QPushButton *addButton;
    QPushButton *findBotton;
    QPushButton *TrainReviewButton;
    QPushButton *InventReviewButton;
    QPushButton *CoachReviewButton;
    QPushButton *ClientReviewButton;
    QLineEdit *findLog;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdminForm)
    {
        if (AdminForm->objectName().isEmpty())
            AdminForm->setObjectName(QStringLiteral("AdminForm"));
        AdminForm->resize(1198, 585);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AdminForm->sizePolicy().hasHeightForWidth());
        AdminForm->setSizePolicy(sizePolicy);
        AdminForm->setMinimumSize(QSize(1198, 585));
        AdminForm->setMaximumSize(QSize(1198, 585));
        AdminForm->setBaseSize(QSize(1198, 585));
        centralwidget = new QWidget(AdminForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(124, 4, 881, 81));
        QFont font;
        font.setFamily(QStringLiteral("AR JULIAN"));
        font.setPointSize(72);
        label->setFont(font);
        adminTable = new QTableView(centralwidget);
        adminTable->setObjectName(QStringLiteral("adminTable"));
        adminTable->setGeometry(QRect(418, 114, 472, 356));
        adminTable->setStyleSheet(QStringLiteral("background-color: rgb(222, 200, 212);"));
        adminTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        AdminExitButton = new QPushButton(centralwidget);
        AdminExitButton->setObjectName(QStringLiteral("AdminExitButton"));
        AdminExitButton->setGeometry(QRect(24, 493, 101, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("AR JULIAN"));
        font1.setPointSize(16);
        AdminExitButton->setFont(font1);
        AdminExitButton->setStyleSheet(QStringLiteral("background-color: rgb(223, 203, 214);"));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName(QStringLiteral("addButton"));
        addButton->setGeometry(QRect(31, 218, 142, 38));
        addButton->setFont(font1);
        addButton->setStyleSheet(QStringLiteral("background-color: rgb(233, 216, 224);"));
        findBotton = new QPushButton(centralwidget);
        findBotton->setObjectName(QStringLiteral("findBotton"));
        findBotton->setGeometry(QRect(29, 379, 141, 41));
        findBotton->setFont(font1);
        findBotton->setStyleSheet(QStringLiteral("background-color:rgb(222, 198, 211)"));
        TrainReviewButton = new QPushButton(centralwidget);
        TrainReviewButton->setObjectName(QStringLiteral("TrainReviewButton"));
        TrainReviewButton->setGeometry(QRect(26, 115, 144, 43));
        TrainReviewButton->setFont(font1);
        TrainReviewButton->setStyleSheet(QStringLiteral("background-color: rgb(228, 208, 219);"));
        InventReviewButton = new QPushButton(centralwidget);
        InventReviewButton->setObjectName(QStringLiteral("InventReviewButton"));
        InventReviewButton->setGeometry(QRect(28, 165, 146, 43));
        InventReviewButton->setFont(font1);
        InventReviewButton->setStyleSheet(QStringLiteral("background-color: rgb(228, 208, 219);"));
        CoachReviewButton = new QPushButton(centralwidget);
        CoachReviewButton->setObjectName(QStringLiteral("CoachReviewButton"));
        CoachReviewButton->setGeometry(QRect(26, 68, 146, 43));
        CoachReviewButton->setFont(font1);
        CoachReviewButton->setStyleSheet(QStringLiteral("background-color: rgb(226, 206, 217);"));
        ClientReviewButton = new QPushButton(centralwidget);
        ClientReviewButton->setObjectName(QStringLiteral("ClientReviewButton"));
        ClientReviewButton->setGeometry(QRect(25, 16, 147, 43));
        ClientReviewButton->setFont(font1);
        ClientReviewButton->setStyleSheet(QStringLiteral("background-color: rgb(228, 211, 221);"));
        findLog = new QLineEdit(centralwidget);
        findLog->setObjectName(QStringLiteral("findLog"));
        findLog->setGeometry(QRect(29, 342, 140, 28));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(31, 309, 92, 36));
        label_3->setFont(font1);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 266, 141, 37));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QStringLiteral("background-color: rgb(223, 201, 213);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(-1, 0, 700, 537));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../../../project/\320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\270/4486275.jpg")));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(633, -4, 566, 539));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../../../project/\320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\270/s6.png")));
        AdminForm->setCentralWidget(centralwidget);
        label_2->raise();
        label_4->raise();
        label->raise();
        AdminExitButton->raise();
        addButton->raise();
        findBotton->raise();
        adminTable->raise();
        TrainReviewButton->raise();
        InventReviewButton->raise();
        CoachReviewButton->raise();
        ClientReviewButton->raise();
        findLog->raise();
        label_3->raise();
        pushButton->raise();
        menubar = new QMenuBar(AdminForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1198, 26));
        AdminForm->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AdminForm->setStatusBar(statusbar);

        retranslateUi(AdminForm);

        QMetaObject::connectSlotsByName(AdminForm);
    } // setupUi

    void retranslateUi(QMainWindow *AdminForm)
    {
        AdminForm->setWindowTitle(QApplication::translate("AdminForm", "Admin", 0));
        label->setText(QApplication::translate("AdminForm", "   Admin Page", 0));
        AdminExitButton->setText(QApplication::translate("AdminForm", "Exit", 0));
        addButton->setText(QApplication::translate("AdminForm", "Add", 0));
        findBotton->setText(QApplication::translate("AdminForm", "Search", 0));
        TrainReviewButton->setText(QApplication::translate("AdminForm", "Training", 0));
        InventReviewButton->setText(QApplication::translate("AdminForm", "Inventory", 0));
        CoachReviewButton->setText(QApplication::translate("AdminForm", "Coaches", 0));
        ClientReviewButton->setText(QApplication::translate("AdminForm", "Clients", 0));
        label_3->setText(QApplication::translate("AdminForm", "Login", 0));
        pushButton->setText(QApplication::translate("AdminForm", "Delete", 0));
        label_2->setText(QString());
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AdminForm: public Ui_AdminForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINFORM_H
