/********************************************************************************
** Form generated from reading UI file 'set_user.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SET_USER_H
#define UI_SET_USER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_set_user
{
public:
    QComboBox *cbx_icon;
    QLabel *lb_picture;
    QLabel *lb_signature;
    QLineEdit *le_signature;
    QLabel *lb_name;
    QLineEdit *le_name;
    QPushButton *pb_clear;
    QPushButton *pb_emit;

    void setupUi(QDialog *set_user)
    {
        if (set_user->objectName().isEmpty())
            set_user->setObjectName(QStringLiteral("set_user"));
        set_user->resize(400, 300);
        cbx_icon = new QComboBox(set_user);
        cbx_icon->setObjectName(QStringLiteral("cbx_icon"));
        cbx_icon->setGeometry(QRect(48, 61, 87, 21));
        cbx_icon->setIconSize(QSize(60, 60));
        lb_picture = new QLabel(set_user);
        lb_picture->setObjectName(QStringLiteral("lb_picture"));
        lb_picture->setGeometry(QRect(11, 61, 30, 16));
        lb_signature = new QLabel(set_user);
        lb_signature->setObjectName(QStringLiteral("lb_signature"));
        lb_signature->setGeometry(QRect(11, 139, 30, 16));
        le_signature = new QLineEdit(set_user);
        le_signature->setObjectName(QStringLiteral("le_signature"));
        le_signature->setGeometry(QRect(48, 139, 171, 21));
        lb_name = new QLabel(set_user);
        lb_name->setObjectName(QStringLiteral("lb_name"));
        lb_name->setGeometry(QRect(11, 217, 30, 16));
        le_name = new QLineEdit(set_user);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setGeometry(QRect(48, 217, 171, 21));
        pb_clear = new QPushButton(set_user);
        pb_clear->setObjectName(QStringLiteral("pb_clear"));
        pb_clear->setGeometry(QRect(150, 250, 93, 28));
        pb_emit = new QPushButton(set_user);
        pb_emit->setObjectName(QStringLiteral("pb_emit"));
        pb_emit->setGeometry(QRect(260, 250, 93, 28));

        retranslateUi(set_user);

        QMetaObject::connectSlotsByName(set_user);
    } // setupUi

    void retranslateUi(QDialog *set_user)
    {
        set_user->setWindowTitle(QApplication::translate("set_user", "Dialog", 0));
        lb_picture->setText(QApplication::translate("set_user", "\345\244\264\345\203\217", 0));
        lb_signature->setText(QApplication::translate("set_user", "\347\255\276\345\220\215", 0));
        lb_name->setText(QApplication::translate("set_user", "\346\230\265\347\247\260", 0));
        pb_clear->setText(QApplication::translate("set_user", "\346\270\205\347\251\272", 0));
        pb_emit->setText(QApplication::translate("set_user", "\346\217\220\344\272\244", 0));
    } // retranslateUi

};

namespace Ui {
    class set_user: public Ui_set_user {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SET_USER_H
