#include "wait_dialog.h"
#include "ui_wait_dialog.h"

wait_dialog::wait_dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wait_dialog)
{
    ui->setupUi(this);
}

wait_dialog::~wait_dialog()
{
    delete ui;
}

void wait_dialog::closeEvent(QCloseEvent *event)
{
    if( QMessageBox::question(this,"提示","是否关闭") == QMessageBox::Yes){
        Q_EMIT SIG_close();
    }
    else{
        event->ignore();//忽略
    }
}

//加入房间
void wait_dialog::on_pb_joinroom_clicked()
{
    Q_EMIT SIG_joinroom();
}
//创建房间
void wait_dialog::on_pb_createroom_clicked()
{
    Q_EMIT SIG_createroom();
}

//返回上一个界面
void wait_dialog::on_pb_return_clicked()
{
    Q_EMIT SIG_return();
}
