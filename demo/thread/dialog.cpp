#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog), m_fileThread( new fileThread )
{
    ui->setupUi(this);

    m_thread = new MyThread;
    connect( m_thread , SIGNAL(SIG_doWork())
             , this , SLOT( slot_dowork() )  );

    connect( this , SIGNAL( SIG_doFileWork())
             , m_fileThread.get() /*获取里面的指针*/
             , SLOT( slot_fileWork())  );

    connect( m_fileThread.get() , SIGNAL(SIG_hello()) ,
             this , SLOT( slot_recvHello() ) );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::slot_recvHello()
{
    qDebug() << "Dialog::slot_recvHello()"<<QThread::currentThreadId();
}

void Dialog::on_pb_start_clicked()
{
    //主线程id
    qDebug() << "Dialog::on_pb_start_clicked()"<<QThread::currentThreadId();
    m_thread->start();// 开启线程的run函数
}

void Dialog::slot_dowork()
{
    qDebug()<< "Dialog::slot_dowork()" << QThread::currentThreadId();
}


void Dialog::on_pb_startFileWork_clicked()
{
    qDebug() << "Dialog::on_pb_startFileWork_clicked()"<<QThread::currentThreadId();
    Q_EMIT SIG_doFileWork();
}

