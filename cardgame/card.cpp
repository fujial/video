#include "card.h"
#include "ui_card.h"



card::card(QWidget *parent) :
    QWidget(parent),card_ATK(0),card_LIFE(0),card_COST(0),userid(0),card_ATK_num(0),
    ui(new Ui::card)
{
    ui->setupUi(this);
    set_cardInfo(card_ATK,card_LIFE,card_COST,0);
}

card::~card()
{
    delete ui;
}

//绘图
void card::paintEvent(QPaintEvent *event)
{
    //画背景
    QPainter painter(this);
    painter.setBrush(Qt::green);
    painter.drawRect(0,0,this->width(),this->height());

    //画的位置
    event->accept();
}




//鼠标点击
void card::mousePressEvent(QMouseEvent *event)
{
    Q_EMIT sig_cardselect();
}

//鼠标放下
void card::mouseReleaseEvent(QMouseEvent *event)
{
    Q_EMIT sig_usecard();
}

void card::set_cardATKnum(int num)
{
    card_ATK_num = num;
}

int card::get_cardATKnum()
{
    return card_ATK_num;
}

void card::set_cardInfo(int ATK, int LIFE, int COST,int user_id)
{
    card_ATK = ATK;
    card_LIFE = LIFE;
    card_COST = COST;
    userid = user_id;
    ui->lb_ACK->setText(QString(" 功%1").arg(ATK));
    ui->lb_LIFE->setText(QString("生%1").arg(LIFE));
    ui->lb_COST->setText(QString(" %1").arg(COST));
}

void card::set_cardOwner(int id)
{
    userid = id;
}
