#pragma once


#define _DEF_BUFFER  ( 4096 )
#define _DEF_CONTENT_SIZE	(1024)
#define _MAX_SIZE	(40)

//自定义协议   先写协议头 再写协议结构
//登录 注册 获取好友信息 添加好友 聊天 发文件 下线请求
//#define _DEF_PROTOCOL_BASE	(10000)
//#define _DEF_PROTOCOL_COUNT (100)

#define BOOL bool
#define DEF_PACK_BASE  (10000)
#define DEF_PACK_COUNT  (100)

//注册
#define  DEF_PACK_REGISTER_RQ    (DEF_PACK_BASE + 0)
#define  DEF_PACK_REGISTER_RS    (DEF_PACK_BASE + 1)
//登录
#define  DEF_PACK_LOGIN_RQ    (DEF_PACK_BASE + 2)
#define  DEF_PACK_LOGIN_RS    (DEF_PACK_BASE + 3)
//创建房间
#define DEF_PACK_CREATEROOM_RQ  (DEF_PACK_BASE + 4)
#define DEF_PACK_CREATEROOM_RS  (DEF_PACK_BASE + 5)
//加入房间
#define DEF_PACK_JOINROOM_RQ  (DEF_PACK_BASE + 6)
#define DEF_PACK_JOINROOM_RS  (DEF_PACK_BASE + 7)
//房间列表请求
#define DEF_PACK_ROOM_MEMBER    (DEF_PACK_BASE + 8)
//音频数据
#define DEF_PACK_AUDIO_FRAME    (DEF_PACK_BASE + 9)
//视频数据
#define DEF_PACK_VIDEO_FRAME    (DEF_PACK_BASE + 10)
//退出房间请求
#define DEF_PACK_LEAVEROOM_RQ   (DEF_PACK_BASE + 11)
//退出房间回复
#define DEF_PACK_LEAVEROOM_RS   (DEF_PACK_BASE + 12)
//音频注册
#define DEF_PACK_AUDIO_REGISTER (DEF_PACK_BASE + 13)
//视频注册
#define DEF_PACK_VIDEO_REGISTER (DEF_PACK_BASE + 14)
//好友信息
#define _DEF_PACK_FRIEND_INFO	(DEF_PACK_BASE + 21 )
//添加好友
#define _DEF_PACK_ADDFRIEND_RQ	(DEF_PACK_BASE + 16 )
#define _DEF_PACK_ADDFRIEND_RS	(DEF_PACK_BASE + 17 )
//聊天
#define _DEF_PACK_CHAT_RQ	(DEF_PACK_BASE + 18 )
#define _DEF_PACK_CHAT_RS	(DEF_PACK_BASE + 19 )
//离线
#define _DEF_PACK_OFFLINE_RQ	(DEF_PACK_BASE + 20 )
//用户信息
#define DEF_PACK_USER_INFO      (DEF_PACK_BASE + 15)

////返回的结果

//注册请求结果
#define tel_is_exist		(0)
#define register_success	(1)
#define name_is_exist       (2)

//登录请求结果
#define user_not_exist		(0)
#define password_error		(1)
#define login_success		(2)
//#define user_online          3

//创建房间结果
#define room_is_exist        0
#define create_success       1

//加入房间结果
#define room_no_exist        0
#define join_success         1
////注册

//添加好友的结果
#define no_this_user		(0)
#define user_refuse			(1)
#define user_offline		(2)
#define add_success			(3)

typedef int PackType;

//协议结构
//注册
typedef struct STRU_REGISTER_RQ
{
    STRU_REGISTER_RQ():type(DEF_PACK_REGISTER_RQ)
	{
		memset( tel  , 0, sizeof(tel));
    //	memset( name  , 0, sizeof(name));
		memset( password , 0, sizeof(password) );
	}
	//需要手机号码 , 密码, 昵称
	PackType type;
	char tel[_MAX_SIZE];
    //char name[_MAX_SIZE];
	char password[_MAX_SIZE];

}STRU_REGISTER_RQ;

typedef struct STRU_REGISTER_RS
{
	//回复结果
    STRU_REGISTER_RS(): type(DEF_PACK_REGISTER_RS) , result(register_success)
	{
	}
	PackType type;
	int result;

}STRU_REGISTER_RS;

//登录
typedef struct STRU_LOGIN_RQ
{
	//登录需要: 手机号 密码 
    STRU_LOGIN_RQ():type(DEF_PACK_LOGIN_RQ)
	{
		memset( tel , 0, sizeof(tel) );
		memset( password , 0, sizeof(password) );
	}
	PackType type;
	char tel[_MAX_SIZE];
	char password[_MAX_SIZE];

}STRU_LOGIN_RQ;

typedef struct STRU_LOGIN_RS
{
	// 需要 结果 , 用户的id
    STRU_LOGIN_RS(): type(DEF_PACK_LOGIN_RS) , result(login_success),userid(0)
	{
	}
    PackType type;
    int userid;
    int result;

} STRU_LOGIN_RS;

//好友信息
typedef struct STRU_FRIEND_INFO
{
    STRU_FRIEND_INFO():type(_DEF_PACK_FRIEND_INFO) , userid(0) , iconid(0)
	{
		memset( name ,  0 , sizeof(name) );
//		memset( feeling , 0 , sizeof(feeling));
	}
        //需要 用户id 头像id 昵称 ////签名 状态--是否在线
	PackType type;
	int userid;
	int iconid;
//	int state;
	char name[_MAX_SIZE];
//	char feeling[_MAX_SIZE];

}STRU_FRIEND_INFO;

//添加好友
typedef struct STRU_ADD_FRIEND_RQ
{
	// 如果用户1 添加用户2 为好友 需要 用户1 id 用户1 名字 ,用户2的名字
	STRU_ADD_FRIEND_RQ():type(_DEF_PACK_ADDFRIEND_RQ) , userid(0)
	{
		memset( userName  , 0 , sizeof(userName));
		memset( friendName , 0 , sizeof(friendName));
	}
	PackType type;
	int userid;
	char userName[_MAX_SIZE];
	char friendName[_MAX_SIZE];

}STRU_ADD_FRIEND_RQ;

typedef struct STRU_ADD_FRIEND_RS
{
    STRU_ADD_FRIEND_RS():type(_DEF_PACK_ADDFRIEND_RS) , userid(0), friendid(0),result(add_success)
	{
		memset( friendName  , 0 , sizeof(friendName));
	}
	//如果用户1 添加用户2 需要 用户1id  用户2 id 用户2的名字 结果
	PackType type;
	int userid; // 用户1
	int friendid; // 用户2
	int result;
	char friendName[_MAX_SIZE];
	
}STRU_ADD_FRIEND_RS;

//聊天
typedef struct STRU_CHAT_RQ
{
	STRU_CHAT_RQ():type(_DEF_PACK_CHAT_RQ) , userid(0) , friendid(0)
	{
		memset( content , 0 , _DEF_CONTENT_SIZE );
	}
	// 谁发给谁 服务器转发  用户1 id 用户2 id 发的内容
	PackType type;
	int userid;
	int friendid;
	char content[_DEF_CONTENT_SIZE];

}STRU_CHAT_RQ;

typedef struct STRU_CHAT_RS
{
	STRU_CHAT_RS():type(_DEF_PACK_CHAT_RS) , userid(0) , friendid(0),result(0)
	{
	}
	PackType type;
	int userid;
	int friendid; //方便找是哪个人不在线
	int result;

}STRU_CHAT_RS;

//发给服务器说明离线
typedef struct STRU_OFFLINE
{
    STRU_OFFLINE():type(_DEF_PACK_OFFLINE_RQ) , userid(0)
    {
    }
    PackType type;
    int userid;

}STRU_OFFLINE;

//创建房间请求
typedef struct STRU_CREATEROOM_RQ
{
    STRU_CREATEROOM_RQ()
    {
        m_nType = DEF_PACK_CREATEROOM_RQ;
        m_UserID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;

}STRU_CREATEROOM_RQ;

//创建房间回复
typedef struct STRU_CREATEROOM_RS
{
    STRU_CREATEROOM_RS()
    {
        m_nType= DEF_PACK_CREATEROOM_RS;
        m_lResult = 0;
        m_RoomId = 0;
    }
    PackType m_nType;   //包类型
    int  m_lResult ;    //创建结果
    int  m_RoomId;

}STRU_CREATEROOM_RS;

//加入房间请求
typedef struct STRU_JOINROOM_RQ
{
    STRU_JOINROOM_RQ()
    {
        m_nType = DEF_PACK_JOINROOM_RQ;
        m_UserID = 0;
        m_RoomID = 0;
    }

    PackType m_nType;   //包类型
    int m_UserID;
    int m_RoomID;

}STRU_JOINROOM_RQ;

//加入房间回复
typedef struct STRU_JOINROOM_RS
{
    STRU_JOINROOM_RS()
    {
        m_nType= DEF_PACK_JOINROOM_RS;
        m_lResult = 0;
        m_RoomID = 0;
    }
    PackType m_nType;   //包类型
    int  m_lResult ;    //注册结果
    int m_RoomID;
}STRU_JOINROOM_RS;

//房间成员请求
typedef struct STRU_ROOM_MEMBER_RQ
{
    STRU_ROOM_MEMBER_RQ()
    {
        m_nType= DEF_PACK_ROOM_MEMBER;
        m_UserID =0;
        memset(m_szUser,0,_MAX_SIZE);
    }
    PackType m_nType;   //包类型
    int m_UserID;
    char m_szUser[_MAX_SIZE];

}STRU_ROOM_MEMBER_RQ;


//离开房间请求
typedef struct STRU_LEAVEROOM_RQ
{
    STRU_LEAVEROOM_RQ()
    {
        m_nType = DEF_PACK_LEAVEROOM_RQ;
        m_nUserId = 0;
        m_RoomId = 0;
        memset(szUserName,0,_MAX_SIZE);
    }
    PackType   m_nType;   //包类型
    int    m_nUserId; //用户ID
    int    m_RoomId;
    char   szUserName[_MAX_SIZE];
}STRU_LEAVEROOM_RQ;

//用户信息请求
struct STRU_USER_INFO_RQ{
    STRU_USER_INFO_RQ(){
        m_nType = DEF_PACK_USER_INFO;
        m_UserID = 0;
        m_iconid = 0;
        memset(m_szUser,0,sizeof(m_szUser));
        memset(m_signature,0,sizeof(m_signature));
    }
    PackType m_nType;
    int m_UserID;
    int m_iconid;
    char m_signature[_MAX_SIZE];
    char m_szUser[_MAX_SIZE];
};

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
///


///视频数据帧
/// 成员描述
/// int type;
/// int userId;
/// int roomId;
/// int min;
/// int sec;
/// int msec;
/// QByteArray videoFrame;



