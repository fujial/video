/********************************************************************************
** Form generated from reading UI file 'wait_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAIT_DIALOG_H
#define UI_WAIT_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_wait_dialog
{
public:
    QPushButton *pb_joinroom;
    QPushButton *pb_createroom;
    QPushButton *pb_return;

    void setupUi(QDialog *wait_dialog)
    {
        if (wait_dialog->objectName().isEmpty())
            wait_dialog->setObjectName(QStringLiteral("wait_dialog"));
        wait_dialog->resize(960, 720);
        pb_joinroom = new QPushButton(wait_dialog);
        pb_joinroom->setObjectName(QStringLiteral("pb_joinroom"));
        pb_joinroom->setGeometry(QRect(340, 220, 240, 60));
        pb_createroom = new QPushButton(wait_dialog);
        pb_createroom->setObjectName(QStringLiteral("pb_createroom"));
        pb_createroom->setGeometry(QRect(340, 120, 240, 60));
        pb_return = new QPushButton(wait_dialog);
        pb_return->setObjectName(QStringLiteral("pb_return"));
        pb_return->setGeometry(QRect(870, 0, 90, 30));

        retranslateUi(wait_dialog);

        QMetaObject::connectSlotsByName(wait_dialog);
    } // setupUi

    void retranslateUi(QDialog *wait_dialog)
    {
        wait_dialog->setWindowTitle(QApplication::translate("wait_dialog", "Dialog", 0));
        pb_joinroom->setText(QApplication::translate("wait_dialog", "\345\212\240\345\205\245\346\210\277\351\227\264", 0));
        pb_createroom->setText(QApplication::translate("wait_dialog", "\345\210\233\345\273\272\346\210\277\351\227\264", 0));
        pb_return->setText(QApplication::translate("wait_dialog", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class wait_dialog: public Ui_wait_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAIT_DIALOG_H
