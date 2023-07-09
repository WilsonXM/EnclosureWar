#include "initwindow.h"
#include "ui_initwindow.h"

initwindow::initwindow(QWidget *parent) :
    QMainWindow(parent),
    initwin(new Ui::initwindow)
{
    initwin->setupUi(this);
}

initwindow::~initwindow()
{
    delete initwin;
}

void initwindow::on_newGame_clicked()
{
    //
}

