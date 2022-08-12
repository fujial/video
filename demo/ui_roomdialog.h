/********************************************************************************
** Form generated from reading UI file 'roomdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOMDIALOG_H
#define UI_ROOMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <my_usershow.h>

QT_BEGIN_NAMESPACE

class Ui_RoomDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_top;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_room;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pb_min;
    QPushButton *pb_max;
    QPushButton *pb_close;
    QWidget *wdg_mid;
    my_usershow *wdg_bigshow;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *wdg_smallshow;
    QSpacerItem *verticalSpacer;
    QWidget *wdg_end;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cb_language;
    QCheckBox *cb_video;
    QCheckBox *cb_scshare;
    QLabel *lb_filter;
    QComboBox *cb_filter;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_exitroom;

    void setupUi(QDialog *RoomDialog)
    {
        if (RoomDialog->objectName().isEmpty())
            RoomDialog->setObjectName(QStringLiteral("RoomDialog"));
        RoomDialog->resize(800, 600);
        RoomDialog->setMinimumSize(QSize(800, 600));
        RoomDialog->setMaximumSize(QSize(1080, 960));
        verticalLayout = new QVBoxLayout(RoomDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_top = new QWidget(RoomDialog);
        wdg_top->setObjectName(QStringLiteral("wdg_top"));
        wdg_top->setMinimumSize(QSize(0, 80));
        wdg_top->setMaximumSize(QSize(16777215, 80));
        horizontalLayout = new QHBoxLayout(wdg_top);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lb_room = new QLabel(wdg_top);
        lb_room->setObjectName(QStringLiteral("lb_room"));
        lb_room->setMinimumSize(QSize(120, 20));
        lb_room->setMaximumSize(QSize(120, 20));

        horizontalLayout->addWidget(lb_room);

        horizontalSpacer = new QSpacerItem(480, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(wdg_top);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(35, 35));
        pushButton->setMaximumSize(QSize(35, 35));

        horizontalLayout->addWidget(pushButton);

        pb_min = new QPushButton(wdg_top);
        pb_min->setObjectName(QStringLiteral("pb_min"));
        pb_min->setMinimumSize(QSize(35, 35));
        pb_min->setMaximumSize(QSize(35, 35));

        horizontalLayout->addWidget(pb_min);

        pb_max = new QPushButton(wdg_top);
        pb_max->setObjectName(QStringLiteral("pb_max"));
        pb_max->setMinimumSize(QSize(35, 35));
        pb_max->setMaximumSize(QSize(35, 35));

        horizontalLayout->addWidget(pb_max);

        pb_close = new QPushButton(wdg_top);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setMinimumSize(QSize(0, 35));
        pb_close->setMaximumSize(QSize(35, 35));

        horizontalLayout->addWidget(pb_close);


        verticalLayout->addWidget(wdg_top);

        wdg_mid = new QWidget(RoomDialog);
        wdg_mid->setObjectName(QStringLiteral("wdg_mid"));
        wdg_bigshow = new my_usershow(wdg_mid);
        wdg_bigshow->setObjectName(QStringLiteral("wdg_bigshow"));
        wdg_bigshow->setGeometry(QRect(0, 0, 580, 459));
        scrollArea = new QScrollArea(wdg_mid);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(580, 0, 220, 461));
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setMaximumSize(QSize(220, 16777215));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 170, 459));
        scrollAreaWidgetContents->setMinimumSize(QSize(170, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(170, 16777215));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        wdg_smallshow = new QWidget(scrollAreaWidgetContents);
        wdg_smallshow->setObjectName(QStringLiteral("wdg_smallshow"));
        wdg_smallshow->setMinimumSize(QSize(200, 0));
        wdg_smallshow->setMaximumSize(QSize(200, 16777215));

        verticalLayout_2->addWidget(wdg_smallshow);

        verticalSpacer = new QSpacerItem(20, 446, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(wdg_mid);

        wdg_end = new QWidget(RoomDialog);
        wdg_end->setObjectName(QStringLiteral("wdg_end"));
        wdg_end->setMinimumSize(QSize(0, 61));
        wdg_end->setMaximumSize(QSize(16777215, 61));
        horizontalLayout_2 = new QHBoxLayout(wdg_end);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        cb_language = new QCheckBox(wdg_end);
        cb_language->setObjectName(QStringLiteral("cb_language"));

        horizontalLayout_2->addWidget(cb_language);

        cb_video = new QCheckBox(wdg_end);
        cb_video->setObjectName(QStringLiteral("cb_video"));

        horizontalLayout_2->addWidget(cb_video);

        cb_scshare = new QCheckBox(wdg_end);
        cb_scshare->setObjectName(QStringLiteral("cb_scshare"));

        horizontalLayout_2->addWidget(cb_scshare);

        lb_filter = new QLabel(wdg_end);
        lb_filter->setObjectName(QStringLiteral("lb_filter"));

        horizontalLayout_2->addWidget(lb_filter);

        cb_filter = new QComboBox(wdg_end);
        cb_filter->setObjectName(QStringLiteral("cb_filter"));

        horizontalLayout_2->addWidget(cb_filter);

        horizontalSpacer_2 = new QSpacerItem(322, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pb_exitroom = new QPushButton(wdg_end);
        pb_exitroom->setObjectName(QStringLiteral("pb_exitroom"));

        horizontalLayout_2->addWidget(pb_exitroom);


        verticalLayout->addWidget(wdg_end);


        retranslateUi(RoomDialog);

        QMetaObject::connectSlotsByName(RoomDialog);
    } // setupUi

    void retranslateUi(QDialog *RoomDialog)
    {
        RoomDialog->setWindowTitle(QApplication::translate("RoomDialog", "Dialog", 0));
        lb_room->setText(QApplication::translate("RoomDialog", "fangjian", 0));
        pushButton->setText(QApplication::translate("RoomDialog", "1", 0));
        pb_min->setText(QApplication::translate("RoomDialog", "-", 0));
        pb_max->setText(QApplication::translate("RoomDialog", "O", 0));
        pb_close->setText(QApplication::translate("RoomDialog", "X", 0));
        cb_language->setText(QApplication::translate("RoomDialog", "\350\257\255\351\237\263", 0));
        cb_video->setText(QApplication::translate("RoomDialog", "\350\247\206\351\242\221", 0));
        cb_scshare->setText(QApplication::translate("RoomDialog", "\345\261\217\345\271\225\345\205\261\344\272\253", 0));
        lb_filter->setText(QApplication::translate("RoomDialog", "\346\273\244\351\225\234", 0));
        cb_filter->clear();
        cb_filter->insertItems(0, QStringList()
         << QApplication::translate("RoomDialog", "\346\227\240", 0)
         << QApplication::translate("RoomDialog", "\345\205\224\345\255\220\350\200\263\346\234\265", 0)
         << QApplication::translate("RoomDialog", "and so on", 0)
        );
        pb_exitroom->setText(QApplication::translate("RoomDialog", "\351\200\200\345\207\272\346\210\277\351\227\264", 0));
    } // retranslateUi

};

namespace Ui {
    class RoomDialog: public Ui_RoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOMDIALOG_H
