#ifndef VIDEO_READ_H
#define VIDEO_READ_H

#include <QObject>
#include <QTimer>
#include <video_common.h>
#include <QMessageBox>
#include <QBuffer>
class video_read : public QObject
{
    Q_OBJECT
public:
    explicit video_read(QObject *parent = 0);
    ~video_read();
signals:
    //阻塞send会导致发送卡顿，应采用多线程发送，避免传入引用导致对象被回收
    void SIG_videoShow(QImage& img);
    void SIG_videoDate(QByteArray& byte_arr);
public slots:
    void slot_video_start();
    void slot_video_pause();
    void slot_video_readmore();
private:
    //摄像头对象
    cv::VideoCapture    cap;
    QTimer*             m_timer;
};

#endif // VIDEO_READ_H
