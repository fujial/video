#ifndef LOGIN_DIALOG_H
#define LOGIN_DIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QMessageBox>
#include <QDebug>
#include <QRegExp>
namespace Ui {
class Login_Dialog;
}

class Login_Dialog : public QDialog
{
    Q_OBJECT

public:

    explicit Login_Dialog(QWidget *parent = 0);

    ~Login_Dialog();

    void closeEvent(QCloseEvent * event);

signals:
    //窗口关闭信号
    void SIG_close( );

    //提交按钮
    void SIG_login_commit(QString number,QString password);

    void SIG_register_commit(QString number,QString password);

private slots:

    void on_button_login_clear_clicked();

    void on_button_login_login_clicked();

    void on_register_confirm_clicked();

    void on_register_clear_clicked();

private:
    Ui::Login_Dialog *ui;
};

#endif // LOGIN_DIALOG_H
