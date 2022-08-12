QT      += multimedia


HEADERS += \
    $$PWD/audio_collect.h \
    $$PWD/audio_play.h \
    $$PWD/audio_common.h

SOURCES += \
    $$PWD/audio_collect.cpp \
    $$PWD/audio_play.cpp



LIBS += $$PWD/speex/lib/libspeex.lib\
