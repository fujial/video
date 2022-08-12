#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"mythread.h"


#include"workthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class fileThread :public WorkThread
{
    Q_OBJECT
signals:
    void SIG_hello();
public:

public slots:
    void slot_fileWork()
    {
        qDebug() << "fileThread::slot_fileWork()" << QThread::currentThreadId();
        Q_EMIT SIG_hello();
        qDebug() << "fileThread::end()" ;
    }
};

//qt 里面的智能指针 自动回收
#include<QSharedPointer>

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:
    void SIG_doFileWork();

private slots:
    void on_pb_start_clicked();

    void slot_dowork();

    void on_pb_startFileWork_clicked();

    void slot_recvHello();
private:
    Ui::Dialog *ui;

    MyThread *m_thread;
    QSharedPointer<fileThread> m_fileThread;
};
#endif // DIALOG_H
