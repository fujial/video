#include "dialog.h"
#include "ui_dialog.h"

DemoDialog::DemoDialog(QWidget *parent)
    : CustomMoveDialog(parent)
    , ui(new Ui::DemoDialog)
{
    ui->setupUi(this);

    this->setWindowFlags( Qt::FramelessWindowHint );
}

DemoDialog::~DemoDialog()
{
    delete ui;
}

void DemoDialog::closeEvent(QCloseEvent *event)
{
    if( QMessageBox::question( this , "提示" , "是否关闭?" )
            == QMessageBox::Yes  )
    {
        //关闭
        //event->accept();
        Q_EMIT SIG_close();
    }else{
        //忽略
        event->ignore();
    }
}


void DemoDialog::on_pb_min_clicked()
{
    this->showMinimized();
}

void DemoDialog::on_pb_close_clicked()
{
    this->close();
}

//创建会议
void DemoDialog::on_pb_create_clicked()
{
    Q_EMIT SIG_createRoom();
}

//加入会议
void DemoDialog::on_pb_join_clicked()
{
    Q_EMIT SIG_joinRoom();
}

//设置属性  ui 和成员
void DemoDialog::slot_setInfo(QString name, int iconid)
{
    m_name = name;
    m_iconid = iconid;

    ui->lb_name->setText( m_name );
    //资源引用 :/tx/2.png
    ui->pb_icon->setIcon( QIcon( QString(":/tx/%1.png").arg(iconid)  ) );
}


void DemoDialog::on_pb_icon_clicked()
{
    //发送信号
    Q_EMIT SIG_setUser();
}

void DemoDialog::slot_setPushButton_enable(bool flag)
{
    ui->pb_create->setEnabled( flag );
    ui->pb_join->setEnabled( flag );
}

