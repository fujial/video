#ifndef WAIT_DIALOG_H
#define WAIT_DIALOG_H

#include <QDialog>
#include "common.h"
namespace Ui {
class wait_dialog;
}

class wait_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit wait_dialog(QWidget *parent = 0);
    ~wait_dialog();
    void closeEvent(QCloseEvent * event);
signals:
    void SIG_createroom();
    void SIG_joinroom();
    void SIG_close();
    void SIG_return();
private slots:
    void on_pb_joinroom_clicked();
    
    void on_pb_createroom_clicked();
    
    void on_pb_return_clicked();

private:
    Ui::wait_dialog *ui;
};

#endif // WAIT_DIALOG_H
