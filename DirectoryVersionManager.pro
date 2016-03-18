#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T17:08:20
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DirectoryVersionManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    versionlistform.cpp \
    projectcreatingform.cpp \
    versiondetailsform.cpp \
    versioncreatingform.cpp \
    xmldata.cpp \
    Project.cpp \
    Version.cpp \
    Element.cpp

HEADERS  += mainwindow.h \
    versionlistform.h \
    projectcreatingform.h \
    versiondetailsform.h \
    versioncreatingform.h \
    xmldata.h \
    Project.h \
    Version.h \
    Element.h

FORMS    += mainwindow.ui \
    versionlistform.ui \
    projectcreatingform.ui \
    versiondetailsform.ui \
    versioncreatingform.ui
