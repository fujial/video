#include "set_user.h"
#include "ui_set_user.h"

set_user::set_user(QWidget *parent) :
    QDialog(parent),my_iconid(0),
    ui(new Ui::set_user)
{
    ui->setupUi(this);
    for(int i = 0; i < 36; i++){
        ui->cbx_icon->addItem(QIcon(QString(":/tx/%1.png").arg(i)),"");
    }
}

set_user::~set_user()
{
    delete ui;
}

//清空
void set_user::on_pb_clear_clicked()
{
    ui->le_name->setText("");
}

//提交
void set_user::on_pb_emit_clicked()
{
    int iconid = ui->cbx_icon->currentIndex();
    QString str_name = ui->le_name->text();
    //提交
    this->hide();
    Q_EMIT SIG_Setuser_Commit(iconid,str_name);
    slot_setInfo(iconid,str_name);
}

//更新用户信息
void set_user::slot_setInfo(int iconid, QString name)
{
    my_iconid = iconid;
    my_name = name;
    ui->cbx_icon->setCurrentIndex(iconid);
    ui->le_name->setText(name);
}
