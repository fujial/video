#include "clogic.h"

void CLogic::setNetPackMap()
{
    NetPackMap(DEF_PACK_REGISTER_RQ)    = &CLogic::RegisterRq;
    NetPackMap(DEF_PACK_LOGIN_RQ)       = &CLogic::LoginRq;
    NetPackMap(DEF_PACK_CREATEROOM_RQ)  = &CLogic::CreateRq;
    NetPackMap(DEF_PACK_JOINROOM_RQ)    = &CLogic::JoinRq;
    NetPackMap(DEF_PACK_USER_INFO)      = &CLogic::slot_UserInfo_RQ;
    NetPackMap(DEF_PACK_LEAVEROOM_RQ)   = &CLogic::LeaveRoomRq;
    NetPackMap(DEF_PACK_ROUND_START)    = &CLogic::round_begin;
    NetPackMap(DEF_PACK_ROUND_END)      = &CLogic::round_end;
}

void CLogic::SendData(sock_fd clientfd, char *szbuf, int nlen)
{
    m_pKernel->SendData( clientfd ,szbuf , nlen );
}

//注册
void CLogic::RegisterRq(sock_fd clientfd,char* szbuf,int nlen)
{
    printf("clientfd:%d RegisterRq\n", clientfd);
    STRU_REGISTER_RQ* rq = (STRU_REGISTER_RQ*)szbuf;
    list<string>lstRes;
    char strsql[1024];
    sprintf(strsql,"select tel from t_user where tel = '%s';",rq->m_tel);
    m_sql->SelectMysql(strsql,1 ,lstRes);
    STRU_REGISTER_RS rs;
    if(lstRes.size() > 0){
        rs.m_lResult = tel_is_exist;
    }else{
        rs.m_lResult = register_success;
        sprintf(strsql,"insert into t_user(tel,password,name) values('%s','%s','%s');",
                rq->m_tel,rq->m_password,rq->m_tel);
        if(!m_sql->UpdataMysql(strsql)){
            printf("updata false:%s\n",strsql);
        }
    }
    SendData(clientfd,(char*)&rs,sizeof(rs));
}

//登录
void CLogic::LoginRq(sock_fd clientfd ,char* szbuf,int nlen)
{
    printf("clientfd:%d LoginRq\n", clientfd);

    STRU_LOGIN_RQ* rq = (STRU_LOGIN_RQ*)szbuf;
    char strsql[1024] = "";
    sprintf(strsql,"select id,password from t_user where tel = '%s';",rq->m_tel);
    list<string> lstRes;
    bool res = m_sql->SelectMysql(strsql,2,lstRes);
    if(!res)
           printf("select error:%s\n",strsql);
    STRU_LOGIN_RS rs;
    if(lstRes.size()>0){
        int id = atoi(lstRes.front().c_str());
        rs.userid = id;
        lstRes.pop_front();
        string strPassword = lstRes.front();

        lstRes.pop_front();
        if(strcmp(strPassword.c_str(),rq->m_password)!=0){
            rs.result = password_error;
        }
        else{
            rs.result = login_success;
            UserInfo *user = NULL;

            if(m_mapIdTouserInfo.find(id,user)){
                //查到了，询问要不要强制下线另一个设备，写一个协议包
                //delete user;
            }
            else{
                user = new UserInfo;
            }
            user->m_id = id;
            user->m_sockfd = clientfd;
            m_mapIdTouserInfo.insert(id,user);
            //Get_UserInfo_Send(id);
        }
    }
    else{
        rs.result = user_not_exist;
    }
    SendData(clientfd,(char*)&rs,sizeof(rs));
    //Get_UserInfo_Send(rs.userid);
}


//处理加入房间请求
void CLogic::JoinRq(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d JoinRq\n", clientfd);
    int playerid = 0;

    UserInfo* playerInfo = nullptr;
    UserInfo* enemyInfo = nullptr;
    //拆包
    STRU_JOINROOM_RQ* rq = (STRU_JOINROOM_RQ*)szbuf;
    STRU_JOINROOM_RS  rs;
    //查询房间是否存在
    list<int> list;
    rs.m_RoomID = rq->m_RoomID;
    if( (m_mapRoomidToplayer.find(rq->m_RoomID,list))== false){
        rs.m_lResult = room_no_exist;
    }
    else if(list.size() >= 2){
        rs.m_lResult = room_max;
    }else{
        rs.m_lResult = join_success;
        //更新房间成员信息表
        playerid = list.front();
        rs.playerid = playerid;
        list.push_back(rq->m_UserID);
        m_mapRoomidToplayer.insert(rq->m_RoomID,list);
        //更新加入房间成员信息
        m_mapIdTouserInfo.find(rq->m_UserID,enemyInfo);
        enemyInfo->m_enemyid = rq->m_UserID;
        enemyInfo->m_sockfd = clientfd;
        enemyInfo->m_id = playerid;
        enemyInfo->m_roomid = rq->m_RoomID;
        m_mapIdTouserInfo.insert(rq->m_UserID,enemyInfo);
    }

    SendData(clientfd,(char*)&rs,sizeof(rs));

    //给房间成员发送通知
    m_mapIdTouserInfo.find(playerid,playerInfo);
    STRU_ROOM_MEMBER_RQ playerrq;
    playerrq.m_enemyid = rq->m_UserID;
    SendData(playerInfo->m_sockfd,(char*)&playerrq,sizeof(playerrq));
    //更新房间成员信息
    m_mapIdTouserInfo.insert(playerid,playerInfo);
}

//处理创建房间请求
void CLogic::CreateRq(sock_fd clientfd, char *szbuf, int nlen)
{
    STRU_CREATEROOM_RQ* rq = (STRU_CREATEROOM_RQ*)szbuf;
    printf("clientfd:%d CreateRq\n", clientfd);
    int roomid = 0;
    do{
       roomid = random()%999999 + 1;
    }while(m_mapRoomidToplayer.IsExist(roomid));
    //房间id对应玩家id
    list<int> Player;
    Player.push_back(rq->m_UserID);
    if(!m_mapRoomidToplayer.find(roomid,Player)){
        m_mapRoomidToplayer.insert(roomid,Player);
    }
//    m_mapRoomidToplayer.insert(roomid,Player);
//    list<int> list;
//    list.push_back(rq->m_UserID);
//    if(!m_mapRoomidToUserlist.find(roomid,list))
//        m_mapRoomidToUserlist.insert(roomid,list);
    STRU_CREATEROOM_RS rs;
    rs.m_RoomId = roomid;
    rs.m_lResult = 1;

    SendData(clientfd,(char*)&rs,sizeof(rs));
}

void CLogic::slot_UserInfo_RQ(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d SetInfoRq\n", clientfd);
    STRU_USER_INFO_RQ *rq = (STRU_USER_INFO_RQ*)szbuf;
    char sqlstr[1024];
    sprintf(sqlstr,"update t_user set icon = %d,name = '%s' where id = %d;",
            rq->m_iconid,rq->m_szUser,rq->m_UserID);
    printf("%s\n",sqlstr);
    m_sql->UpdataMysql(sqlstr);
    Get_UserInfo_Send(rq->m_UserID);
}

//获取用户信息并发送
void CLogic::Get_UserInfo_Send(int id)
{
    printf("userid:%d get_userinfo_send\n",id);
    char sql[1024] = "";
    sprintf(sql,"select name,icon from t_user where id = %d;",id);
    list<string> lst;
    m_sql->SelectMysql(sql,2,lst);
    if(lst.size() != 2)
        return ;
    string name = lst.front();
    lst.pop_front();
    string iconid = lst.front();
    lst.pop_front();

    UserInfo* user = nullptr;
    if(!m_mapIdTouserInfo.find(id,user)){
        printf("Get_UserInfo_Send find m_mapIdTouserInfo error\n");
        return;
    }
    strcpy(user->m_userName,name.c_str());
    STRU_USER_INFO_RQ rq;
    rq.m_UserID = id;
    rq.m_iconid = atoi(iconid.c_str());
    strcpy(rq.m_szUser,name.c_str());
    SendData(user->m_sockfd,(char*)&rq,sizeof(rq));
}

//离开房间请求
void CLogic::LeaveRoomRq(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d LeaveRoomRq\n", clientfd);
    STRU_LEAVEROOM_RQ *rq = (STRU_LEAVEROOM_RQ*) szbuf;
    //向两个玩家发送胜利还是失败回复包
    STRU_LEAVEROOM_RS rs;
    rs.loserid = rq->loserid;
    rs.winnerid = rq->winnerid;
    UserInfo* winner;
    if(m_mapIdTouserInfo.find(rq->winnerid,winner))
        SendData(winner->m_sockfd,(char*)&rs,sizeof(rs));
    m_mapRoomidToplayer.erase(rq->m_RoomId);
//    m_mapRoomidToplayer.erase(rq->loserid);
//    m_mapRoomidToplayer.erase(rq->winnerid);

}

void CLogic::round_end(sock_fd clientfd, char *szbuf, int nlen)
{

}

void CLogic::round_begin(sock_fd clientfd, char *szbuf, int nlen)
{

}


