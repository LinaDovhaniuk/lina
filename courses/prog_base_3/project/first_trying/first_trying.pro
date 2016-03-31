QT += gui
QT += sql
TARGET = demo03
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp
HEADERS += mainwindow.h

QT *= core gui widgets
