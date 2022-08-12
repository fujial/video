#include "video_read.h"
//#include "facedefect.h"

video_read::video_read(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer;
//    faceDefect::FaceDetectInit();
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slot_video_readmore()));
}

video_read::~video_read()
{
    m_timer->stop();
    delete m_timer;
}

void video_read::slot_video_start()
{

    cap.open(0);//打开默认摄像头
    if(!cap.isOpened()){
        QMessageBox::information(NULL,tr("提示"),tr("视频没有打开"));
        return;
    }
    //用一秒钟除以帧率
    m_timer->start(1000/FRAME_RATE);
}

void video_read::slot_video_pause()
{
    if(cap.isOpened()){
        cap.release();
    }
}

void video_read::slot_video_readmore()
{
    //获取摄像头
    Mat frame;
    if(!cap.read(frame)){
        return;
    }
    //将opencv采集的BGR的图片类型转化为 RGB24的类型
    cvtColor(frame,frame,CV_BGR2RGB);

//    std::vector<Rect> face;
//    faceDefect::detectAndDisplay(frame,face);

    //定义QImage对象,用于发送数据以及图片显示
    QImage image((unsigned const char*)frame.data,frame.cols,frame.rows,QImage::Format_RGB888);
    //转化为大小更小的图片
    image = image.scaled(IMAGE_WIDTH,IMAGE_HEIGHT,Qt::KeepAspectRatio);

    Q_EMIT SIG_videoShow(image);


    //编码发送
    //压缩图片从 RGB24 格式压缩到 JPEG 格式, 发送出去
    QByteArray ba;
    QBuffer qbuf(&ba); // QBuffer 与 QByteArray 字节数组联立联系
    image.save( &qbuf , "JPEG" , IMAGE_QUALITY ); //将图片的数据写入 ba

    Q_EMIT SIG_videoDate(ba);

}
