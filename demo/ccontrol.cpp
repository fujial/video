#include "ccontrol.h"

#define NetMap(x) my_netMap[ x - DEF_PACK_BASE]//宏替换协议选择函数
CControl *CControl::createControl()
{
    static CControl mycontrol;
    return & mycontrol;
}

//构造函数
CControl::CControl(QObject *parent) : QObject(parent),user_id(0),room_id(0)
{
    //初始化网络
    set_netMap();
    //初始化ip
    initConfig();
    my_login_dialog = new Login_Dialog ;
    myclient        = new TcpClientMediator;
    my_dialog       = new DemoDialog;
    my_roomdialog   = new RoomDialog;
    my_setuser      = new set_user;
    my_audioCollect = new Audio_collect;
    my_videoRead    = new video_read;
    my_deskread     = new video_show;
    connect(my_login_dialog,SIGNAL(SIG_close() ),
            this,SLOT(slot_destroy()));
    connect(my_dialog,SIGNAL(SIG_close()),
            this, SLOT(slot_destroy()));

    connect(myclient,SIGNAL(SIG_ReadyData(uint,char*,int)),
            this,SLOT(slot_dealDate(uint,char*,int)));

    connect(my_login_dialog,SIGNAL(SIG_login_commit(QString,QString)),
            this,SLOT(slot_login_commit(QString,QString)));
    connect(my_login_dialog,SIGNAL(SIG_register_commit(QString,QString)),
            this,SLOT(slot_register_commit(QString,QString)));

    connect(my_dialog,SIGNAL(SIG_joinRoom()),
            this,SLOT(slot_joinroom()));
    connect(my_dialog,SIGNAL(SIG_createRoom()),
            this,SLOT(slot_createroom()));

    connect(my_dialog,SIGNAL(SIG_setUser()),
            this,SLOT(slot_setuser()));

    connect(my_setuser,SIGNAL(SIG_Setuser_Commit(int,QString,QString)),
            this,SLOT(slot_Setuser_Commit(int,QString,QString)));

    connect(my_roomdialog,SIGNAL(SIG_quitRoom()),
            this,SLOT(slot_quit_room()) );

    connect(my_audioCollect,SIGNAL(SIG_audioFrame(QByteArray&)),
            this , SLOT(slot_SendAudioFrame(QByteArray&)));

    connect(my_videoRead,SIGNAL(SIG_videoShow(QImage&)),
            this, SLOT(slot_RefreshVideoFrame(QImage&)));

    connect(my_videoRead,SIGNAL(SIG_videoDate(QByteArray&)),
            this, SLOT(slot_SendVideoDate(QByteArray&)));

    connect(my_roomdialog,SIGNAL(SIG_audioOpen()),
            this,SLOT(slot_audioOpen()));

    connect(my_roomdialog,SIGNAL(SIG_audioClose()),
            this,SLOT(slot_audioClose()));

    connect(my_roomdialog,SIGNAL(SIG_videoOpen()),
            this,SLOT(slot_videoOpen()));

    connect(my_roomdialog,SIGNAL(SIG_videoClose()),
            this,SLOT(slot_videoClose()));

    connect(my_roomdialog,SIGNAL(SIG_deskshareOpen()),
            my_deskread,SLOT(start()));

    connect(my_roomdialog,SIGNAL(SIG_deskshareClose()),
            my_deskread,SLOT(pause()));

    connect( my_deskread,SIGNAL(SIG_screenFrame(QImage&)),
             this,SLOT(slot_RefreshVideoFrame(QImage&)));

    connect( my_deskread,SIGNAL(SIG_screenFrameData(QByteArray&)),
             this,SLOT(slot_SendVideoDate(QByteArray&)));


    myclient->OpenNet(server_IP.toStdString().c_str() );
    my_login_dialog->show();


}

static std::string GetMD5(QString str)
{
    std::string tmp = QString("%1_%2").arg(str).arg(MD5_KEY).toStdString();
    MD5 md5(tmp);
    return md5.toString();
}

//协议映射关系
void CControl::set_netMap()
{
    memset(my_netMap,0,sizeof(PFUN));
    NetMap(DEF_PACK_LOGIN_RS)       = &CControl::slot_dealLoginRS;
    NetMap(DEF_PACK_REGISTER_RS)    = &CControl::slot_dealRegisterRS;
    NetMap(DEF_PACK_JOINROOM_RS)    = &CControl::slot_del_joinroom_RS;
    NetMap(DEF_PACK_CREATEROOM_RS)  = &CControl::slot_del_createroom_RS;
    NetMap(DEF_PACK_ROOM_MEMBER)    = &CControl::slot_del_roommem_RQ;
    NetMap(DEF_PACK_USER_INFO)      = &CControl::slot_del_setInfo_RS;
    NetMap(DEF_PACK_LEAVEROOM_RQ)   = &CControl::slot_del_leaveroom_RQ;
    NetMap(DEF_PACK_AUDIO_FRAME)    = &CControl::slot_del_AudioFrame;
    NetMap(DEF_PACK_VIDEO_FRAME)    = &CControl::slot_del_VideoFrame;
}
//界面关闭
void CControl::slot_destroy()
{

    if(my_login_dialog){
        my_login_dialog->hide();//为了避免一直调用close形成死循环
        delete my_login_dialog;
        my_login_dialog = NULL;
    }
    if(my_dialog){
        my_dialog->hide();
        delete my_dialog;
        my_dialog = NULL;
    }
    if(my_roomdialog){
        my_roomdialog->hide();
        delete my_roomdialog;
        my_roomdialog = NULL;
    }
    if(my_setuser){
        my_setuser->hide();
        delete my_setuser;
        my_setuser = NULL;
    }

    if(my_audioCollect){
        delete my_audioCollect;
        my_audioCollect = NULL;
    }

    if(my_videoRead){
        delete my_videoRead;
        my_videoRead = NULL;
    }
    if(myclient){
        myclient->CloseNet();
        delete myclient;
        myclient = NULL;
    }
    if(my_deskread){
        delete my_deskread;
        my_deskread = NULL;
    }
}

//处理网络
void CControl::slot_dealDate(uint socket, char *buf, int nlen)
{
    int type = *(int*)buf;
    if(type >= DEF_PACK_BASE && type <= DEF_PACK_BASE+DEF_PACK_COUNT){
        PFUN pf = NetMap(type);
        if(pf)
            (this->*pf)(socket,buf,nlen);

    }
    delete[] buf;
}

//登陆回复
void CControl::slot_dealLoginRS(uint socket, char *buf, int nlen)
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
        my_dialog->show();
        break;
    }
}

//注册回复
void CControl::slot_dealRegisterRS(uint socket, char *buf, int nlen)
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

//初始化配置文件，读取ip
void CControl::initConfig()
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

//登陆提交
void CControl::slot_login_commit(QString number, QString password)
{
    std::string str_number      =   number.toStdString();
    std::string str_password    =   GetMD5(password);
    STRU_LOGIN_RQ rq;
    strcpy(rq.tel, str_number.c_str());
    strcpy(rq.password,str_password.c_str());
    slot_SendData(0,(char*)&rq,sizeof(rq));
}

//注册提交
void CControl::slot_register_commit(QString number, QString password)
{
    std::string str_number      =   number.toStdString();
    std::string str_password    =   GetMD5(password);
    //写入协议包
    STRU_REGISTER_RQ rq;
    strcpy(rq.tel, str_number.c_str());
    strcpy(rq.password, str_password.c_str());

    slot_SendData(0,(char*)&rq,sizeof(rq));
}

//发送数据
bool CControl::slot_SendData(unsigned int lSendIP, char *buf, int nlen)
{
    return myclient->SendData(lSendIP,buf,nlen);
}



//加入会议
void CControl::slot_joinroom()
{
    qDebug() << "slot_joinroom";
    if(room_id != 0){
        QMessageBox::about(this->my_dialog,"提示","不能重复加入房间");
        return;
    }
    int roomid = QInputDialog::getInt(this->my_dialog,"加入房间","房间号");
    if((roomid <= 0)||(roomid > 999999)){
        QMessageBox::about(this->my_dialog,"提示","房间号错误");
        return;
    }
    STRU_JOINROOM_RQ rq;
    rq.m_RoomID = roomid;
    rq.m_UserID = user_id;
    slot_SendData(0,(char*)&rq,sizeof(rq));

}

//创建会议
void CControl::slot_createroom()
{
    qDebug() << "slot_createroom";
    STRU_CREATEROOM_RQ rq;
    rq.m_UserID = user_id;
    slot_SendData(0,(char*)&rq,sizeof(rq));
}

//处理创建会议回复
void CControl::slot_del_createroom_RS(uint socket, char *buf, int nlen)
{
    qDebug( ) << "slot_del_createroom_RS";
    STRU_CREATEROOM_RS* rs = (STRU_CREATEROOM_RS*)buf;
    room_id = rs->m_RoomId;
    this->slot_set_joinroom(this->room_id);
}

//处理加入房间回复
void CControl::slot_del_joinroom_RS(uint socket, char *buf, int nlen)
{
    qDebug() << "slot_del_joinroom_RS";
    STRU_JOINROOM_RS* rs = (STRU_JOINROOM_RS*)buf;
    if(rs->m_lResult!=join_success){
        QMessageBox::about(my_dialog,"提示","加入失败");
        return;
    }
    else{
        QMessageBox::about(my_dialog,"提示","加入成功");
    }
    room_id = rs->m_RoomID;
    this->slot_set_joinroom(this->room_id);
}

//加入房间成员请求
void CControl::slot_del_roommem_RQ(uint socket, char *buf, int nlen)
{
    qDebug() << "slot_del_roommem_RQ";
    //拆包
    STRU_ROOM_MEMBER_RQ* rq = (STRU_ROOM_MEMBER_RQ*)buf;
    //检查房间是否已经存在该用户
    if(Map_IdToUsershow.count(rq->m_UserID) > 0)
        return;
    //用户显示
    my_usershow* new_user = new my_usershow;
    new_user->slot_setInfo(rq->m_UserID,QString::fromStdString(rq->m_szUser));
    connect(new_user,SIGNAL(SIG_userClicked(int,QString)),
            my_roomdialog,SLOT(slot_setBigImageInfo(int,QString)));
    //如果用户已经存在，则删除
    if(Map_IdToUsershow.count(rq->m_UserID) > 0){
        qDebug("old user");
        my_usershow* old = new my_usershow;
        old = Map_IdToUsershow[rq->m_UserID];
        Map_IdToUsershow.erase(rq->m_UserID);
        my_roomdialog->slot_removeuser(old);
    }
    Map_IdToUsershow[rq->m_UserID] = new_user;
    my_roomdialog->slot_adduser(new_user);

    //创建音频对象
    if(Map_IdToaudio.count(rq->m_UserID) > 0){
        Audio_play* ap = Map_IdToaudio[rq->m_UserID];
        Map_IdToaudio.erase(rq->m_UserID);
        delete ap;
    }
    Audio_play* ap = new Audio_play;
    Map_IdToaudio[rq->m_UserID] = ap;

}


//进入房间后原界面处理
void CControl::slot_set_joinroom(int roomid)
{
    qDebug() << "slot_set_joinroom";
    //隐藏原来界面，显示房间界面
    room_id = roomid;
    //按键变灰代替隐藏
    //this->my_dialog->hide();
    my_dialog->slot_setPushButton_enable(false);
    my_roomdialog->showNormal();
    my_roomdialog->set_roomid(room_id);

    //在房间中显示
    my_usershow* me = new my_usershow;
    connect(me,SIGNAL(SIG_userClicked(int,QString)),
            my_roomdialog,SLOT(slot_setBigImageInfo(int,QString)));
    me->slot_setInfo(user_id,user_name);
    Map_IdToUsershow[user_id] = me;
    my_roomdialog->slot_adduser(me);
}

//设置用户信息
void CControl::slot_setuser()
{
    qDebug() << "slot_setuser";
    my_setuser->show();
}

//提交用户信息
void CControl::slot_Setuser_Commit(int iconid, QString name, QString signature)
{
    std::string strName = name.toStdString();
    std::string strSignature = signature.toStdString();
    STRU_USER_INFO_RQ rq;
    rq.m_iconid = iconid;
    rq.m_UserID = user_id;
    strcpy(rq.m_szUser,strName.c_str());
    strcpy(rq.m_signature,strSignature.c_str());
    slot_SendData(0,(char*)&rq,sizeof(rq));
    QMessageBox::about(this->my_dialog,"提示","设置成功");
}

//处理初始化请求
void CControl::slot_del_setInfo_RS(uint socket, char *buf, int nlen)
{
    STRU_USER_INFO_RQ *rq = (STRU_USER_INFO_RQ*)buf;
    user_name = QString::fromStdString(rq->m_szUser);
    my_dialog->slot_setInfo(user_name,rq->m_iconid);
    my_setuser->slot_setInfo(rq->m_iconid,user_name,
                             QString::fromStdString(rq->m_signature));
}

//退出房间
void CControl::slot_quit_room()
{
    qDebug() << "slot_quit_room";
    //发包
    STRU_LEAVEROOM_RQ rq;
    rq.m_nUserId = user_id;
    rq.m_RoomId = room_id;
    slot_SendData(0,(char*)&rq,sizeof(rq));
    room_id = 0;
    my_dialog->slot_setPushButton_enable(true);
    //关闭各种按钮
    my_roomdialog->slot_setRoomClear();
    //退出房间
    for(auto item = Map_IdToUsershow.begin(); item != Map_IdToUsershow.end();/* item++*/){
        qDebug() << "11111";
        my_usershow *usershow = item->second;
        Map_IdToUsershow.erase(item++);
        qDebug("slot_quit_room");
        my_roomdialog->slot_removeuser(usershow);
    }
    //音频收集回收map
    for(auto item = Map_IdToaudio.begin(); item != Map_IdToaudio.end();/* item++*/){
        Audio_play * user = item->second;
        Map_IdToaudio.erase(item++);
        delete user;
    }
}

//处理离开房间请求
void CControl::slot_del_leaveroom_RQ(uint socket, char *buf, int nlen)
{

    qDebug() << "slot_del_leaveroom_RQ";
    STRU_LEAVEROOM_RQ* rq = (STRU_LEAVEROOM_RQ*)buf;
    if(Map_IdToUsershow.count(rq->m_nUserId) == 0)
        return;
    my_usershow* usershow = Map_IdToUsershow[rq->m_nUserId];
    //先脱离关系再回收
    Map_IdToUsershow.erase(usershow->my_id);
    my_roomdialog->slot_removeuser(usershow);

    //从map中回收这个人

}

void CControl::slot_audioOpen()
{
    my_audioCollect->slot_audiostart();
}

void CControl::slot_audioClose()
{
    my_audioCollect->slot_audiopause();
}

void CControl::slot_videoOpen()
{
    my_videoRead->slot_video_start();
}

void CControl::slot_videoClose()
{
    my_videoRead->slot_video_pause();
}

void CControl::slot_deskshareOpen()
{


}

void CControl::slot_deskshareClose()
{


}
///音频数据帧
/// 成员描述
/// int type;
/// int userId;
/// int roomId;
/// int hour;
/// int min;
/// int sec;
/// int msec;
/// QByteArray audioFrame;  --> char frame[]; 柔性数组
//发送视频数据
void CControl::slot_SendVideoDate(QByteArray& ba)
{
    int type = DEF_PACK_VIDEO_FRAME;
    int userid = user_id;
    int roomid = room_id;
    QTime tm = QTime::currentTime();
    int hour = tm.hour();
    int min = tm.minute();
    int sec = tm.second();
    int msec = tm.msec();
    char* Audiodata = ba.data();
    int len = ba.size();
    //序列化数据
    char* buf = new char[sizeof(int)*7+len];
    char* tmp = buf;
    *(int*)tmp = type;
    tmp += (sizeof(int));
    *(int*)tmp = userid;
    tmp += (sizeof(int));
    *(int*)tmp = roomid;
    tmp += (sizeof(int));
    *(int*)tmp = hour;
    tmp += (sizeof(int));
    *(int*)tmp = min;
    tmp += (sizeof(int));
    *(int*)tmp = sec;
    tmp += (sizeof(int));
    *(int*)tmp = msec;
    tmp += (sizeof(int));
    memcpy( tmp, Audiodata, len );
    tmp += len;



    slot_SendData(0,buf,sizeof(int)*7+len);
    delete[] buf;
}
//发送音频数据
void CControl::slot_SendAudioFrame(QByteArray& ba)
{
    //确认协议：协议头，房间号，音频长度，音频数据,卡顿避免
    int type = DEF_PACK_AUDIO_FRAME;
    int userid = user_id;
    int roomid = room_id;
    QTime tm = QTime::currentTime();
    int hour = tm.hour();
    int min = tm.minute();
    int sec = tm.second();
    int msec = tm.msec();
    char* Audiodata = ba.data();
    int len = ba.size();
    //序列化数据
    char* buf = new char[sizeof(int)*7+len];
    char* tmp = buf;
    *(int*)tmp = type;
    tmp += (sizeof(int));
    *(int*)tmp = userid;
//    qDebug() <<"*(int*)tmp userid"<<*(int*)tmp;
    tmp += (sizeof(int));
    *(int*)tmp = roomid;
//    qDebug() <<"*(int*)tmp roomid"<<*(int*)tmp;
    tmp += (sizeof(int));
    *(int*)tmp = hour;
    tmp += (sizeof(int));
    *(int*)tmp = min;
    tmp += (sizeof(int));
    *(int*)tmp = sec;
    tmp += (sizeof(int));
    *(int*)tmp = msec;
    tmp += (sizeof(int));
    memcpy( tmp, Audiodata, len );
    tmp += len;
//    qDebug() << sizeof(int)*7+len;


    slot_SendData(0,buf,sizeof(int)*7+len);
    delete[] buf;
    buf = NULL;

}
//主屏幕显示点击用户
void CControl::slot_RefreshUserFrame(int userid, QImage& image)
{
    //用户图片显示
    my_roomdialog->slot_setBigImage(userid,image);
    //预览图片显示
    if(Map_IdToUsershow.count(userid) > 0){


        //map中未存入用户数据



        my_usershow* user = Map_IdToUsershow[userid];
        user->slot_setImage(image);
    }
}

//刷新画面
void CControl::slot_RefreshVideoFrame(QImage& image)
{
    slot_RefreshUserFrame(user_id,image);
}


//处理音频数组
void CControl::slot_del_AudioFrame(uint socket, char *buf, int nlen)
{
    //反序列化
    int type;
    int userid;
    int roomid;

    //反序列化数据
    char* tmp = buf;
    type = *(int*)tmp ;
    tmp += (sizeof(int));
    userid = *(int*)tmp;
    tmp += (sizeof(int));
    roomid = *(int*)tmp ;
    tmp += (sizeof(int));

    tmp += (sizeof(int));

    tmp += (sizeof(int));

    tmp += (sizeof(int));

    tmp += (sizeof(int));/*
    qDebug() << "audio" << userid << "  " << roomid;*/
    //音频数据部分
    int audiolen = nlen - 7*sizeof(int);
    QByteArray ba(tmp,audiolen);
    if(Map_IdToaudio.count(userid) > 0){
        Audio_play* ap = Map_IdToaudio[userid];
        ap->slot_net_rx(ba);
    }

}


//处理视频数据
void CControl::slot_del_VideoFrame(uint socket, char *buf, int nlen)
{     
    int type;
    int userid;
    int roomid;

    //反序列化数据
    char* tmp = buf;
    type = *(int*)tmp ;
    tmp += (sizeof(int));
    userid = *(int*)tmp;
    tmp += (sizeof(int));
    roomid = *(int*)tmp ;
    tmp += (sizeof(int));
    //为用到的数据部分
    tmp += (sizeof(int));
    tmp += (sizeof(int));
    tmp += (sizeof(int));
    tmp += (sizeof(int));
//    qDebug() << "vedio" << userid;
    //图片数据部分
    int imagelen = nlen - 7*sizeof(int);
    QImage image;
    image.loadFromData((uchar*)tmp,imagelen);
    slot_RefreshUserFrame(userid,image);
}



CControl::~CControl()
{
    slot_destroy();
}


