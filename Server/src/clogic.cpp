#include "clogic.h"

void CLogic::setNetPackMap()
{
    NetPackMap(DEF_PACK_REGISTER_RQ)    = &CLogic::RegisterRq;
    NetPackMap(DEF_PACK_LOGIN_RQ)       = &CLogic::LoginRq;
    NetPackMap(DEF_PACK_JOINROOM_RQ)    = &CLogic::JoinRq;
    NetPackMap(DEF_PACK_CREATEROOM_RQ)  = &CLogic::CreateRq;
    NetPackMap(DEF_PACK_USER_INFO)      = &CLogic::slot_UserInfo_RQ;
    NetPackMap(DEF_PACK_LEAVEROOM_RQ)   = &CLogic::LeaveRoomRq;
    NetPackMap(DEF_PACK_VIDEO_FRAME)    = &CLogic::VideoFrame;
    NetPackMap(DEF_PACK_AUDIO_FRAME)    = &CLogic::AudioFrame;
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
        sprintf(strsql,"insert into t_user(tel,password,name,icon,feeling) values('%s','%s','%s',5,'nothing');",
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
            Get_UserInfo_Send(id);
        }
    }
    else{
        rs.result = user_not_exist;
    }
    SendData(clientfd,(char*)&rs,sizeof(rs));
}


//处理加入房间请求
void CLogic::JoinRq(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d JoinRq\n", clientfd);
    //拆包
    STRU_JOINROOM_RQ* rq = (STRU_JOINROOM_RQ*)szbuf;
    STRU_JOINROOM_RS  rs;
    //查询房间是否存在
    list<int> list;
    rs.m_RoomID = rq->m_RoomID;
    if( !m_mapRoomidToUserlist.find(rq->m_RoomID,list)){
        rs.m_lResult = room_no_exist;
    }else{
        rs.m_lResult = join_success;
    }
    SendData(clientfd,(char*)&rs,sizeof(rs));

    //查询是否已经在房间
    UserInfo* joinInfo = nullptr;
    if( !m_mapIdTouserInfo.find(rq->m_UserID,joinInfo) ){
        return;
    }
    STRU_ROOM_MEMBER_RQ joinrq;
    joinrq.m_UserID = rq->m_UserID;
    strcpy(joinrq.m_szUser,joinInfo->m_userName);

    //给房间所有成员发送通知
    for(auto item = list.begin(); item != list.end();++item){
        int memid = *item;
        UserInfo* memInfo = nullptr;
        if(!m_mapIdTouserInfo.find(memid,memInfo)){
            continue;
        }
        STRU_ROOM_MEMBER_RQ memrq;
        memrq.m_UserID = memid;
        strcpy(memrq.m_szUser,memInfo->m_userName);
        //
        SendData(memInfo->m_sockfd,(char*)&joinrq,sizeof(joinrq));
        //
        SendData(joinInfo->m_sockfd,(char*)&memrq,sizeof (memrq));
    }
    //更新房间成员信息
    list.push_back(joinInfo->m_id);
    //成员信息更新
    m_mapRoomidToUserlist.insert(rq->m_RoomID,list);
}

//处理创建房间请求
void CLogic::CreateRq(sock_fd clientfd, char *szbuf, int nlen)
{
    STRU_CREATEROOM_RQ* rq = (STRU_CREATEROOM_RQ*)szbuf;
    printf("clientfd:%d CreateRq\n", clientfd);
    int roomid = 0;
    do{
       roomid = random()%999999 + 1;
    }while(m_mapRoomidToUserlist.IsExist(roomid));
    list<int> list;
    list.push_back(rq->m_UserID);
    if(!m_mapRoomidToUserlist.find(roomid,list))
        m_mapRoomidToUserlist.insert(roomid,list);
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
    sprintf(sqlstr,"update t_user set icon = %d,name = '%s',feeling = '%s' where id = %d;",
            rq->m_iconid,rq->m_szUser,rq->m_signature,rq->m_UserID);
    printf("%s\n",sqlstr);
    m_sql->UpdataMysql(sqlstr);
    Get_UserInfo_Send(rq->m_UserID);
}
//获取用户信息并发送
void CLogic::Get_UserInfo_Send(int id)
{
    char sql[1024] = "";
    sprintf(sql,"select name,icon,feeling from t_user where id = %d;",id);
    list<string> lst;
    m_sql->SelectMysql(sql,3,lst);
    if(lst.size() != 3)
        return ;
    string name = lst.front();
    lst.pop_front();
    string iconid = lst.front();
    lst.pop_front();
    string feeling = lst.front();
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
    strcpy(rq.m_signature,feeling.c_str());
    SendData(user->m_sockfd,(char*)&rq,sizeof(rq));

}

//离开房间请求
void CLogic::LeaveRoomRq(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d LeaveRoomRq\n", clientfd);
    STRU_LEAVEROOM_RQ *rq = (STRU_LEAVEROOM_RQ*) szbuf;
    list<int> list;
    if(!m_mapRoomidToUserlist.find(rq->m_RoomId,list))
        return;
    for(auto item = list.begin(); item!=list.end();){
        int id = *item;
        if(id == rq->m_nUserId){
            m_mapRoomidToUserlist.erase(id);
            printf("auto first\n");
            item = list.erase(item);
            //SendData(clientfd,szbuf,nlen);
        }
        else{
            UserInfo* user = NULL;
            printf("auto second\n");
            if(!m_mapIdTouserInfo.find(id,user))
                continue;
            SendData(user->m_sockfd,szbuf,nlen);
            ++item;
        }
    }
    if(list.size() == 0){
        printf("roomid == %d\n",rq->m_RoomId);
        m_mapRoomidToUserlist.erase(rq->m_RoomId);
    }else{
        m_mapRoomidToUserlist.insert(rq->m_RoomId,list);
    }
}
//处理音频请求
void CLogic::AudioFrame(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d AudioFrame nlen %d ", clientfd,nlen);

    char* tmp = szbuf;
    tmp += sizeof(int);
    int userid = *(int*)tmp;
    tmp += sizeof(int);
    int roomid = *(int*)tmp;
    printf("%d,%d\n",userid,roomid);
    list<int> lst;
    if(!m_mapRoomidToUserlist.find(roomid,lst))
        return;
    for(auto item = lst.begin(); item != lst.end(); ++item){
        int id = * item;
        if(id != userid){
            UserInfo* user = NULL;
            if(!m_mapIdTouserInfo.find(id,user))
                continue;
            SendData(user->m_sockfd,szbuf,nlen);
        }
    }
}
//处理视频请求
void CLogic::VideoFrame(sock_fd clientfd, char *szbuf, int nlen)
{
    printf("clientfd:%d VideoFrame\n", clientfd);
    char* tmp = szbuf;
    tmp += sizeof(int);
    int userid = *(int*)tmp;
    tmp += sizeof(int);
    int roomid = *(int*)tmp;

    list<int> lst;
    if(!m_mapRoomidToUserlist.find(roomid,lst))
        return;
    for(auto item = lst.begin(); item != lst.end(); ++item){
        int id = * item;
        //if(id != userid){
            UserInfo* user = NULL;
            if(!m_mapIdTouserInfo.find(id,user))
                continue;
            SendData(user->m_sockfd,szbuf,nlen);
        //}
    }
}




