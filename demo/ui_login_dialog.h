/********************************************************************************
** Form generated from reading UI file 'login_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_DIALOG_H
#define UI_LOGIN_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login_Dialog
{
public:
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *line_password;
    QLabel *number;
    QLineEdit *line_number;
    QPushButton *button_login_login;
    QLabel *password;
    QPushButton *button_login_clear;
    QWidget *tab_2;
    QLabel *register_number;
    QLineEdit *register_line_number;
    QLabel *register_password;
    QLineEdit *register_line_password;
    QLabel *register_confirmpassword;
    QLineEdit *register_confirm_line_password;
    QPushButton *register_confirm;
    QPushButton *register_clear;

    void setupUi(QDialog *Login_Dialog)
    {
        if (Login_Dialog->objectName().isEmpty())
            Login_Dialog->setObjectName(QStringLiteral("Login_Dialog"));
        Login_Dialog->resize(496, 329);
        Login_Dialog->setMinimumSize(QSize(496, 329));
        Login_Dialog->setMaximumSize(QSize(496, 329));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        Login_Dialog->setFont(font);
        label = new QLabel(Login_Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 161, 331));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/register.png")));
        label->setScaledContents(true);
        tabWidget = new QTabWidget(Login_Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(160, 0, 341, 331));
        tabWidget->setToolTipDuration(-1);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        line_password = new QLineEdit(tab);
        line_password->setObjectName(QStringLiteral("line_password"));
        line_password->setGeometry(QRect(100, 90, 130, 30));
        number = new QLabel(tab);
        number->setObjectName(QStringLiteral("number"));
        number->setGeometry(QRect(50, 50, 72, 30));
        line_number = new QLineEdit(tab);
        line_number->setObjectName(QStringLiteral("line_number"));
        line_number->setGeometry(QRect(100, 50, 130, 30));
        button_login_login = new QPushButton(tab);
        button_login_login->setObjectName(QStringLiteral("button_login_login"));
        button_login_login->setGeometry(QRect(180, 200, 90, 30));
        password = new QLabel(tab);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(50, 90, 72, 30));
        button_login_clear = new QPushButton(tab);
        button_login_clear->setObjectName(QStringLiteral("button_login_clear"));
        button_login_clear->setGeometry(QRect(70, 200, 90, 30));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        register_number = new QLabel(tab_2);
        register_number->setObjectName(QStringLiteral("register_number"));
        register_number->setGeometry(QRect(60, 40, 72, 30));
        register_line_number = new QLineEdit(tab_2);
        register_line_number->setObjectName(QStringLiteral("register_line_number"));
        register_line_number->setGeometry(QRect(110, 40, 130, 30));
        register_password = new QLabel(tab_2);
        register_password->setObjectName(QStringLiteral("register_password"));
        register_password->setGeometry(QRect(60, 90, 72, 30));
        register_line_password = new QLineEdit(tab_2);
        register_line_password->setObjectName(QStringLiteral("register_line_password"));
        register_line_password->setGeometry(QRect(110, 90, 130, 30));
        register_confirmpassword = new QLabel(tab_2);
        register_confirmpassword->setObjectName(QStringLiteral("register_confirmpassword"));
        register_confirmpassword->setGeometry(QRect(40, 140, 72, 30));
        register_confirm_line_password = new QLineEdit(tab_2);
        register_confirm_line_password->setObjectName(QStringLiteral("register_confirm_line_password"));
        register_confirm_line_password->setGeometry(QRect(110, 140, 130, 30));
        register_confirm = new QPushButton(tab_2);
        register_confirm->setObjectName(QStringLiteral("register_confirm"));
        register_confirm->setGeometry(QRect(150, 200, 90, 30));
        register_clear = new QPushButton(tab_2);
        register_clear->setObjectName(QStringLiteral("register_clear"));
        register_clear->setGeometry(QRect(50, 200, 90, 30));
        tabWidget->addTab(tab_2, QString());
        QWidget::setTabOrder(tabWidget, line_number);
        QWidget::setTabOrder(line_number, line_password);
        QWidget::setTabOrder(line_password, button_login_clear);
        QWidget::setTabOrder(button_login_clear, button_login_login);
        QWidget::setTabOrder(button_login_login, register_line_number);
        QWidget::setTabOrder(register_line_number, register_line_password);
        QWidget::setTabOrder(register_line_password, register_confirm_line_password);
        QWidget::setTabOrder(register_confirm_line_password, register_confirm);

        retranslateUi(Login_Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Login_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Login_Dialog)
    {
        Login_Dialog->setWindowTitle(QApplication::translate("Login_Dialog", "Dialog", 0));
        label->setText(QString());
        number->setText(QApplication::translate("Login_Dialog", "\350\264\246\345\217\267", 0));
        button_login_login->setText(QApplication::translate("Login_Dialog", "\347\231\273\351\231\206", 0));
        password->setText(QApplication::translate("Login_Dialog", "\345\257\206\347\240\201", 0));
        button_login_clear->setText(QApplication::translate("Login_Dialog", "\346\270\205\351\231\244", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Login_Dialog", "\343\200\200\347\231\273\345\275\225\343\200\200", 0));
        register_number->setText(QApplication::translate("Login_Dialog", "\350\264\246\345\217\267", 0));
        register_password->setText(QApplication::translate("Login_Dialog", "\345\257\206\347\240\201", 0));
        register_confirmpassword->setText(QApplication::translate("Login_Dialog", "\347\241\256\350\256\244\345\257\206\347\240\201", 0));
        register_confirm->setText(QApplication::translate("Login_Dialog", "\347\241\256\350\256\244", 0));
        register_clear->setText(QApplication::translate("Login_Dialog", "\346\270\205\351\231\244", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Login_Dialog", " \346\263\250\345\206\214\343\200\200", 0));
    } // retranslateUi

};

namespace Ui {
    class Login_Dialog: public Ui_Login_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_DIALOG_H
