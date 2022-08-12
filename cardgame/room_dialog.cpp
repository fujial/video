#include "room_dialog.h"
#include "ui_room_dialog.h"

room_Dialog::room_Dialog(QWidget *parent) :
    QDialog(parent),player_using_card(NULL),enemy_using_card(NULL),player_handcard_num(5),enemy_handcard_num(5),
    player_fight_card(NULL),enemy_fight_card(NULL),
    ui(new Ui::room_Dialog)
{
    ui->setupUi(this);
    //this->setWindowFlags( Qt::FramelessWindowHint );
    my_boxlayout  = new QVBoxLayout;
    my_boxlayout2 = new QVBoxLayout;
    my_boxlayout3 = new QVBoxLayout;
    my_boxlayout4 = new QVBoxLayout;
    for(int i =0 ; i < 5; i++){
        List_enemy_cardList[i] = 0;
        List_player_cardList[i] = 0;
    }
    for(int i = 0; i < 5; i++){
        player_handcard[i] = new card;
        SLOT_player_getcard(player_handcard[i]);
        player_handcard[i]->set_cardOwner(playerid);
        connect(player_handcard[i],SIGNAL(sig_cardselect()),
                this,SLOT(slot_cardselect()) );
        connect(player_handcard[i],SIGNAL(sig_usecard()),
                this,SLOT(slot_usercard()) );
    }
    for(int i = 5; i < 10; i++){
        enemy_handcard[i] = new card;
        SLOT_enemy_getcard(enemy_handcard[i]);
        enemy_handcard[i]->set_cardOwner(enemyid);
        connect(enemy_handcard[i],SIGNAL(sig_cardselect() ),
                this,SLOT(slot_enemycardselect()));
        connect(enemy_handcard[i],SIGNAL(sig_usecard()),
                this,SLOT(slot_enemycard()));
    }

    //玩家卡牌列表设置垂直布局
    slot_setenemy_fightcardList_Layout(my_boxlayout4);
    slot_setenemy_handcardList_Layout(my_boxlayout2);
    slot_setplayer_fightcardList_Layout(my_boxlayout3);
    slot_setplayer_handcardList_Layout(my_boxlayout);
    //初始化房间信息
    slot_setroomInfo(0,0,30,30,0);

}

room_Dialog::~room_Dialog()
{
    delete ui;
}

//玩家使用卡牌
void room_Dialog::SLOT_player_getcard(card* mycard)
{
    mycard->set_cardInfo(3,3,4,playerid);

    my_boxlayout->addWidget(mycard);
}

//敌人获取卡牌
void room_Dialog::SLOT_enemy_getcard(card *mycard)
{
    mycard->set_cardInfo(3,3,4,enemyid);

    my_boxlayout2->addWidget(mycard);
}



void room_Dialog::slot_destroycard(QWidget *card)
{
    card->hide();
    delete card;
    card = NULL;
}
//初始化房间信息
void room_Dialog::slot_setroomInfo(int player_id, int enemy_id, int playerlife, int enemylife, int room_id)
{
    if(player_id != 0){
        playerid = player_id;
        ui->lb_playerid->setText(QString("id:%1").arg(player_id));
    }
    if(enemy_id != 0){
        enemyid = enemy_id;
        ui->lb_enemyid->setText(QString("id:%1").arg(enemy_id));
    }
    if(playerlife != 0){
        player_life = playerlife;
    }
    if(enemylife != 0){
        enemy_life = enemylife;
    }
    if(room_id != 0){
        roomid = room_id;
        ui->lb_roomid->setText(QString("房间号%1").arg(roomid));
    }
}

//重写关闭事件
void room_Dialog::closeEvent(QCloseEvent *event)
{
    if( QMessageBox::question(this,"提示","是否关闭") == QMessageBox::Yes){
        Q_EMIT SIG_close();
    }
    else{
        event->ignore();//忽略
    }
}

int room_Dialog::SLOT_selectwinner()
{
    if(enemy_life == 0)
        return 0;
}
//投降按钮
void room_Dialog::on_pb_exitroom_clicked()
{
    if( QMessageBox::question(this,"提示","确认投降？") == QMessageBox::Yes ){
        Q_EMIT SIG_close();
    }
    else{

    }
}

void room_Dialog::SLOT_clear()
{
    playerid =0;
    enemyid = 0;
    player_life = 0;
    enemy_life = 0;
    roomid = 0;
}

////鼠标按下
//void room_Dialog::mousePressEvent(QMouseEvent *event)
//{
//    int x=this->mapFromGlobal(QCursor().pos()).x();
//    int y=this->mapFromGlobal(QCursor().pos()).y();
//    if(x >= 840 && x <= 960){
//        slot_cardselect(x,y);
//    }
//    else if(x >= 0 && x <= 120){
//        slot_enemycardselect(x,y);
//    }
//}

////鼠标放松
//void room_Dialog::mouseReleaseEvent(QMouseEvent *event)
//{
//    int x=this->mapFromGlobal(QCursor().pos()).x();
//    int y=this->mapFromGlobal(QCursor().pos()).y();
//    if(x <= 840 && x >= 720 ){
//        slot_usercard(x,y);
//    }
//    else if(x <= 240 && x >= 120){
//        slot_enemycard(x,y);
//    }
//}


//玩家选择卡牌
void room_Dialog::slot_cardselect()
{
    int x=this->mapFromGlobal(QCursor().pos()).x();
    if(x <= 960 && x >= 840)
        player_using_card = qobject_cast<card*>(sender());
    if(x < 840 && x >= 720 )
        player_fight_card = qobject_cast<card*>(sender());;
//    if(!player_using_card)
//        qDebug() << "!player_using_card";
}

//敌人选择卡牌
void room_Dialog::slot_enemycardselect()
{
    int x=this->mapFromGlobal(QCursor().pos()).x();
    //qDebug() << "slot_enemycardselect";
    if(x <= 120 && x >= 0)
        enemy_using_card = qobject_cast<card*>(sender());
    if(x <= 240 && x >=120)
        enemy_fight_card = qobject_cast<card*>(sender());
}

//玩家出牌动作
void room_Dialog::slot_usercard()
{
    //qDebug() << "slot_usercard";
    int x=this->mapFromGlobal(QCursor().pos()).x();
    if(x <= 840 && x >= 720 && player_using_card!=NULL){
        my_boxlayout3->addWidget(player_using_card );

    }
    else if(x <= 240 && x >= 120 && player_using_card!=NULL){
        qDebug() <<"card fight";
        enemy_fight_card = qobject_cast<card*>(sender());
        if(enemy_fight_card != NULL)
            slot_card_fight(player_fight_card,enemy_fight_card);
    }
    else{

    }
}

//敌人出牌
void room_Dialog::slot_enemycard()
{
    //qDebug() << "slot_enemycard";
    int x=this->mapFromGlobal(QCursor().pos()).x();
    if(x <= 240 && x >= 120 && enemy_using_card!=NULL){
        my_boxlayout4->addWidget(enemy_using_card );
    }
    else if(x <= 840 && x >= 720 && enemy_using_card != NULL ){
        qDebug() << "card fight";
        player_fight_card = qobject_cast<card*>(sender());
        if(player_fight_card != NULL)
            slot_card_fight(enemy_fight_card,player_fight_card);
    }
    else{

    }
}

void room_Dialog::slot_card_fight(card *card1, card *card2)
{
    //攻击次数不为0，攻击次数减一，方便未来设计可以多次攻击的卡牌
    int ATK_num = card1->get_cardATKnum();
    if(ATK_num!=0){
        --ATK_num;
    }
    else{
        QMessageBox::about(this,"提示","该卡牌现在无法攻击");
    }
    card1->set_cardATKnum(ATK_num);

}

void room_Dialog::slot_setenemy_fightcardList_Layout(QVBoxLayout *my_boxlayout)
{
    ui->wdg_enemy_fight_cardshow->setLayout(my_boxlayout);
}

void room_Dialog::slot_setenemy_handcardList_Layout(QVBoxLayout *my_boxlayout)
{
    ui->wdg_enemy_cardshow->setLayout(my_boxlayout);
}

void room_Dialog::slot_setplayer_fightcardList_Layout(QVBoxLayout *my_boxlayout)
{
    ui->wdg_player_fight_cardshow->setLayout(my_boxlayout);
}

void room_Dialog::slot_setplayer_handcardList_Layout(QVBoxLayout *my_boxlayout)
{
    ui->wdg_player_cardshow->setLayout(my_boxlayout);
}
