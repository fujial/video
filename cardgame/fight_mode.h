#ifndef FIGHT_MODE_H
#define FIGHT_MODE_H

#include <QObject>

class fight_mode : public QObject
{
    Q_OBJECT
public:
    explicit fight_mode(QObject *parent = 0);
    virtual ~fight_mode(){}
signals:

public:
    //回合开始
    void round_begin();
    //回合结束
    virtual void round_end(){}
    //胜负判定
    virtual void choose_winner(){}

    int roomid;
    int playerid;
    int enemyid;
public slots:
};
class fight_mode_standard:fight_mode
{
public:
    fight_mode_standard();
    ~fight_mode_standard();
public:
    int roomid;
    int playerid;
    int enemyid;
};

#endif // FIGHT_MODE_H
