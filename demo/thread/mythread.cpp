#include "mythread.h"


MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    qDebug() <<"MyThread::run():" << QThread::currentThreadId();
    Q_EMIT SIG_doWork();
    qDebug() <<"MyThread::end()" ;
}
