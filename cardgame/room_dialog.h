#ifndef ROOM_DIALOG_H
#define ROOM_DIALOG_H

#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QCloseEvent>
#include <QMessageBox>
#include <QCursor>
#include <QMouseEvent>
#include <QPoint>
#include <QCursor>
#include "card.h"
namespace Ui {
class room_Dialog;
}

class room_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit room_Dialog(QWidget *parent = 0);
    ~room_Dialog();

public slots:
    void slot_setroomInfo(int player_id, int enemy_id,int playerlife,int enemylife,int room_id);
    void closeEvent(QCloseEvent * event);

signals:
    void SIG_close();

public:
    Ui::room_Dialog *   ui;
    QVBoxLayout*        my_boxlayout;//用户布局对象
    QVBoxLayout*        my_boxlayout2;
    QVBoxLayout*        my_boxlayout3;
    QVBoxLayout*        my_boxlayout4;
    int                 playerid;
    int                 enemyid;
    int                 roomid;
    int                 player_life;
    int                 enemy_life;
    std::map<int,card*> MAP_Player_CardList;
    std::map<int,card*> MAP_Enemy_CardList;
    int                 List_player_cardList[5];
    int                 List_enemy_cardList[5];
    int                 player_handcard_num;
    int                 enemy_handcard_num;
    card*               player_using_card;
    card*               enemy_using_card;
    card*               player_fight_card;
    card*               enemy_fight_card;
    card*               player_handcard[5];
    card*               player_card[5];
    card*               enemy_handcard[5];
    card*               enemy_card[5];
private slots:
    void SLOT_player_getcard(card* mycard);

    void SLOT_enemy_getcard(card* mycard);
    //玩家出牌动作
    void slot_usercard();
    //玩家选择要出的牌
    void slot_cardselect();
    //敌人出牌动作
    void slot_enemycard();
    //玩家选择要出的牌
    void slot_enemycardselect();
    //卡牌销毁
    void slot_destroycard(QWidget* card);

    int SLOT_selectwinner();/////////传入两个用户对象,判断赢家

    void on_pb_exitroom_clicked();
    
    void slot_card_fight(card* card1,card* card2 );

    void slot_setenemy_fightcardList_Layout(QVBoxLayout* my_boxlayout);

    void slot_setenemy_handcardList_Layout(QVBoxLayout* my_boxlayout);

    void slot_setplayer_fightcardList_Layout(QVBoxLayout* my_boxlayout);

    void slot_setplayer_handcardList_Layout(QVBoxLayout* my_boxlayout);


public slots:
    void SLOT_clear();

};


#endif // ROOM_DIALOG_H
