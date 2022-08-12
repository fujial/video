#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QDebug>

enum card_state{ hand,player_fight,enemy_fight,death};
namespace Ui {
class card;
}

class card : public QWidget
{
    Q_OBJECT

public:
    explicit card(QWidget *parent = 0);
    int card_ATK;
    int card_LIFE;
    int card_COST;
    int userid;
    int card_ATK_num;
    ~card();
public slots:
    void paintEvent(QPaintEvent *event);
    //鼠标按下
    void mousePressEvent(QMouseEvent* event);
    //鼠标松开
    void mouseReleaseEvent(QMouseEvent* event);

    void set_cardATKnum(int num);
    
    int get_cardATKnum();
    
    void set_cardInfo(int ATK,int LIFE,int COST,int user_id);

    void set_cardOwner(int id);
signals:
    void sig_cardselect();
    void sig_usecard();
private:
    Ui::card *ui;
};

#endif // CARD_H
