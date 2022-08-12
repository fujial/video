#include "login_dialog.h"
#include "ui_login_dialog.h"

Login_Dialog::Login_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login_Dialog)
{
    ui->setupUi(this);
}

Login_Dialog::~Login_Dialog()
{
    delete ui;
}

void Login_Dialog::closeEvent(QCloseEvent * event)
{
    if( QMessageBox::question(this,"提示","是否关闭") == QMessageBox::Yes){
        Q_EMIT SIG_close();
    }
    else{
        event->ignore();//忽略
    }
}


//登陆清空
void Login_Dialog::on_button_login_clear_clicked()
{
    ui->line_number->setText("");
    ui->line_password->setText("");
}

//登陆确认
void Login_Dialog::on_button_login_login_clicked()
{
    //输入规范
    QString strnumber = ui->line_number->text();
    QString strpassword = ui->line_password->text();
    if(strnumber.isEmpty()||strpassword.isEmpty()){
        QMessageBox::about(this,"提示","输入不能为空");
        return;
    }
    QRegExp reg("^1[3-8][0-9]\{6,9\}$");
    bool res = reg.exactMatch(strnumber);
    if(!res){
        QMessageBox::about(this,"提示","输入手机号非法");
        return;
    }
    if(strpassword.length() > 20){
        QMessageBox::about(this,"提示","密码不能大于二十位");
        return;
    }
    Q_EMIT SIG_login_commit(strnumber,strpassword);
}
//注册确认
void Login_Dialog::on_register_confirm_clicked()
{
    //输入规范
    QString strnumber = ui->register_line_number->text();
    QString strpassword = ui->register_line_password->text();
    QString strconfirmpassoword = ui->register_confirm_line_password->text();
    if(strnumber.isEmpty()||strpassword.isEmpty()||strconfirmpassoword.isEmpty()){
        QMessageBox::about(this,"提示","输入不能为空");
        return;
    }
    QRegExp reg("^1[3-8][0-9]\{6,9\}$");
    bool res = reg.exactMatch(strnumber);
    if(!res){
        QMessageBox::about(this,"提示","输入手机号非法");
        return;
    }
    if(strpassword.length() > 20){
        QMessageBox::about(this,"提示","密码不能大于二十位");
        return;
    }
    if(strpassword!=strconfirmpassoword){
        QMessageBox::about(this,"提示","两次输入不一致");
        return;
    }
    Q_EMIT SIG_register_commit(strnumber,strpassword);
}

//注册清空
void Login_Dialog::on_register_clear_clicked()
{
    ui->register_line_number->setText("");
    ui->register_line_password->setText("");
    ui->register_confirm_line_password->setText("");
}
