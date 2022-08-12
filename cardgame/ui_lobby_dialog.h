/********************************************************************************
** Form generated from reading UI file 'lobby_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOBBY_DIALOG_H
#define UI_LOBBY_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_lobby_dialog
{
public:
    QPushButton *pb_icon;
    QWidget *wdg_menu;
    QPushButton *pb_fightmode;
    QPushButton *pb_practicemode;
    QPushButton *pb_set;
    QLabel *lb_id;
    QLabel *lb_name;
    QPushButton *pb_leave;

    void setupUi(QDialog *lobby_dialog)
    {
        if (lobby_dialog->objectName().isEmpty())
            lobby_dialog->setObjectName(QStringLiteral("lobby_dialog"));
        lobby_dialog->resize(960, 720);
        lobby_dialog->setMinimumSize(QSize(960, 720));
        lobby_dialog->setMaximumSize(QSize(960, 720));
        pb_icon = new QPushButton(lobby_dialog);
        pb_icon->setObjectName(QStringLiteral("pb_icon"));
        pb_icon->setGeometry(QRect(0, 0, 90, 90));
        wdg_menu = new QWidget(lobby_dialog);
        wdg_menu->setObjectName(QStringLiteral("wdg_menu"));
        wdg_menu->setGeometry(QRect(160, 70, 640, 480));
        pb_fightmode = new QPushButton(wdg_menu);
        pb_fightmode->setObjectName(QStringLiteral("pb_fightmode"));
        pb_fightmode->setGeometry(QRect(200, 40, 240, 60));
        pb_practicemode = new QPushButton(wdg_menu);
        pb_practicemode->setObjectName(QStringLiteral("pb_practicemode"));
        pb_practicemode->setGeometry(QRect(200, 140, 240, 60));
        pb_set = new QPushButton(lobby_dialog);
        pb_set->setObjectName(QStringLiteral("pb_set"));
        pb_set->setGeometry(QRect(880, 0, 40, 30));
        lb_id = new QLabel(lobby_dialog);
        lb_id->setObjectName(QStringLiteral("lb_id"));
        lb_id->setGeometry(QRect(380, 0, 90, 30));
        lb_name = new QLabel(lobby_dialog);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setGeometry(QRect(480, 0, 90, 30));
        pb_leave = new QPushButton(lobby_dialog);
        pb_leave->setObjectName(QStringLiteral("pb_leave"));
        pb_leave->setGeometry(QRect(920, 0, 40, 30));

        retranslateUi(lobby_dialog);

        QMetaObject::connectSlotsByName(lobby_dialog);
    } // setupUi

    void retranslateUi(QDialog *lobby_dialog)
    {
        lobby_dialog->setWindowTitle(QApplication::translate("lobby_dialog", "Dialog", 0));
        pb_icon->setText(QApplication::translate("lobby_dialog", "\347\224\250\346\210\267\345\244\264\345\203\217", 0));
        pb_fightmode->setText(QApplication::translate("lobby_dialog", "\345\257\271\346\210\230\346\250\241\345\274\217", 0));
        pb_practicemode->setText(QApplication::translate("lobby_dialog", "\347\273\203\344\271\240\346\250\241\345\274\217", 0));
        pb_set->setText(QApplication::translate("lobby_dialog", "\350\256\276\347\275\256", 0));
        lb_id->setText(QApplication::translate("lobby_dialog", "\347\224\250\346\210\267id", 0));
        lb_name->setText(QString());
        pb_leave->setText(QApplication::translate("lobby_dialog", "\351\200\200\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class lobby_dialog: public Ui_lobby_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBY_DIALOG_H
