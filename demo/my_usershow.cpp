#include "my_usershow.h"
#include "ui_my_usershow.h"

my_usershow::my_usershow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::my_usershow)
{
    ui->setupUi(this);
}

my_usershow::~my_usershow()
{
    delete ui;
}

void my_usershow::slot_setImage(QImage image)
{
    my_image = image;
    //更新触发绘图事件
    repaint();

}

void my_usershow::slot_setInfo(int id, QString name)
{
    my_id = id;
    my_name = name;
    ui->lb_name->setText(QString("用户:%1 用户id:%2").arg(name).arg(id));
}

void my_usershow::paintEvent(QPaintEvent *event)
{
    //画背景
    QPainter painter(this);
    painter.setBrush(Qt::black);
    painter.drawRect(0,0,this->width(),this->height());

    //画人物
    //画图片
    if( my_image.size().height()<= 0 )
        return;
    // 加载图片用 QImage , 画图使用 QPixmap
    // 图片缩放 scaled
    QPixmap pixmap = QPixmap::fromImage( my_image.scaled( QSize( this->width() ,
                                                                this->height() - ui->lb_name->height()), Qt::KeepAspectRatio ));
    //画的位置
    int x = this->width() - pixmap.width();
    int y = this->height() - pixmap.height() - ui->lb_name->height();
    x = x /2;
    y = ui->lb_name->height() + y/2;
    painter.drawPixmap( QPoint(x,y) , pixmap );
    painter.end();
    event->accept();
}

void my_usershow::mousePressEvent(QMouseEvent *event)
{
    Q_EMIT SIG_userClicked(my_id,my_name);
    event->accept();
}
