#ifndef VIDEO_COMMON_H
#define VIDEO_COMMON_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>


using namespace cv;

//帧数
#define FRAME_RATE (15)
//图片宽度
#define IMAGE_WIDTH (320)
//图片高度
#define IMAGE_HEIGHT (240)
//图片质量
#define IMAGE_QUALITY (50)

#endif // VIDEO_COMMON_H
