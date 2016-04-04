#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T17:08:20
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DirectoryVersionManager
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    versionlistform.cpp \
    projectcreatingform.cpp \
    versiondetailsform.cpp \
    versioncreatingform.cpp \
    Project.cpp \
    Version.cpp \
    Element.cpp \
    Reader.cpp \
    XmlIO.cpp \
    filemover.cpp \
    addnewfolderform.cpp

HEADERS  += mainwindow.h \
    versionlistform.h \
    projectcreatingform.h \
    versiondetailsform.h \
    versioncreatingform.h \
    Project.h \
    Version.h \
    Element.h \
    Reader.h \
    XmlIO.h \
    filemover.h \
    addnewfolderform.h

FORMS    += mainwindow.ui \
    versionlistform.ui \
    projectcreatingform.ui \
    versiondetailsform.ui \
    versioncreatingform.ui \
    addnewfolderform.ui
