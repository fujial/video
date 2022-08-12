/********************************************************************************
** Form generated from reading UI file 'room_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOM_DIALOG_H
#define UI_ROOM_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_room_Dialog
{
public:
    QWidget *wdg_enemy;
    QPushButton *pb_enemy_headshot;
    QPushButton *pb_enemy_skill;
    QScrollArea *SA_enemy_cardlist;
    QWidget *wdg_enemy_cardshow;
    QLabel *lb_enemyid;
    QWidget *wdg_player;
    QPushButton *pb_player_headshot;
    QPushButton *pb_player_skill;
    QScrollArea *SA_player_cardlist;
    QWidget *wdg_player_cardshow;
    QLabel *lb_playerid;
    QWidget *wdg_fight;
    QLabel *lb_roomid;
    QPushButton *pb_exitroom;
    QScrollArea *SA_enemy_cardlist_2;
    QWidget *wdg_enemy_fight_cardshow;
    QScrollArea *SA_player_cardlist_2;
    QWidget *wdg_player_fight_cardshow;

    void setupUi(QDialog *room_Dialog)
    {
        if (room_Dialog->objectName().isEmpty())
            room_Dialog->setObjectName(QStringLiteral("room_Dialog"));
        room_Dialog->resize(960, 720);
        room_Dialog->setMinimumSize(QSize(960, 720));
        room_Dialog->setMaximumSize(QSize(960, 720));
        wdg_enemy = new QWidget(room_Dialog);
        wdg_enemy->setObjectName(QStringLiteral("wdg_enemy"));
        wdg_enemy->setGeometry(QRect(0, 0, 120, 720));
        wdg_enemy->setMinimumSize(QSize(120, 720));
        wdg_enemy->setMaximumSize(QSize(120, 720));
        pb_enemy_headshot = new QPushButton(wdg_enemy);
        pb_enemy_headshot->setObjectName(QStringLiteral("pb_enemy_headshot"));
        pb_enemy_headshot->setGeometry(QRect(0, 0, 120, 60));
        pb_enemy_skill = new QPushButton(wdg_enemy);
        pb_enemy_skill->setObjectName(QStringLiteral("pb_enemy_skill"));
        pb_enemy_skill->setGeometry(QRect(0, 60, 60, 30));
        SA_enemy_cardlist = new QScrollArea(wdg_enemy);
        SA_enemy_cardlist->setObjectName(QStringLiteral("SA_enemy_cardlist"));
        SA_enemy_cardlist->setGeometry(QRect(0, 120, 120, 600));
        SA_enemy_cardlist->setMinimumSize(QSize(120, 600));
        SA_enemy_cardlist->setMaximumSize(QSize(120, 600));
        SA_enemy_cardlist->setWidgetResizable(true);
        wdg_enemy_cardshow = new QWidget();
        wdg_enemy_cardshow->setObjectName(QStringLiteral("wdg_enemy_cardshow"));
        wdg_enemy_cardshow->setGeometry(QRect(0, 0, 118, 598));
        SA_enemy_cardlist->setWidget(wdg_enemy_cardshow);
        lb_enemyid = new QLabel(wdg_enemy);
        lb_enemyid->setObjectName(QStringLiteral("lb_enemyid"));
        lb_enemyid->setGeometry(QRect(60, 60, 60, 30));
        wdg_player = new QWidget(room_Dialog);
        wdg_player->setObjectName(QStringLiteral("wdg_player"));
        wdg_player->setGeometry(QRect(840, 0, 120, 720));
        pb_player_headshot = new QPushButton(wdg_player);
        pb_player_headshot->setObjectName(QStringLiteral("pb_player_headshot"));
        pb_player_headshot->setGeometry(QRect(0, 0, 120, 60));
        pb_player_skill = new QPushButton(wdg_player);
        pb_player_skill->setObjectName(QStringLiteral("pb_player_skill"));
        pb_player_skill->setGeometry(QRect(60, 60, 60, 30));
        SA_player_cardlist = new QScrollArea(wdg_player);
        SA_player_cardlist->setObjectName(QStringLiteral("SA_player_cardlist"));
        SA_player_cardlist->setGeometry(QRect(0, 120, 120, 600));
        SA_player_cardlist->setMinimumSize(QSize(120, 600));
        SA_player_cardlist->setMaximumSize(QSize(120, 600));
        SA_player_cardlist->setWidgetResizable(true);
        wdg_player_cardshow = new QWidget();
        wdg_player_cardshow->setObjectName(QStringLiteral("wdg_player_cardshow"));
        wdg_player_cardshow->setGeometry(QRect(0, 0, 118, 598));
        SA_player_cardlist->setWidget(wdg_player_cardshow);
        lb_playerid = new QLabel(wdg_player);
        lb_playerid->setObjectName(QStringLiteral("lb_playerid"));
        lb_playerid->setGeometry(QRect(0, 60, 60, 30));
        wdg_fight = new QWidget(room_Dialog);
        wdg_fight->setObjectName(QStringLiteral("wdg_fight"));
        wdg_fight->setGeometry(QRect(120, 0, 720, 720));
        wdg_fight->setMinimumSize(QSize(720, 720));
        wdg_fight->setMaximumSize(QSize(720, 720));
        lb_roomid = new QLabel(wdg_fight);
        lb_roomid->setObjectName(QStringLiteral("lb_roomid"));
        lb_roomid->setGeometry(QRect(300, 10, 120, 15));
        pb_exitroom = new QPushButton(wdg_fight);
        pb_exitroom->setObjectName(QStringLiteral("pb_exitroom"));
        pb_exitroom->setGeometry(QRect(540, 0, 60, 30));
        SA_enemy_cardlist_2 = new QScrollArea(wdg_fight);
        SA_enemy_cardlist_2->setObjectName(QStringLiteral("SA_enemy_cardlist_2"));
        SA_enemy_cardlist_2->setGeometry(QRect(0, 0, 120, 720));
        SA_enemy_cardlist_2->setMinimumSize(QSize(120, 720));
        SA_enemy_cardlist_2->setMaximumSize(QSize(120, 720));
        SA_enemy_cardlist_2->setWidgetResizable(true);
        wdg_enemy_fight_cardshow = new QWidget();
        wdg_enemy_fight_cardshow->setObjectName(QStringLiteral("wdg_enemy_fight_cardshow"));
        wdg_enemy_fight_cardshow->setGeometry(QRect(0, 0, 118, 718));
        SA_enemy_cardlist_2->setWidget(wdg_enemy_fight_cardshow);
        SA_player_cardlist_2 = new QScrollArea(wdg_fight);
        SA_player_cardlist_2->setObjectName(QStringLiteral("SA_player_cardlist_2"));
        SA_player_cardlist_2->setGeometry(QRect(600, 0, 120, 720));
        SA_player_cardlist_2->setMinimumSize(QSize(120, 720));
        SA_player_cardlist_2->setMaximumSize(QSize(120, 720));
        SA_player_cardlist_2->setWidgetResizable(true);
        wdg_player_fight_cardshow = new QWidget();
        wdg_player_fight_cardshow->setObjectName(QStringLiteral("wdg_player_fight_cardshow"));
        wdg_player_fight_cardshow->setGeometry(QRect(0, 0, 118, 718));
        SA_player_cardlist_2->setWidget(wdg_player_fight_cardshow);

        retranslateUi(room_Dialog);

        QMetaObject::connectSlotsByName(room_Dialog);
    } // setupUi

    void retranslateUi(QDialog *room_Dialog)
    {
        room_Dialog->setWindowTitle(QApplication::translate("room_Dialog", "room_Dialog", 0));
        pb_enemy_headshot->setText(QApplication::translate("room_Dialog", "\346\225\214\344\272\272\345\244\264\345\203\217", 0));
        pb_enemy_skill->setText(QApplication::translate("room_Dialog", "\346\225\214\344\272\272\346\212\200\350\203\275", 0));
        lb_enemyid->setText(QApplication::translate("room_Dialog", "\347\216\251\345\256\266", 0));
        pb_player_headshot->setText(QApplication::translate("room_Dialog", "\347\216\251\345\256\266\345\244\264\345\203\217", 0));
        pb_player_skill->setText(QApplication::translate("room_Dialog", "\347\216\251\345\256\266\346\212\200\350\203\275", 0));
        lb_playerid->setText(QApplication::translate("room_Dialog", "\347\216\251\345\256\266", 0));
        lb_roomid->setText(QApplication::translate("room_Dialog", "roomid", 0));
        pb_exitroom->setText(QApplication::translate("room_Dialog", "\346\212\225\351\231\215", 0));
    } // retranslateUi

};

namespace Ui {
    class room_Dialog: public Ui_room_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOM_DIALOG_H
