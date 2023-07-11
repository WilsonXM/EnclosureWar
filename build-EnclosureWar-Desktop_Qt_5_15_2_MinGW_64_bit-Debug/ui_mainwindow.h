/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <model/GameWidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_0;
    GameWidget *gamewidget;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *clock;
    QHBoxLayout *horizontalLayout_1;
    QLabel *labelPlayer1;
    QLabel *labelScore1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPlayer2;
    QLabel *labelScore2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelPlayer3;
    QLabel *labelScore3_;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelPlayer4;
    QLabel *labelScore4;
    QSpacerItem *verticalSpacer;
    QPushButton *stopButton;
    QPushButton *musicButton;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1200, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 0, 1201, 801));
        horizontalLayout_0 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_0->setObjectName(QString::fromUtf8("horizontalLayout_0"));
        horizontalLayout_0->setContentsMargins(0, 0, 0, 0);
        gamewidget = new GameWidget(horizontalLayoutWidget_3);
        gamewidget->setObjectName(QString::fromUtf8("gamewidget"));

        horizontalLayout_0->addWidget(gamewidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_0->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        clock = new QLabel(horizontalLayoutWidget_3);
        clock->setObjectName(QString::fromUtf8("clock"));
        clock->setEnabled(true);
        clock->setMinimumSize(QSize(0, 140));
        QFont font;
        font.setFamily(QString::fromUtf8("Consolas"));
        font.setPointSize(30);
        font.setBold(true);
        clock->setFont(font);

        verticalLayout->addWidget(clock);

        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName(QString::fromUtf8("horizontalLayout_1"));
        labelPlayer1 = new QLabel(horizontalLayoutWidget_3);
        labelPlayer1->setObjectName(QString::fromUtf8("labelPlayer1"));
        labelPlayer1->setMinimumSize(QSize(0, 0));
        labelPlayer1->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Consolas"));
        font1.setPointSize(15);
        font1.setBold(true);
        labelPlayer1->setFont(font1);

        horizontalLayout_1->addWidget(labelPlayer1);

        labelScore1 = new QLabel(horizontalLayoutWidget_3);
        labelScore1->setObjectName(QString::fromUtf8("labelScore1"));
        labelScore1->setEnabled(true);
        labelScore1->setMinimumSize(QSize(0, 110));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Consolas"));
        font2.setPointSize(20);
        font2.setBold(true);
        labelScore1->setFont(font2);
        labelScore1->setAlignment(Qt::AlignCenter);

        horizontalLayout_1->addWidget(labelScore1);


        verticalLayout->addLayout(horizontalLayout_1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelPlayer2 = new QLabel(horizontalLayoutWidget_3);
        labelPlayer2->setObjectName(QString::fromUtf8("labelPlayer2"));
        labelPlayer2->setFont(font1);

        horizontalLayout_2->addWidget(labelPlayer2);

        labelScore2 = new QLabel(horizontalLayoutWidget_3);
        labelScore2->setObjectName(QString::fromUtf8("labelScore2"));
        labelScore2->setMinimumSize(QSize(0, 110));
        labelScore2->setFont(font2);

        horizontalLayout_2->addWidget(labelScore2, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelPlayer3 = new QLabel(horizontalLayoutWidget_3);
        labelPlayer3->setObjectName(QString::fromUtf8("labelPlayer3"));
        labelPlayer3->setFont(font1);

        horizontalLayout_3->addWidget(labelPlayer3);

        labelScore3_ = new QLabel(horizontalLayoutWidget_3);
        labelScore3_->setObjectName(QString::fromUtf8("labelScore3_"));
        labelScore3_->setMinimumSize(QSize(0, 110));
        labelScore3_->setFont(font2);

        horizontalLayout_3->addWidget(labelScore3_, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelPlayer4 = new QLabel(horizontalLayoutWidget_3);
        labelPlayer4->setObjectName(QString::fromUtf8("labelPlayer4"));
        labelPlayer4->setFont(font1);

        horizontalLayout_4->addWidget(labelPlayer4);

        labelScore4 = new QLabel(horizontalLayoutWidget_3);
        labelScore4->setObjectName(QString::fromUtf8("labelScore4"));
        labelScore4->setMinimumSize(QSize(0, 110));
        labelScore4->setFont(font2);

        horizontalLayout_4->addWidget(labelScore4, 0, Qt::AlignHCenter);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        stopButton = new QPushButton(horizontalLayoutWidget_3);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(stopButton);

        musicButton = new QPushButton(horizontalLayoutWidget_3);
        musicButton->setObjectName(QString::fromUtf8("musicButton"));
        musicButton->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(musicButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout_0->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        clock->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">60</p></body></html>", nullptr));
        labelPlayer1->setText(QCoreApplication::translate("MainWindow", "Player 1 :", nullptr));
        labelScore1->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelPlayer2->setText(QCoreApplication::translate("MainWindow", "Player 2 :", nullptr));
        labelScore2->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelPlayer3->setText(QCoreApplication::translate("MainWindow", "Player 3 :", nullptr));
        labelScore3_->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelPlayer4->setText(QCoreApplication::translate("MainWindow", "Player 4 :", nullptr));
        labelScore4->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234", nullptr));
        musicButton->setText(QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
