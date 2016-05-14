#-------------------------------------------------
#
# Project created by QtCreator 2016-05-14T19:34:50
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LoginForm
TEMPLATE = app


SOURCES += main.cpp\
        login.cpp \
    adminform.cpp \
    database.cpp \
    mainwindow.cpp

HEADERS  += login.h \
    adminform.h \
    database.h \
    mainwindow.h

FORMS    += login.ui \
    adminform.ui \
    mainwindow.ui
