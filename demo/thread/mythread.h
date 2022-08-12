#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include<QDebug>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

signals:
    void SIG_doWork();
public slots:
    void run(); //线程函数
};

#endif // MYTHREAD_H
