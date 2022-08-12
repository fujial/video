#include "lobby_dialog.h"
#include "ui_lobby_dialog.h"

lobby_dialog::lobby_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::lobby_dialog)
{
    ui->setupUi(this);
    this->setWindowFlags( Qt::FramelessWindowHint );

}

lobby_dialog::~lobby_dialog()
{
    delete ui;
}

void lobby_dialog::closeEvent(QCloseEvent *event)
{
    if( QMessageBox::question(this,"提示","是否关闭") == QMessageBox::Yes){
        Q_EMIT SIG_close();
    }
    else{
        event->ignore();//忽略
    }
}
//对战模式
void lobby_dialog::on_pb_fightmode_clicked()
{
    Q_EMIT SIG_showroom();
}

//点击头像
void lobby_dialog::on_pb_icon_clicked()
{
    Q_EMIT SIG_UserInfo();
}

void lobby_dialog::slot_setUserInfo(int icon_id, int user_id, QString my_name)
{
    ui->lb_id->setText(QString("userid:%1").arg(user_id));
    ui->lb_name->setText(QString("name:%1").arg(my_name));
    iconid = icon_id;
    userid = user_id;
    name = my_name;
}


//退出房间按钮
void lobby_dialog::on_pb_leave_clicked()
{
    if( QMessageBox::question(this,"提示","是否退出登陆") == QMessageBox::Yes){
        Q_EMIT SIG_close();
    }
    else{
        //忽略
    }
}
