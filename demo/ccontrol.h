#ifndef CCONTROL_H
#define CCONTROL_H

#include <QObject>
#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QCloseEvent>
#include <QSettings>//包含配置文件
#include <QFileInfo>
#include <QApplication>
#include <QInputDialog>
#include <QTime>

#include <map>


#include <dialog.h>
#include <login_dialog.h>
#include <roomdialog.h>
#include <set_user.h>
#include "TcpClientMediator.h"
#include "packdef.h"
#include "md5.h"
#define MD5_KEY "123"
class CControl;//避免先定义了函数指针导致找不到类的生命
typedef void (CControl:: *PFUN)(uint,char*,int);


class CControl : public QObject
{
    Q_OBJECT
public:
    static CControl* createControl();

private:
    explicit CControl(QObject *parent = 0);
    CControl(const CControl&){}
    ~CControl();

private:
    PFUN            my_netMap[DEF_PACK_COUNT];//选择采取协议种类，数量为协议数量
    Login_Dialog*   my_login_dialog;
    INetMediator*   myclient;
    QString         server_IP;
    DemoDialog*         my_dialog;
    RoomDialog*     my_roomdialog;
    set_user*       my_setuser;
    int             user_id;
    int             room_id;
    QString         user_name;
    std::map<int ,my_usershow*> Map_IdToUsershow;

    Audio_collect*  my_audioCollect;
    //每个用户有自己的视频读取对象
    std::map<int ,Audio_play*> Map_IdToaudio;

    video_read*     my_videoRead;
    //桌面采集对象
    video_show*     my_deskread;

    std::map<int ,video_show*> Map_IdToVideo;



signals:

public slots:
    //设置协议映射
    void set_netMap();

    //网络处理函数
    void slot_dealDate(uint socket, char *buf, int nlen);

    void slot_destroy();

    void slot_dealLoginRS(uint socket, char *buf, int nlen);

    void slot_dealRegisterRS(uint socket, char *buf, int nlen);

    void initConfig();

    void slot_login_commit(QString number,QString password);

    void slot_register_commit(QString number,QString password);
    //向客户端发送数据
    bool slot_SendData(unsigned int lSendIP , char* buf , int nlen );
    //加入会议
    void slot_joinroom();
    //创建会议
    void slot_createroom();
    //创建房间回复
    void slot_del_createroom_RS(uint socket, char *buf, int nlen);
    //加入房间回复
    void slot_del_joinroom_RS(uint socket, char *buf, int nlen);
    //加入房间成员请求
    void slot_del_roommem_RQ(uint socket, char *buf, int nlen);

    void slot_set_joinroom(int roomid);
    //设置用户信息
    void slot_setuser();

    void slot_Setuser_Commit(int iconid, QString name, QString signature);

    void slot_del_setInfo_RS(uint socket, char *buf, int nlen);

    void slot_quit_room();

    void slot_del_leaveroom_RQ(uint socket, char *buf, int nlen);

    void slot_audioOpen();
    void slot_audioClose();
    void slot_videoOpen();
    void slot_videoClose();
    void slot_deskshareOpen();
    void slot_deskshareClose();

    //发送音频数据
    void slot_SendAudioFrame(QByteArray& ba);
    //发送视频
    void slot_RefreshVideoFrame(QImage& image);
    void slot_RefreshUserFrame(int userid,QImage& image);
    void slot_SendVideoDate(QByteArray& ba);

    void slot_del_AudioFrame(uint socket, char *buf, int nlen);
    void slot_del_VideoFrame(uint socket, char *buf, int nlen);


};

#endif // CCONTROL_H
