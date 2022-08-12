/********************************************************************************
** Form generated from reading UI file 'card.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARD_H
#define UI_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_card
{
public:
    QLabel *lb_LIFE;
    QLabel *lb_COST;
    QLabel *lb_ACK;

    void setupUi(QWidget *card)
    {
        if (card->objectName().isEmpty())
            card->setObjectName(QStringLiteral("card"));
        card->resize(100, 100);
        card->setMinimumSize(QSize(100, 100));
        card->setMaximumSize(QSize(100, 100));
        lb_LIFE = new QLabel(card);
        lb_LIFE->setObjectName(QStringLiteral("lb_LIFE"));
        lb_LIFE->setGeometry(QRect(40, 80, 50, 20));
        QFont font;
        font.setPointSize(7);
        lb_LIFE->setFont(font);
        lb_LIFE->setTextFormat(Qt::PlainText);
        lb_COST = new QLabel(card);
        lb_COST->setObjectName(QStringLiteral("lb_COST"));
        lb_COST->setGeometry(QRect(0, 0, 40, 20));
        lb_COST->setFont(font);
        lb_COST->setTextFormat(Qt::PlainText);
        lb_ACK = new QLabel(card);
        lb_ACK->setObjectName(QStringLiteral("lb_ACK"));
        lb_ACK->setGeometry(QRect(0, 80, 50, 20));
        lb_ACK->setFont(font);
        lb_ACK->setTextFormat(Qt::PlainText);

        retranslateUi(card);

        QMetaObject::connectSlotsByName(card);
    } // setupUi

    void retranslateUi(QWidget *card)
    {
        card->setWindowTitle(QApplication::translate("card", "Form", 0));
        lb_LIFE->setText(QApplication::translate("card", "\347\224\237\345\221\275", 0));
        lb_COST->setText(QApplication::translate("card", "\350\264\271\347\224\250", 0));
        lb_ACK->setText(QApplication::translate("card", "\346\224\273\345\207\273", 0));
    } // retranslateUi

};

namespace Ui {
    class card: public Ui_card {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARD_H
