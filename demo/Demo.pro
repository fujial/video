#-------------------------------------------------
#
# Project created by QtCreator 2022-05-31T14:29:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo
TEMPLATE = app


SOURCES += main.cpp\
    ccontrol.cpp \
    login_dialog.cpp \
    roomdialog.cpp \
    dialog.cpp \
    my_usershow.cpp \
    set_user.cpp

HEADERS  += \
    ccontrol.h \
    login_dialog.h \
    roomdialog.h \
    dialog.h \
    my_usershow.h \
    set_user.h

FORMS    += \
    login_dialog.ui \
    roomdialog.ui \
    dialog.ui \
    my_usershow.ui \
    set_user.ui

INCLUDEPATH += ./netapi/\
            ./MD5/\
            ./uiapi/\
            ./AudioApi/\
            ./VideoApi/


include(./netapi/netapi.pri)
include(./MD5/MD5.pri)
include(./uiapi/uiapi.pri)
include(./AudioApi/audioapi.pri)
include(./VideoApi/videoapi.pri)
RESOURCES += \
    resources.qrc

DISTFILES +=
