/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DemoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *wdg_content;
    QVBoxLayout *verticalLayout_2;
    QWidget *wdg_tittle;
    QHBoxLayout *horizontalLayout;
    QLabel *lb_tittle_icon;
    QLabel *lb_tittle;
    QSpacerItem *horizontalSpacer;
    QPushButton *pb_min;
    QPushButton *pb_close;
    QWidget *wdg_user;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pb_icon;
    QLabel *lb_name;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pb_setup;
    QWidget *wdg_room;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *pb_join;
    QToolButton *pb_create;
    QToolButton *pb_history;
    QWidget *wdg_bottom;

    void setupUi(QDialog *DemoDialog)
    {
        if (DemoDialog->objectName().isEmpty())
            DemoDialog->setObjectName(QStringLiteral("DemoDialog"));
        DemoDialog->resize(336, 600);
        DemoDialog->setMinimumSize(QSize(336, 600));
        DemoDialog->setMaximumSize(QSize(336, 600));
        DemoDialog->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(DemoDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        wdg_content = new QWidget(DemoDialog);
        wdg_content->setObjectName(QStringLiteral("wdg_content"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        wdg_content->setFont(font);
        wdg_content->setStyleSheet(QLatin1String("background-color: rgb(66, 66, 66);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(wdg_content);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        wdg_tittle = new QWidget(wdg_content);
        wdg_tittle->setObjectName(QStringLiteral("wdg_tittle"));
        wdg_tittle->setMinimumSize(QSize(100, 40));
        wdg_tittle->setMaximumSize(QSize(16777215, 40));
        horizontalLayout = new QHBoxLayout(wdg_tittle);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lb_tittle_icon = new QLabel(wdg_tittle);
        lb_tittle_icon->setObjectName(QStringLiteral("lb_tittle_icon"));
        lb_tittle_icon->setMinimumSize(QSize(30, 30));
        lb_tittle_icon->setMaximumSize(QSize(30, 30));
        lb_tittle_icon->setPixmap(QPixmap(QString::fromUtf8(":/bq/0.png")));
        lb_tittle_icon->setScaledContents(true);

        horizontalLayout->addWidget(lb_tittle_icon);

        lb_tittle = new QLabel(wdg_tittle);
        lb_tittle->setObjectName(QStringLiteral("lb_tittle"));
        lb_tittle->setMinimumSize(QSize(0, 30));
        lb_tittle->setFont(font);

        horizontalLayout->addWidget(lb_tittle);

        horizontalSpacer = new QSpacerItem(190, 15, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pb_min = new QPushButton(wdg_tittle);
        pb_min->setObjectName(QStringLiteral("pb_min"));
        pb_min->setMinimumSize(QSize(30, 30));
        pb_min->setMaximumSize(QSize(30, 30));
        pb_min->setFont(font);
        pb_min->setFocusPolicy(Qt::NoFocus);
        pb_min->setFlat(true);

        horizontalLayout->addWidget(pb_min);

        pb_close = new QPushButton(wdg_tittle);
        pb_close->setObjectName(QStringLiteral("pb_close"));
        pb_close->setMinimumSize(QSize(30, 30));
        pb_close->setMaximumSize(QSize(30, 30));
        pb_close->setFont(font);
        pb_close->setFocusPolicy(Qt::NoFocus);
        pb_close->setFlat(true);

        horizontalLayout->addWidget(pb_close);


        verticalLayout_2->addWidget(wdg_tittle);

        wdg_user = new QWidget(wdg_content);
        wdg_user->setObjectName(QStringLiteral("wdg_user"));
        wdg_user->setMinimumSize(QSize(0, 60));
        wdg_user->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_2 = new QHBoxLayout(wdg_user);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pb_icon = new QPushButton(wdg_user);
        pb_icon->setObjectName(QStringLiteral("pb_icon"));
        pb_icon->setMinimumSize(QSize(50, 50));
        pb_icon->setMaximumSize(QSize(50, 50));
        QIcon icon;
        icon.addFile(QStringLiteral(":/tx/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_icon->setIcon(icon);
        pb_icon->setIconSize(QSize(50, 50));

        horizontalLayout_2->addWidget(pb_icon);

        lb_name = new QLabel(wdg_user);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setMinimumSize(QSize(0, 50));
        lb_name->setFont(font);

        horizontalLayout_2->addWidget(lb_name);

        horizontalSpacer_2 = new QSpacerItem(207, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pb_setup = new QPushButton(wdg_user);
        pb_setup->setObjectName(QStringLiteral("pb_setup"));
        pb_setup->setMinimumSize(QSize(30, 30));
        pb_setup->setMaximumSize(QSize(30, 30));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/sett.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_setup->setIcon(icon1);
        pb_setup->setFlat(true);

        horizontalLayout_2->addWidget(pb_setup);


        verticalLayout_2->addWidget(wdg_user);

        wdg_room = new QWidget(wdg_content);
        wdg_room->setObjectName(QStringLiteral("wdg_room"));
        wdg_room->setMinimumSize(QSize(0, 100));
        wdg_room->setMaximumSize(QSize(16777215, 100));
        wdg_room->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(wdg_room);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pb_join = new QToolButton(wdg_room);
        pb_join->setObjectName(QStringLiteral("pb_join"));
        pb_join->setMinimumSize(QSize(100, 80));
        pb_join->setMaximumSize(QSize(100, 80));
        pb_join->setFont(font);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/color.png"), QSize(), QIcon::Normal, QIcon::Off);
        pb_join->setIcon(icon2);
        pb_join->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pb_join->setAutoRaise(true);

        horizontalLayout_3->addWidget(pb_join);

        pb_create = new QToolButton(wdg_room);
        pb_create->setObjectName(QStringLiteral("pb_create"));
        pb_create->setMinimumSize(QSize(100, 80));
        pb_create->setMaximumSize(QSize(100, 80));
        pb_create->setFont(font);
        pb_create->setIcon(icon2);
        pb_create->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pb_create->setAutoRaise(true);

        horizontalLayout_3->addWidget(pb_create);

        pb_history = new QToolButton(wdg_room);
        pb_history->setObjectName(QStringLiteral("pb_history"));
        pb_history->setMinimumSize(QSize(100, 80));
        pb_history->setMaximumSize(QSize(100, 80));
        pb_history->setFont(font);
        pb_history->setIcon(icon2);
        pb_history->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        pb_history->setAutoRaise(true);

        horizontalLayout_3->addWidget(pb_history);


        verticalLayout_2->addWidget(wdg_room);

        wdg_bottom = new QWidget(wdg_content);
        wdg_bottom->setObjectName(QStringLiteral("wdg_bottom"));
        wdg_bottom->setMinimumSize(QSize(0, 200));

        verticalLayout_2->addWidget(wdg_bottom);


        verticalLayout->addWidget(wdg_content);


        retranslateUi(DemoDialog);

        QMetaObject::connectSlotsByName(DemoDialog);
    } // setupUi

    void retranslateUi(QDialog *DemoDialog)
    {
        DemoDialog->setWindowTitle(QApplication::translate("DemoDialog", "DemoDialog", 0));
        lb_tittle_icon->setText(QString());
        lb_tittle->setText(QApplication::translate("DemoDialog", "\346\210\221\347\232\204\344\274\232\350\256\256", 0));
        pb_min->setText(QApplication::translate("DemoDialog", "\344\270\200", 0));
        pb_close->setText(QApplication::translate("DemoDialog", "X", 0));
        pb_icon->setText(QString());
        lb_name->setText(QApplication::translate("DemoDialog", "\346\210\221\347\232\204\345\220\215\345\255\227", 0));
        pb_setup->setText(QString());
        pb_join->setText(QApplication::translate("DemoDialog", "\345\212\240\345\205\245\344\274\232\350\256\256", 0));
        pb_create->setText(QApplication::translate("DemoDialog", "\345\210\233\345\273\272\344\274\232\350\256\256", 0));
        pb_history->setText(QApplication::translate("DemoDialog", "\344\274\232\350\256\256\350\256\260\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class DemoDialog: public Ui_DemoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
