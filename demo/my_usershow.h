#ifndef MY_USERSHOW_H
#define MY_USERSHOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
namespace Ui {
class my_usershow;
}

class my_usershow : public QWidget
{
    Q_OBJECT

public:
    class CControl;
    explicit my_usershow(QWidget *parent = 0);
    ~my_usershow();
signals:
    void SIG_userClicked(int my_id,QString my_name);
public slots:
    void slot_setImage(QImage image);
    void slot_setInfo(int id, QString name);
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
public:
    int my_id;
    Ui::my_usershow *ui;
    QImage my_image;
    QString my_name;
    friend class CControl;
};

#endif // MY_USERSHOW_H
