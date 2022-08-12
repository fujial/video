#include "game_control.h"

#define NetMap(x) my_netMap[ x - DEF_PACK_BASE]//宏替换协议选择函数
//单例模式创造游戏控制者
game_Control *game_Control::create_game_Control()
{
    static game_Control my_control;
    return &my_control;
}

game_Control::game_Control(QObject *parent) : QObject(parent)
{
    //初始化网络映射函数
    set_netMap();
    //初始化ip
    game_Control::initConfig();


    //my_room_Dialog  = new room_Dialog;
    myclient        = new TcpClientMediator;
    my_login_dialog = new Login_Dialog;
    my_lobby_dialog = new lobby_dialog;
    my_wait_dialog  = new wait_dialog;
    my_set_user     = new set_user;
    //信号槽关联

    connect(myclient,SIGNAL(SIG_ReadyData(uint,char*,int)),
            this,SLOT(slot_dealData(uint,char*,int)));
    connect(my_login_dialog,SIGNAL(SIG_close()),
            this,SLOT(slot_destroy()));
    connect(my_login_dialog,SIGNAL(SIG_login_commit(QString,QString)),
            this , SLOT(slot_login_commit(QString,QString)));
    connect( my_login_dialog,SIGNAL(SIG_register_commit(QString,QString)),
             this,SLOT(slot_register_commit(QString,QString)));
    connect( my_lobby_dialog,SIGNAL(SIG_close()),
             this,SLOT(slot_destroy()));
    connect( my_lobby_dialog,SIGNAL(SIG_showroom()),
             this,SLOT(slot_showroom()));
    connect( my_lobby_dialog,SIGNAL(SIG_UserInfo()),
             this,SLOT(slot_setInfo()) );
    connect( my_wait_dialog,SIGNAL(SIG_createroom()),
             this,SLOT(slot_createroom()) );
    connect( my_wait_dialog,SIGNAL(SIG_joinroom()),
             this,SLOT(slot_joinroom()) );
    connect( my_wait_dialog,SIGNAL(SIG_close()),
             this,SLOT(slot_destroy()) );
    connect( my_wait_dialog,SIGNAL(SIG_return()),
             this ,SLOT(slot_return_lobby()) );
    connect( my_set_user,SIGNAL(SIG_Setuser_Commit(int,QString)),
             this,SLOT(slot_userInfo_commit(int,QString)));


    //客户端连接服务器
    myclient->OpenNet(server_IP.toStdString().c_str());
    my_login_dialog->show();


}
//初始化协议映射
void game_Control::set_netMap()
{
    memset(my_netMap,0,sizeof(PFUN));
    NetMap(DEF_PACK_LOGIN_RS)       = &game_Control::slot_dealLoginRS;
    NetMap(DEF_PACK_REGISTER_RS)    = &game_Control::slot_delRegisterRS;
    NetMap(DEF_PACK_CREATEROOM_RS)  = &game_Control::slot_delcreateroomRS;
    NetMap(DEF_PACK_JOINROOM_RS)    = &game_Control::slot_deljoinroomRS;
    NetMap(DEF_PACK_USER_INFO)      = &game_Control::slot_delUserinfoRS;
    NetMap(DEF_PACK_ROOM_MEMBER)    = &game_Control::slot_del_roommem_RQ;
    NetMap(DEF_PACK_LEAVEROOM_RS)   = &game_Control::slot_delleaveroomRS;
}

//根据服务器回复数据判断协议种类,同一个协议可以绑定多个处理函数
void game_Control::slot_dealData(uint socket, char *buf, int nlen)
{
    int type = *(int*)buf;
    if(type >= DEF_PACK_BASE && type <= DEF_PACK_BASE+DEF_PACK_COUNT){
        PFUN pf = NetMap(type);
        if(pf)
            (this->*pf)(socket,buf,nlen);

    }
    delete[] buf;
}


//初始化配置文件，读取ip
void game_Control::initConfig()
{
    server_IP = _DEF_SERVER_IP;
    //设置配置文件目录
    QString path = QApplication::applicationDirPath() + "/config.ini";
    QFileInfo info(path);
    QSettings settings(path, QSettings::IniFormat, NULL);

    if(info.exists()){
        //配置文件存在，找到组
        settings.beginGroup("Net");
        QVariant ip = settings.value("ip");
        QString strIP = ip.toString();
        settings.endGroup();
        if(strIP.isEmpty()){
            server_IP = strIP;
        }
    }
    else{
        //配置文件不存在要找的组，写入默认ip
        settings.beginGroup("Net");
        //键值对方式设置ip
        settings.setValue("ip",server_IP);
        settings.endGroup();
    }
    qDebug() << server_IP;
}

//空间回收
void game_Control::slot_destroy()
{
    //为了复用考虑，可以写成传参形式，根据传入参数决定回收哪些变量
    if(my_room_Dialog){
        delete my_room_Dialog;
        my_room_Dialog = NULL;
    }
    if(myclient){
        delete myclient;
        myclient = NULL;
    }
    if(my_login_dialog){
        delete my_login_dialog;
        my_login_dialog = NULL;
    }
    if(my_lobby_dialog){
        delete my_lobby_dialog;
        my_lobby_dialog = NULL;
    }
    if(my_wait_dialog){
        delete my_wait_dialog;
        my_wait_dialog = NULL;
    }
}

//房间选择
void game_Control::slot_showroom()
{
    my_wait_dialog->show();
    my_lobby_dialog->hide();
}


//显示用户信息
void game_Control::slot_setInfo()
{
    my_set_user->show();
}


//离开房间空间回收
void game_Control::slot_leaveroom()
{
    my_wait_dialog->show();
    my_room_Dialog->SLOT_clear();
    my_room_Dialog->hide();
    delete my_room_Dialog;
    my_room_Dialog = NULL;
}

//返回模式选择界面
void game_Control::slot_return_lobby()
{
    my_wait_dialog->hide();
    my_lobby_dialog->show();
}

//
game_Control::~game_Control()
{
    slot_destroy();
}
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------信息提交------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
//登陆信息提交
void game_Control::slot_login_commit(QString number, QString password)
{
    std::string str_number      =   number.toStdString();
    //MD5加密
    MD5 md5(password.toStdString());
    std::string str_password    =   md5.toString();
    STRU_LOGIN_RQ rq;
    strcpy(rq.tel, str_number.c_str());
    strcpy(rq.password,str_password.c_str());
    slot_SendData(0,(char*)&rq,sizeof(rq));
}

//注册信息提交
void game_Control::slot_register_commit(QString number, QString password)
{
    std::string str_number      =   number.toStdString();
    MD5 md5(password.toStdString());
    std::string str_password    =   md5.toString();
    //std::string str_password    =   GetMD5(password);
    //写入协议包
    STRU_REGISTER_RQ rq;
    strcpy(rq.tel, str_number.c_str());
    strcpy(rq.password, str_password.c_str());

    slot_SendData(0,(char*)&rq,sizeof(rq));
}


//数据发送接口
void game_Control::slot_SendData(unsigned int lSendIP, char *buf, int nlen)
{
    myclient->SendData(lSendIP,buf,nlen);
}



//创建游戏房间
void game_Control::slot_createroom()
{
    STRU_CREATEROOM_RQ rq;
    rq.m_UserID = user_id;
    slot_SendData(0,(char*)&rq,sizeof(rq));
}

//加入游戏房间
void game_Control::slot_joinroom()
{
    if(!my_fight_mode_standard){
        my_fight_mode_standard = new fight_mode_standard;
    }
    int roomid = QInputDialog::getInt(this->my_wait_dialog,"加入房间","房间号");
    if((roomid <= 0)||(roomid > 999999)){
        QMessageBox::about(this->my_wait_dialog,"提示","房间号错误");
        return;
    }
    STRU_JOINROOM_RQ rq;
    rq.m_UserID = user_id;
    rq.m_RoomID = roomid;
    slot_SendData(0,(char*)&rq,sizeof(rq));
}

//用户信息提交
void game_Control::slot_userInfo_commit(int iconid, QString name)
{
    icon_id = iconid;
    user_name = name;
    std::string strName = name.toStdString();
    STRU_USER_INFO_RQ rq;
    qDebug() <<"iconid" << iconid;
    qDebug() << "name" << name;
    rq.m_iconid = iconid;
    rq.m_UserID = user_id;
    strcpy(rq.m_szUser,strName.c_str());
    slot_SendData(0,(char*)&rq,sizeof(rq));
    QMessageBox::about(this->my_lobby_dialog,"提示","设置成功");

}

//离开房间数据发送
void game_Control::slot_leaveroom_RQ()
{
    STRU_LEAVEROOM_RQ rq;
    rq.loserid = user_id;
    if(rq.loserid != my_room_Dialog->enemyid)
        rq.winnerid = my_room_Dialog->enemyid;
    else{
        rq.winnerid = my_room_Dialog->playerid;
    }
    rq.m_RoomId = my_room_Dialog->roomid;
    slot_leaveroom();
    slot_SendData(0,(char*)&rq,sizeof(rq));
}


//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------接收数据处理--------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------

//处理登陆回复
void game_Control::slot_dealLoginRS(uint socket, char *buf, int nlen)
{
    STRU_LOGIN_RS *rs = (STRU_LOGIN_RS*)buf;
    switch(rs->result){
    case user_not_exist:
        QMessageBox::about(this->my_login_dialog,"提示","用户名不存在");
        break;
    case password_error:
        QMessageBox::about(this->my_login_dialog,"提示","密码错误");
        break;
    case login_success:
        QMessageBox::about(this->my_login_dialog,"提示","登陆成功");
        user_id = rs->userid;
        my_login_dialog->hide();
        my_lobby_dialog->slot_setUserInfo(icon_id,user_id,user_name);
        my_lobby_dialog->show();
        break;
    }
}

//处理注册信息回复
void game_Control::slot_delRegisterRS(uint socket, char *buf, int nlen)
{
    STRU_REGISTER_RS *rs = (STRU_REGISTER_RS*)buf;
    switch(rs ->result){
        case tel_is_exist:
            QMessageBox::about(this->my_login_dialog,"提示","用户已存在");
        break;
        case register_success:
            QMessageBox::about(this->my_login_dialog,"提示","创建成功");
        break;
    }
}

//处理加入房间回复
void game_Control::slot_deljoinroomRS(uint socket, char *buf, int nlen)
{


    STRU_JOINROOM_RS* rs = (STRU_JOINROOM_RS*)buf;
    switch(rs->m_lResult){
    case room_no_exist:
        QMessageBox::about(this->my_wait_dialog,"提示","房间不存在");
        break;
    case room_max:
        QMessageBox::about(this->my_wait_dialog,"提示","房间人数已满");
        break;
    case join_success:
        QMessageBox::about(this->my_wait_dialog,"提示","加入房间成功");
        my_room_Dialog = new room_Dialog;
        connect( this, SIGNAL(SIG_setRoomInfo(int,int,int,int,int)),
                 my_room_Dialog,SLOT(slot_setroomInfo(int,int,int,int,int)));
        connect( my_room_Dialog,SIGNAL(SIG_close()),
                 this,SLOT(slot_leaveroom_RQ()) );
        connect( my_room_Dialog,SIGNAL(SIG_close()),
                 this,SLOT(slot_leaveroom()) );
        Q_EMIT SIG_setRoomInfo(rs->playerid,user_id,30,30,rs->m_RoomID);
        slot_afterroom();
        my_room_Dialog->show();
        break;
    }

}

//处理创建房间回复
void game_Control::slot_delcreateroomRS(uint socket, char *buf, int nlen)
{
    STRU_CREATEROOM_RS* rs = (STRU_CREATEROOM_RS*)buf;
    //根据对战模式创建相应的房间类,记得回收
    my_room_Dialog = new room_Dialog;
    connect( this, SIGNAL(SIG_setRoomInfo(int,int,int,int,int)),
             my_room_Dialog,SLOT(slot_setroomInfo(int,int,int,int,int)));
    connect( my_room_Dialog,SIGNAL(SIG_close()),
             this,SLOT(slot_leaveroom_RQ()) );
    connect( my_room_Dialog,SIGNAL(SIG_close()),
             this,SLOT(slot_leaveroom()) );
    //目前只有一种模式，后续会扩展多种模式，更改创建房间请求，增加一个变量存放创建房间模式的种类
    //服务器发送应答报文时携带对应模式，将创建对应类进行封装，根据不同请求确定不同变量是否
    my_fight_mode_standard = new fight_mode_standard();
    my_fight_mode_standard->roomid = rs->m_RoomId;

    my_fight_mode_standard->playerid = user_id;
    my_room_Dialog->roomid = rs->m_RoomId;
    my_room_Dialog->playerid = user_id;
    //根据模式的不同传入不同的参数，应该将对手的信息存入到回复报文中发送回来
    //不同的英雄根据技能强弱可以设置不同的初始血量
    Q_EMIT SIG_setRoomInfo(user_id,0,30,30,rs->m_RoomId);
    my_room_Dialog->show();
    slot_afterroom();
    slot_round_over(socket,buf,nlen);

}

//用户信息接收
void game_Control::slot_delUserinfoRS(uint socket, char *buf, int nlen)
{
    STRU_USER_INFO_RQ *rq = (STRU_USER_INFO_RQ*)buf;
    user_name = QString::fromStdString(rq->m_szUser);
    icon_id = rq->m_iconid;
    my_set_user->slot_setInfo(rq->m_iconid,user_name);
    my_lobby_dialog->slot_setUserInfo(rq->m_iconid,user_id,rq->m_szUser);
}

//处理离开房间请求回复
void game_Control::slot_delleaveroomRS(uint socket, char *buf, int nlen)
{
    QMessageBox::about(my_room_Dialog,"提示","你赢了");

    slot_leaveroom();
}

//处理加入房间成员回复
void game_Control::slot_del_roommem_RQ(uint socket, char *buf, int nlen)
{
    STRU_ROOM_MEMBER_RQ* rq = (STRU_ROOM_MEMBER_RQ*)buf;
    //用户显示
    my_room_Dialog->slot_setroomInfo(rq->m_UserID,rq->m_enemyid,0,0,0);
    QMessageBox::about(my_room_Dialog,"提示","有玩家加入房间");

    //这部分是为了实现断线重连，暂时还没有实现，先简单说一下思路
    //用户登陆之后，服务器会检测该用户是否又未完成的对局（服务器端是否有相应用户id对应的对局信息），
    //如果有，服务器发送相应的对局信息同步给登陆的用户，严格来说这部分应该在登陆时实现，服务器调用
    //查询函数

    //如果用户已经存在

}

//回合开始接收信息
void game_Control::slot_round_start(uint socket, char *buf, int nlen)
{
    int type = DEF_PACK_ROUND_START;
}

//回合结束发送信息
void game_Control::slot_round_over(uint socket, char *buf, int nlen)
{
    qDebug() << "round over";
    int type = DEF_PACK_ROUND_END;
    int userid = user_id;
    QVBoxLayout*        my_boxlayout = my_room_Dialog->my_boxlayout; //用户布局对象
//    QVBoxLayout*        my_boxlayout2= my_room_Dialog->my_boxlayout2;
//    QVBoxLayout*        my_boxlayout3= my_room_Dialog->my_boxlayout3;
//    QVBoxLayout*        my_boxlayout4= my_room_Dialog->my_boxlayout4;
    int size = sizeof(*my_boxlayout);
    char* my_buf = new char[sizeof(QVBoxLayout) + 2*sizeof(int)];
    *(int*)my_buf = type;
    my_buf += sizeof(int);
    *(int*)my_buf = userid;
    my_buf += sizeof(int);
    memcpy(my_buf,my_boxlayout,sizeof(QVBoxLayout));
    qDebug() << size;
//    size += sizeof(*my_boxlayout2);
//    qDebug() << size;
//    size += sizeof(*my_boxlayout3);
//    qDebug() << size;
//    size += sizeof(*my_boxlayout4);
//    qDebug() << size;
    slot_SendData(0,my_buf,sizeof(QVBoxLayout) + 2*sizeof(int));
}

//进入房间后原房间处理
void game_Control::slot_afterroom()
{
    my_lobby_dialog->hide();
    my_wait_dialog->hide();
}

//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
