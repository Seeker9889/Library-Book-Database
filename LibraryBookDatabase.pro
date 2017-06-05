#-------------------------------------------------
#
# Project created by QtCreator 2016-11-08T11:47:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LibraryBookDatabase
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    book.cpp \
    datarecord.cpp

HEADERS  += mainwindow.h \
    book.h \
    datarecord.h \
    internalvariables.h

FORMS    += mainwindow.ui
