INCLUDEPATH += E:/opencv-4.2.0/opencv/build/install/include

LIBS += E:/opencv-4.2.0/opencv/build/lib/libopencv_*.a



HEADERS += \
    $$PWD/video_common.h \
    $$PWD/video_read.h \
    $$PWD/video_show.h

SOURCES += \
    $$PWD/video_read.cpp \
    $$PWD/video_show.cpp
