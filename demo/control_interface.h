#ifndef CONTROL_INTERFACE_H
#define CONTROL_INTERFACE_H
#include <QObject>
#include "mainwindow.h"
#include "dialog.h"
#include <QWidget>
#include "TcpClientMediator.h"
#include "TcpServerMediator.h"
class control_interface
{
public:
    control_interface();
    static control_interface *create_control_interface();
private:
    Dialog* mydialog;
    Mainwindow* mymainwindow;
    INetMediator* my_client;
    explicit control_interface(QWidget *parent = 0);
    ~control_interface();
    control_interface (const control_interface&){}
signals:

public slots:
    void slot_destroy();//销毁窗口
    void SIG_DealData(uint,char*,int);
};

#endif // CONTROL_INTERFACE_H
