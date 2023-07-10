/********************************************************************************
** Form generated from reading UI file 'initwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INITWINDOW_H
#define UI_INITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_initwindow
{
public:
    QWidget *centralwidget;
    QPushButton *newGame;
    QPushButton *rank;
    QPushButton *help;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QMainWindow *initwindow)
    {
        if (initwindow->objectName().isEmpty())
            initwindow->setObjectName(QString::fromUtf8("initwindow"));
        initwindow->resize(800, 600);
        initwindow->setMinimumSize(QSize(800, 600));
        initwindow->setMaximumSize(QSize(800, 600));
        initwindow->setStyleSheet(QString::fromUtf8("QWidget #centralwidget\n"
"{\n"
"	border-image: url(:/images/initwindow);\n"
"}\n"
""));
        centralwidget = new QWidget(initwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        newGame = new QPushButton(centralwidget);
        newGame->setObjectName(QString::fromUtf8("newGame"));
        newGame->setGeometry(QRect(230, 330, 92, 28));
        newGame->setStyleSheet(QString::fromUtf8(""));
        rank = new QPushButton(centralwidget);
        rank->setObjectName(QString::fromUtf8("rank"));
        rank->setGeometry(QRect(230, 400, 92, 28));
        help = new QPushButton(centralwidget);
        help->setObjectName(QString::fromUtf8("help"));
        help->setGeometry(QRect(230, 470, 92, 28));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(380, 330, 211, 171));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        initwindow->setCentralWidget(centralwidget);
        newGame->raise();
        stackedWidget->raise();
        rank->raise();
        help->raise();

        retranslateUi(initwindow);

        QMetaObject::connectSlotsByName(initwindow);
    } // setupUi

    void retranslateUi(QMainWindow *initwindow)
    {
        initwindow->setWindowTitle(QCoreApplication::translate("initwindow", "\345\234\210\345\234\260\345\244\247\344\275\234\346\210\230", nullptr));
        newGame->setText(QCoreApplication::translate("initwindow", "New Game", nullptr));
        rank->setText(QCoreApplication::translate("initwindow", "Rankings", nullptr));
        help->setText(QCoreApplication::translate("initwindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class initwindow: public Ui_initwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITWINDOW_H
