#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mainwin(new Ui::MainWindow)
{
    mainwin->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete mainwin;
}

