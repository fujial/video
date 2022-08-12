#include "control_interface.h"

#define _SERVER_IP_

control_interface* control_interface::create_control_interface()
{
    static control_interface* control;
    return control;
}

control_interface::control_interface(QWidget *parent):QObject(NULL)
{
    Dialog* mydialog = new Dialog;
    Mainwindow* mymainwindow = new Mainwindow;
    INetMediator* my_client = new TcpClientMediator;
    //connect(my_client,SIGNAL(SIG_ReadyData(uint,char*,int)),
    //       this,SLOT(SIG_DealData(uint,char*,int)));
    //my_client->OpenNet(_SERVER_IP_,8080);//链接服务器
    //mymainwindow->show();
    mydialog->show();
}

control_interface::~control_interface()
{
    slot_destroy();
}

void control_interface::control_interface::slot_destroy()
{
    if(mydialog){
        mydialog->hide();
        delete mydialog;
        mydialog = NULL;
    }//避免多线程多次调用
    if(mydialog){
        mydialog->hide();
        delete mydialog;
        mydialog = NULL;
    }
    if(my_client){
        my_client->CloseNet();
        delete my_client;
        my_client = NULL;
    }
}

void control_interface::control_interface::SIG_DealData(uint a, char *buf, int nlen)
{
    delete[] buf;
}

