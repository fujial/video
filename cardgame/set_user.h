#ifndef SET_USER_H
#define SET_USER_H

#include <QDialog>
#include <QDebug>
namespace Ui {
class set_user;
}

class set_user : public QDialog
{
    Q_OBJECT

public:
    explicit set_user(QWidget *parent = 0);
    ~set_user();

signals:
    void SIG_Setuser_Commit(int conid, QString name);
public slots:
    void on_pb_clear_clicked();

    void on_pb_emit_clicked();

    void slot_setInfo(int iconid, QString name);

private:
    Ui::set_user *ui;
    int my_iconid;
    QString  my_name;
};

#endif // SET_USER_H
