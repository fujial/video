#ifndef LOBBY_DIALOG_H
#define LOBBY_DIALOG_H

#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QString>
namespace Ui {
class lobby_dialog;
}

class lobby_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit lobby_dialog(QWidget *parent = 0);
    ~lobby_dialog();
    void closeEvent(QCloseEvent * event);

signals:
    void SIG_close();
    void SIG_showroom();
    void SIG_UserInfo();

public slots:
    void on_pb_fightmode_clicked();
    void on_pb_icon_clicked();
    void slot_setUserInfo(int icon_id,int user_id,QString my_name);

private slots:
    void on_pb_leave_clicked();

private:
    Ui::lobby_dialog*   ui;
    int                 iconid;
    int                 userid;
    QString             name;
};

#endif // LOBBY_DIALOG_H
