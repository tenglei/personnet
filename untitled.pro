#-------------------------------------------------
#
# Project created by QtCreator 2017-05-18T15:07:11
#
#-------------------------------------------------

QT       += core gui
QT       +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    initmysql.cpp \
    person.cpp \
    friends.cpp \
    wsexperience.cpp \
    friendarticle.cpp

HEADERS  += mainwindow.h \
    initmysql.h \
    person.h \
    friends.h \
    wsexperience.h \
    friendarticle.h

FORMS    += mainwindow.ui \
    person.ui \
    friends.ui \
    wsexperience.ui \
    friendarticle.ui

RESOURCES += \
    background.qrc

DISTFILES += \
    C:/Users/tenglei/Desktop/background.png
