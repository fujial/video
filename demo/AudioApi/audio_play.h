#ifndef AUDIO_PLAY_H
#define AUDIO_PLAY_H

#include <QObject>
#include <audio_common.h>

class Audio_play : public QObject
{
    Q_OBJECT
public:
    explicit Audio_play(QObject *parent = 0);
    ~Audio_play();
signals:

public slots:
    void slot_net_rx(QByteArray& ba);

private:
    QAudioFormat        format;
    QAudioOutput*       audio_out;
    QIODevice*          myBuffer_out;
    //SPEEX 相关全局变量
    SpeexBits           bits_dec;
    void*               Dec_State;
};

#endif // AUDIO_PLAY_H
