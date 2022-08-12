#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include<QDebug>
#include<TcpClientMediator.h>
#include<TcpServerMediator.h>
namespace Ui {
class Mainwindow;
}

class Mainwindow : public QWidget
{
    Q_OBJECT

public:
    explicit Mainwindow(QWidget *parent = 0);
    ~Mainwindow();

private:
    Ui::Mainwindow *ui;
};

#endif // MAINWINDOW_H
