#-------------------------------------------------
#
# Project created by QtCreator 2013-07-28T23:09:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        MainWindow.cpp \
    ProductsView.cpp \
    Database.cpp \
    MainProductList.cpp \
    ProductsFilter.cpp

HEADERS  += MainWindow.h \
    ProductsView.h \
    Database.h \
    MainProductList.h \
    ProductsFilter.h

FORMS    += MainWindow.ui
