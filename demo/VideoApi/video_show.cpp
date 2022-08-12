#include "video_show.h"
video_show::video_show(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer;
    connect(m_timer,SIGNAL(timeout()),
            this,SLOT(slot_getDeskImage()));
}

video_show::~video_show()
{
    if(m_timer){
        delete m_timer;
        m_timer = NULL;
    }
}

//开始采集
void video_show::start()
{
    m_timer->start(1000/FRAME_RATE);
}

//暂停
void video_show::pause()
{
    m_timer->stop();
}

//发送
void video_show::slot_getDeskImage()
{
    //获取桌面
    QScreen *src = QApplication::primaryScreen();
    // QRect deskRect = QApplication::desktop()->screenGeometry();
    //转化为图片
    QPixmap map = src->grabWindow( QApplication::desktop()->winId()/* ,0,0 , deskRect.width() , deskRect.height()*/);
    QImage image = map.toImage();
    //发送数据太大，会导致卡顿
    image = image.scaled( 1600, 900, Qt::KeepAspectRatio, Qt::SmoothTransformation );
    Q_EMIT SIG_screenFrame(image);
    //压缩图片从RGB24格式压缩到 JPEG 格式, 发送出去
    QByteArray ba;
    QBuffer qbuf(&ba); // QBuffer 与 QByteArray 字节数组联立联系
    image.save( &qbuf , "JPEG" , IMAGE_QUALITY ); //将图片的数据写入 ba
    Q_EMIT SIG_screenFrameData( ba );
}
