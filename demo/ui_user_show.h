/********************************************************************************
** Form generated from reading UI file 'user_show.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USER_SHOW_H
#define UI_USER_SHOW_H

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

class Ui_user_show
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lb_name;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *user_show)
    {
        if (user_show->objectName().isEmpty())
            user_show->setObjectName(QStringLiteral("user_show"));
        user_show->resize(200, 170);
        verticalLayout = new QVBoxLayout(user_show);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lb_name = new QLabel(user_show);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lb_name);

        verticalSpacer = new QSpacerItem(20, 123, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(user_show);

        QMetaObject::connectSlotsByName(user_show);
    } // setupUi

    void retranslateUi(QWidget *user_show)
    {
        user_show->setWindowTitle(QApplication::translate("user_show", "Form", 0));
        lb_name->setText(QApplication::translate("user_show", "\347\224\250\346\210\267\345\220\215", 0));
    } // retranslateUi

};

namespace Ui {
    class user_show: public Ui_user_show {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USER_SHOW_H
