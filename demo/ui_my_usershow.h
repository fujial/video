/********************************************************************************
** Form generated from reading UI file 'my_usershow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_USERSHOW_H
#define UI_MY_USERSHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_my_usershow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lb_name;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *my_usershow)
    {
        if (my_usershow->objectName().isEmpty())
            my_usershow->setObjectName(QStringLiteral("my_usershow"));
        my_usershow->resize(200, 170);
        my_usershow->setMinimumSize(QSize(200, 170));
        my_usershow->setMaximumSize(QSize(1080, 960));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        my_usershow->setFont(font);
        my_usershow->setStyleSheet(QLatin1String("\n"
"background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(my_usershow);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lb_name = new QLabel(my_usershow);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setEnabled(true);
        lb_name->setMinimumSize(QSize(0, 20));
        lb_name->setMaximumSize(QSize(16777215, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(8);
        lb_name->setFont(font1);
        lb_name->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_name);

        verticalSpacer = new QSpacerItem(20, 121, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(my_usershow);

        QMetaObject::connectSlotsByName(my_usershow);
    } // setupUi

    void retranslateUi(QWidget *my_usershow)
    {
        my_usershow->setWindowTitle(QApplication::translate("my_usershow", "Form", 0));
        lb_name->setText(QApplication::translate("my_usershow", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class my_usershow: public Ui_my_usershow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_USERSHOW_H
