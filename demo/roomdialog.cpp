#include "roomdialog.h"
#include "ui_roomdialog.h"

RoomDialog::RoomDialog(QWidget *parent) :
    CustomMoveDialog(parent),
    ui(new Ui::RoomDialog)
{
    ui->setupUi(this);
    my_boxlayout = new QVBoxLayout;
    //用户列表垂直布局
    ui->wdg_smallshow->setLayout(my_boxlayout);
    my_boxlayout->setContentsMargins(0,0,0,0);
    my_boxlayout->setSpacing(5);
}

RoomDialog::~RoomDialog()
{
    delete ui;
}

void RoomDialog::set_roomid(int roomid)
{
    ui->lb_room->setText(QString("房间号%1").arg(roomid));
}

void RoomDialog::slot_adduser(QWidget *Q)
{
    my_boxlayout->addWidget(Q);
}

void RoomDialog::slot_removeuser(QWidget *Q)
{
    Q->hide();
    my_boxlayout->removeWidget(Q);
    delete Q;
}

//退出房间后清空所有
void RoomDialog::slot_setRoomClear()
{
    //设置ui
    ui->cb_language->setCheckable(false);
    ui->cb_video->setCheckable(false);
    ui->cb_scshare->setCheckable(false);

    //发送信号
    Q_EMIT SIG_videoClose();
    Q_EMIT SIG_audioClose();
    Q_EMIT SIG_deskshareClose();
}

void RoomDialog::slot_setBigImage(int userid, QImage image)
{
    if(ui->wdg_bigshow->my_id == userid){
        ui->wdg_bigshow->slot_setImage(image);
    }
}

void RoomDialog::slot_setBigImageInfo(int userid, QString name)
{
    ui->wdg_bigshow->slot_setInfo(userid,name);
    my_usershow* user = (my_usershow*) QObject::sender();
}


void RoomDialog::on_pb_min_clicked()
{
    this->slot_showMin();
}

//隐藏用户列表
void RoomDialog::on_pushButton_clicked()
{
    if(ui->scrollArea->isHidden()){
        ui->scrollArea->show();
    }
    else{
        ui->scrollArea->hide();
    }
}

void RoomDialog::on_pb_max_clicked()
{
    this->slot_showMax();
}

void RoomDialog::on_pb_close_clicked()
{
    Q_EMIT SIG_quitRoom();
    this->close();
}


//退出房间
void RoomDialog::on_pb_exitroom_clicked()
{
    if(QMessageBox::question(this,"提示","是否要退出房间") == QMessageBox::Yes){
        Q_EMIT SIG_quitRoom();
        this->close();
    }
}

//语音按键
void RoomDialog::on_cb_language_clicked()
{
    if(ui->cb_language->isChecked()){
        Q_EMIT SIG_audioOpen();

    }
    else{

        Q_EMIT SIG_audioClose();

    }

}

//视频按键
void RoomDialog::on_cb_video_clicked()
{

    if(ui->cb_video->isChecked()){
        ui->cb_scshare->setCheckable(false);
        Q_EMIT SIG_deskshareClose();
        Q_EMIT SIG_videoOpen();

    }
    else{
        ui->cb_scshare->setCheckable(true);
        Q_EMIT SIG_videoClose();
    }
}

//屏幕共享按键
void RoomDialog::on_cb_scshare_clicked()
{
    if(ui->cb_scshare->isChecked()){
        ui->cb_video->setCheckable(false);
        Q_EMIT SIG_deskshareOpen();
        Q_EMIT SIG_videoClose();
    }
    else{
        ui->cb_video->setCheckable(true);
        Q_EMIT SIG_deskshareClose();
    }
}
