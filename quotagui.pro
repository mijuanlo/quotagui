#-------------------------------------------------
#
# Project created by QtCreator 2019-02-06T10:24:01
#
#-------------------------------------------------

unix|win32: CONFIG   += c++1z
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = quotagui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# N4D validator debug msgs
#DEFINES += _N4D_DEBUG_

# N4D result messages received into gui
#DEFINES += N4D_SHOW_RESULT

# INFO ABOUT RUNNING THREADS & DELETION
#DEFINES += RUNNING_THREADS

# all qDebug() messages
#CONFIG += qt warn_off release
#DEFINES += QT_NO_DEBUG_OUTPUT QT_NO_WARNING_OUTPUT
#DEFINES += QT_NO_DEBUG

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    n4d.cpp

HEADERS += \
        mainwindow.h \
    n4d.h

FORMS += \
        mainwindow.ui

#DISTFILES += \
#    banner.png \
#    configured.png

RESOURCES += \
    resources.qrc

unix|win32: LIBS += -lxmlrpc++ -lxmlrpc -lxmlrpc_xmlparse -lxmlrpc_xmltok -lxmlrpc_util -lxmlrpc_client++
