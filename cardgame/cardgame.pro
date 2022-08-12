#-------------------------------------------------
#
# Project created by QtCreator 2022-07-25T13:07:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cardgame
TEMPLATE = app


SOURCES += main.cpp\
        room_dialog.cpp \
    card.cpp \
    game_control.cpp \
    login_dialog.cpp \
    lobby_dialog.cpp \
    wait_dialog.cpp \
    fight_mode.cpp \
    set_user.cpp

HEADERS  += room_dialog.h \
    card.h \
    game_control.h \
    login_dialog.h \
    lobby_dialog.h \
    wait_dialog.h \
    fight_mode.h \
    set_user.h \
    common.h

FORMS    += room_dialog.ui \
    card.ui \
    login_dialog.ui \
    lobby_dialog.ui \
    wait_dialog.ui \
    set_user.ui


INCLUDEPATH +=  ./netapi/\
                ./MD5/\


include(./netapi/netapi.pri)
include(./MD5/MD5.pri)

DISTFILES +=

RESOURCES += \
    resources.qrc
