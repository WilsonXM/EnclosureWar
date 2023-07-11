/********************************************************************************
** Form generated from reading UI file 'InitWindow.ui'
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InitWindow
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *InitWindow)
    {
        if (InitWindow->objectName().isEmpty())
            InitWindow->setObjectName(QString::fromUtf8("InitWindow"));
        InitWindow->resize(800, 600);
        centralwidget = new QWidget(InitWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        InitWindow->setCentralWidget(centralwidget);

        retranslateUi(InitWindow);

        QMetaObject::connectSlotsByName(InitWindow);
    } // setupUi

    void retranslateUi(QMainWindow *InitWindow)
    {
        InitWindow->setWindowTitle(QCoreApplication::translate("InitWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InitWindow: public Ui_InitWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INITWINDOW_H
