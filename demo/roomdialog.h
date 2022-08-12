#ifndef ROOMDIALOG_H
#define ROOMDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <customwidget.h>
#include <my_usershow.h>
#include <audio_collect.h>
#include <audio_play.h>
#include <video_read.h>
#include <video_show.h>
#include <QDebug>
#include <QString>
#include <QMessageBox>
namespace Ui {
class RoomDialog;
}

class RoomDialog : public CustomMoveDialog
{
    Q_OBJECT
signals:
    void SIG_quitRoom();
    //摄像头，音频，桌面共享的开启和关闭
    void SIG_audioOpen();
    void SIG_audioClose();
    void SIG_videoOpen();
    void SIG_videoClose();
    void SIG_deskshareOpen();
    void SIG_deskshareClose();
public:
    explicit RoomDialog(QWidget *parent = 0);
    ~RoomDialog();
public slots:
    void set_roomid(int roomid);
    void slot_adduser(QWidget* Q);
    void slot_removeuser(QWidget* Q);
    void slot_setRoomClear();
    void slot_setBigImage(int userid, QImage image);
    void slot_setBigImageInfo(int userid, QString name);
public:
    Ui::RoomDialog *ui;
    QVBoxLayout* my_boxlayout;
private slots:

    void on_pb_min_clicked();
    void on_pushButton_clicked();
    void on_pb_max_clicked();
    void on_pb_close_clicked();
    void on_pb_exitroom_clicked();
    void on_cb_language_clicked();
    void on_cb_video_clicked();
    void on_cb_scshare_clicked();



    //-----------------------------------------

};

#endif // ROOMDIALOG_H
