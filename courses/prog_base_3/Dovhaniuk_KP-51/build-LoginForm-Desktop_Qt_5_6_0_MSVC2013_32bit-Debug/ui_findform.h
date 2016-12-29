/********************************************************************************
** Form generated from reading UI file 'findform.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDFORM_H
#define UI_FINDFORM_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_findForm
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *name;
    QLineEdit *surname;
    QPushButton *ok;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *findForm)
    {
        if (findForm->objectName().isEmpty())
            findForm->setObjectName(QStringLiteral("findForm"));
        findForm->resize(321, 274);
        centralwidget = new QWidget(findForm);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(87, 18, 126, 37));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(12, 84, 55, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(8, 119, 55, 16));
        name = new QLineEdit(centralwidget);
        name->setObjectName(QStringLiteral("name"));
        name->setGeometry(QRect(98, 81, 113, 22));
        surname = new QLineEdit(centralwidget);
        surname->setObjectName(QStringLiteral("surname"));
        surname->setGeometry(QRect(95, 119, 116, 22));
        ok = new QPushButton(centralwidget);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(11, 187, 93, 28));
        findForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(findForm);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 321, 26));
        findForm->setMenuBar(menubar);
        statusbar = new QStatusBar(findForm);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        findForm->setStatusBar(statusbar);

        retranslateUi(findForm);

        QMetaObject::connectSlotsByName(findForm);
    } // setupUi

    void retranslateUi(QMainWindow *findForm)
    {
        findForm->setWindowTitle(QApplication::translate("findForm", "MainWindow", 0));
        label->setText(QApplication::translate("findForm", "Find", 0));
        label_2->setText(QApplication::translate("findForm", "Name", 0));
        label_3->setText(QApplication::translate("findForm", "Surname", 0));
        ok->setText(QApplication::translate("findForm", "Find", 0));
    } // retranslateUi

};

namespace Ui {
    class findForm: public Ui_findForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDFORM_H
