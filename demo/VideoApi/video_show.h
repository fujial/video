#ifndef VIDEO_SHOW_H
#define VIDEO_SHOW_H

#include <QObject>
#include <QTimer>
#include <QApplication>
#include <QDesktopWidget>
#include <QBuffer>
#include <QScreen>
#include <QImage>
#include <video_common.h>
class video_show : public QObject
{
    Q_OBJECT
public:
    explicit video_show(QObject *parent = 0);
    ~video_show();
signals:
    void SIG_screenFrame( QImage& image);
    void SIG_screenFrameData( QByteArray& ba );
public slots:
    void start();
    void pause();
    void slot_getDeskImage();
private:
    QTimer* m_timer;
};

#endif // VIDEO_SHOW_H
