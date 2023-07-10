#include "initwindow.h"
#include "ui_initwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

initwindow::initwindow(QWidget *parent) :
    QMainWindow(parent),
    initwin(new Ui::initwindow)
{
    initwin->setupUi(this);
    // set the window size

}

initwindow::~initwindow()
{
    delete initwin;
}

void initwindow::on_newGame_clicked()
{
    // jump to the mainwindow(playwindow)
    MainWindow *main = new MainWindow;
    main->show();
    this->close();
}

