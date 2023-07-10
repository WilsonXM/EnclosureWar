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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_initwindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page0;
    QPushButton *newGame;
    QPushButton *rank;
    QPushButton *help;
    QWidget *page1;
    QPushButton *commitButton;
    QPushButton *backButton;
    QLabel *mapsize;
    QLabel *speed;
    QLabel *timeNeed;
    QLineEdit *widthlineEdit;
    QLineEdit *heightlineEdit;
    QLabel *width0;
    QLabel *height0;
    QLineEdit *speedlineEdit;
    QLineEdit *timelineEdit;
    QLabel *personNumber;
    QLineEdit *personlineEdit;

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
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(120, 70, 561, 501));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page0 = new QWidget();
        page0->setObjectName(QString::fromUtf8("page0"));
        newGame = new QPushButton(page0);
        newGame->setObjectName(QString::fromUtf8("newGame"));
        newGame->setGeometry(QRect(220, 200, 130, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(13);
        font.setBold(true);
        newGame->setFont(font);
        newGame->setStyleSheet(QString::fromUtf8(""));
        rank = new QPushButton(page0);
        rank->setObjectName(QString::fromUtf8("rank"));
        rank->setGeometry(QRect(220, 300, 130, 50));
        rank->setFont(font);
        help = new QPushButton(page0);
        help->setObjectName(QString::fromUtf8("help"));
        help->setGeometry(QRect(220, 400, 130, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(13);
        font1.setBold(false);
        help->setFont(font1);
        stackedWidget->addWidget(page0);
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        commitButton = new QPushButton(page1);
        commitButton->setObjectName(QString::fromUtf8("commitButton"));
        commitButton->setGeometry(QRect(120, 420, 130, 50));
        commitButton->setFont(font);
        backButton = new QPushButton(page1);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(350, 420, 130, 50));
        backButton->setFont(font);
        mapsize = new QLabel(page1);
        mapsize->setObjectName(QString::fromUtf8("mapsize"));
        mapsize->setGeometry(QRect(20, 170, 100, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Consolas"));
        font2.setPointSize(10);
        font2.setBold(true);
        mapsize->setFont(font2);
        speed = new QLabel(page1);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setGeometry(QRect(20, 220, 100, 30));
        speed->setFont(font2);
        timeNeed = new QLabel(page1);
        timeNeed->setObjectName(QString::fromUtf8("timeNeed"));
        timeNeed->setGeometry(QRect(20, 270, 100, 30));
        timeNeed->setFont(font2);
        widthlineEdit = new QLineEdit(page1);
        widthlineEdit->setObjectName(QString::fromUtf8("widthlineEdit"));
        widthlineEdit->setGeometry(QRect(150, 170, 110, 30));
        widthlineEdit->setCursorPosition(0);
        widthlineEdit->setAlignment(Qt::AlignCenter);
        widthlineEdit->setClearButtonEnabled(false);
        heightlineEdit = new QLineEdit(page1);
        heightlineEdit->setObjectName(QString::fromUtf8("heightlineEdit"));
        heightlineEdit->setGeometry(QRect(340, 170, 110, 30));
        heightlineEdit->setAlignment(Qt::AlignCenter);
        width0 = new QLabel(page1);
        width0->setObjectName(QString::fromUtf8("width0"));
        width0->setGeometry(QRect(260, 170, 61, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Consolas"));
        font3.setPointSize(10);
        width0->setFont(font3);
        height0 = new QLabel(page1);
        height0->setObjectName(QString::fromUtf8("height0"));
        height0->setGeometry(QRect(450, 170, 71, 30));
        height0->setFont(font3);
        speedlineEdit = new QLineEdit(page1);
        speedlineEdit->setObjectName(QString::fromUtf8("speedlineEdit"));
        speedlineEdit->setGeometry(QRect(150, 220, 110, 30));
        speedlineEdit->setCursorPosition(0);
        speedlineEdit->setAlignment(Qt::AlignCenter);
        speedlineEdit->setClearButtonEnabled(false);
        timelineEdit = new QLineEdit(page1);
        timelineEdit->setObjectName(QString::fromUtf8("timelineEdit"));
        timelineEdit->setGeometry(QRect(150, 270, 110, 30));
        timelineEdit->setCursorPosition(0);
        timelineEdit->setAlignment(Qt::AlignCenter);
        timelineEdit->setClearButtonEnabled(false);
        personNumber = new QLabel(page1);
        personNumber->setObjectName(QString::fromUtf8("personNumber"));
        personNumber->setGeometry(QRect(20, 320, 100, 30));
        personNumber->setFont(font2);
        personlineEdit = new QLineEdit(page1);
        personlineEdit->setObjectName(QString::fromUtf8("personlineEdit"));
        personlineEdit->setGeometry(QRect(150, 320, 110, 30));
        personlineEdit->setCursorPosition(0);
        personlineEdit->setAlignment(Qt::AlignCenter);
        personlineEdit->setClearButtonEnabled(false);
        stackedWidget->addWidget(page1);
        initwindow->setCentralWidget(centralwidget);

        retranslateUi(initwindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(initwindow);
    } // setupUi

    void retranslateUi(QMainWindow *initwindow)
    {
        initwindow->setWindowTitle(QCoreApplication::translate("initwindow", "\345\234\210\345\234\260\345\244\247\344\275\234\346\210\230", nullptr));
        newGame->setText(QCoreApplication::translate("initwindow", "New Game", nullptr));
        rank->setText(QCoreApplication::translate("initwindow", "Rankings", nullptr));
        help->setText(QCoreApplication::translate("initwindow", "Help", nullptr));
        commitButton->setText(QCoreApplication::translate("initwindow", "Commit", nullptr));
        backButton->setText(QCoreApplication::translate("initwindow", "Back", nullptr));
        mapsize->setText(QCoreApplication::translate("initwindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:11pt;\">Map Size :</span></p></body></html>", nullptr));
        speed->setText(QCoreApplication::translate("initwindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:11pt;\">Speed :</span></p></body></html>", nullptr));
        timeNeed->setText(QCoreApplication::translate("initwindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:11pt;\">Time :</span></p></body></html>", nullptr));
        width0->setText(QCoreApplication::translate("initwindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">(Width)</span></p></body></html>", nullptr));
        height0->setText(QCoreApplication::translate("initwindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:8pt;\">(Height)</span></p></body></html>", nullptr));
        personNumber->setText(QCoreApplication::translate("initwindow", "<html><head/><body><p align=\"right\"><span style=\" font-size:11pt;\">Person :</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class initwindow: public Ui_initwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITWINDOW_H
