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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QPushButton *pb_start;
    QPushButton *pb_startFileWork;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(800, 600);
        pb_start = new QPushButton(Dialog);
        pb_start->setObjectName(QStringLiteral("pb_start"));
        pb_start->setGeometry(QRect(30, 560, 93, 28));
        pb_startFileWork = new QPushButton(Dialog);
        pb_startFileWork->setObjectName(QStringLiteral("pb_startFileWork"));
        pb_startFileWork->setGeometry(QRect(140, 560, 191, 28));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        pb_start->setText(QApplication::translate("Dialog", "\345\274\200\345\247\213", 0));
        pb_startFileWork->setText(QApplication::translate("Dialog", "\345\274\200\345\247\213\346\226\207\344\273\266\345\267\245\344\275\234", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
