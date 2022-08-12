#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H

#include <QDialog>
#include <QString>
#include <QSettings>//包含配置文件
#include <QFileInfo>
#include <QApplication>
#include <QInputDialog>
#include <QTime>
#include <QDebug>

#include "common.h"
#include "card.h"
#include "room_dialog.h"
#include "TcpClientMediator.h"
#include "packdef.h"
#include "login_dialog.h"
#include "md5.h"
#include "lobby_dialog.h"
#include "wait_dialog.h"
#include "fight_mode.h"
#include "set_user.h"
class game_Control;
//定义协议对应处理函数
typedef void (game_Control:: *PFUN)(uint,char*,int);


class game_Control : public QObject
{
    Q_OBJECT
public:
    static game_Control* create_game_Control();
    PFUN                my_netMap[DEF_PACK_COUNT];

    QString             server_IP;

    //核心类控制变量
    INetMediator*       myclient;
    room_Dialog*        my_room_Dialog;
    Login_Dialog*       my_login_dialog;
    lobby_dialog*       my_lobby_dialog;//大厅界面
    wait_dialog*        my_wait_dialog;
    set_user*           my_set_user;
    fight_mode_standard*         my_fight_mode_standard;


    std::vector<card*>  VEC_player_card;
    std::vector<card*>  VEC_enemy_card;

    //用户信息
    std::string         str_number;
    int                 user_id;
    int                 icon_id;
    QString             user_name;

private:
    explicit game_Control(QObject *parent = 0);
    ~game_Control();
    game_Control(const game_Control&){}
    //初始化协议映射表
    void set_netMap();
    //初始化配置文件
    void initConfig();
    //处理用户登陆回复
    void slot_dealLoginRS(uint socket, char *buf, int nlen);
    //处理用户注册回复
    void slot_delRegisterRS(uint socket, char *buf, int nlen);
    //处理加入房间回复
    void slot_deljoinroomRS(uint socket, char *buf, int nlen);
    //处理创建房间回复
    void slot_delcreateroomRS(uint socket, char *buf, int nlen);
    //处理用户信息提交
    void slot_delUserinfoRS(uint socket, char *buf, int nlen);
    //处理离开房间回复
    void slot_delleaveroomRS(uint socket, char *buf, int nlen);
    //处理房间成员请求
    void slot_del_roommem_RQ(uint socket, char *buf, int nlen);
    //回合开始
    void slot_round_start(uint socket, char *buf, int nlen);
    //回合结束
    void slot_round_over(uint socket, char *buf, int nlen);
    //加入对战后原界面处理
    void slot_afterroom();
    //向服务器发送数据
    void slot_SendData(unsigned int lSendIP, char *buf, int nlen);





signals:
    void SIG_setRoomInfo(int player_id, int enemy_id, int playerlife, int enemylife, int room_id);
public slots:
    //空间回收
    void slot_destroy();
    //登陆信息提交
    void slot_login_commit(QString,QString);
    //注册信息提交
    void slot_register_commit(QString,QString);
    //选择房间
    void slot_showroom();

    void slot_dealData(uint socket, char *buf, int nlen);
    
    void slot_createroom();

    void slot_joinroom();
    //显示用户信息界面
    void slot_setInfo();
    //提交用户信息更改
    void slot_userInfo_commit( int iconid, QString name);
    //离开游戏房间/认输请求
    void slot_leaveroom_RQ();
    //离开房间界面回收处理
    void slot_leaveroom();
    //返回模式选择界面
    void slot_return_lobby();   
};

#endif // GAME_CONTROL_H
