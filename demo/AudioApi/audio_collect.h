#ifndef AUDIO_COLLECT_H
#define AUDIO_COLLECT_H

#include <QObject>
#include <QTimer>
#include "audio_common.h"

class Audio_collect : public QObject
{
    Q_OBJECT
public:
    explicit Audio_collect(QObject *parent = 0);
    ~Audio_collect();
    //数据采集状态位，初始化状态为Stop , 开始状态为 Record , 暂停状态为 Pause , 先判断再执行开始和暂停
    enum audio_state{Stop, Record, Pause};
signals:
    //定时采集数据，以信号形式发送
    void SIG_audioFrame(QByteArray& );


public slots:
    //开始采集
    void slot_audiostart();
    //停止采集
    void slot_audiopause();
    //定时发送
    void slot_timesend();
    //
private:
        QAudioFormat        format;
        QTimer*             my_timer;
        QAudioInput*        audio_in;
        QIODevice*          myBuffer_in;
        int                 my_stateRecord;
        //SPEEX 相关变量
        SpeexBits           bits_enc;
        void*               Enc_State;
};

#endif // AUDIO_COLLECT_H
