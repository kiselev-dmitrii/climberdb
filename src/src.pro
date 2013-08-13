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
    ProductsFilter.cpp \
    MainSoldList.cpp \
    SoldProductsView.cpp \
    TableView.cpp \
    Utils.cpp \
    CreateConsignmentDialog.cpp \
    EditConsignmentDialog.cpp

HEADERS  += MainWindow.h \
    ProductsView.h \
    Database.h \
    MainProductList.h \
    ProductsFilter.h \
    MainSoldList.h \
    SoldProductsView.h \
    TableView.h \
    Utils.h \
    EditConsignmentDialog.h \
    CreateConsignmentDialog.h

FORMS    += MainWindow.ui \
    EditConsignmentDialog.ui \
    CreateConsignmentDialog.ui
