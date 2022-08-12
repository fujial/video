#ifndef CLOGIC_H
#define CLOGIC_H

#include"TCPKernel.h"

class CLogic
{
public:
    CLogic( TcpKernel* pkernel )
    {
        m_pKernel = pkernel;
        m_sql = pkernel->m_sql;
        m_tcp = pkernel->m_tcp;
    }
public:
    //设置协议映射
    void setNetPackMap();
    /************** 发送数据*********************/
    void SendData( sock_fd clientfd, char*szbuf, int nlen )
    {
        m_pKernel->SendData( clientfd ,szbuf , nlen );
    }
    /************** 网络处理 *********************/
    //注册
    void RegisterRq(sock_fd clientfd, char*szbuf, int nlen);
    //登录
    void LoginRq(sock_fd clientfd, char*szbuf, int nlen);

    void JoinRq(sock_fd clientfd, char*szbuf, int nlen);

    void CreateRq(sock_fd clientfd, char*szbuf, int nlen);

    //设置用户信息
    void slot_UserInfo_RQ(sock_fd clientfd, char*szbuf, int nlen);

    void Get_UserInfo_Send(int id);

    void LeaveRoomRq(sock_fd clientfd, char*szbuf, int nlen);

    void AudioFrame(sock_fd clientfd, char*szbuf, int nlen);

    void VideoFrame(sock_fd clientfd, char*szbuf, int nlen);
    /*******************************************/

private:
    TcpKernel* m_pKernel;
    CMysql * m_sql;
    Block_Epoll_Net * m_tcp;

    MyMap<int , UserInfo*> m_mapIdTouserInfo;
    MyMap<int , list<int>> m_mapRoomidToUserlist;
};

#endif // CLOGIC_H
