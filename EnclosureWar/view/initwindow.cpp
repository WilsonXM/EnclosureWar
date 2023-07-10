#include "initwindow.h"
#include "ui_initwindow.h"
#include "mainwindow.h"

initwindow::initwindow(QWidget *parent) :
    QMainWindow(parent),
    initwin(new Ui::initwindow)
{
    initwin->setupUi(this);

    // switch the pages in the initwindow
    initwin->stackedWidget->setCurrentIndex(0);
    connect(initwin->newGame, &QPushButton::clicked, this, &initwindow::switchPage);
    connect(initwin->backButton, &QPushButton::clicked, this, &initwindow::switchPage);

    //
}

initwindow::~initwindow()
{
    delete initwin;
}

void initwindow::switchPage()
{
    int nIndex = initwin->stackedWidget->currentIndex();
    if(nIndex)
        initwin->stackedWidget->setCurrentIndex(0);
    else
        initwin->stackedWidget->setCurrentIndex(1);
}



void initwindow::on_commitButton_clicked()
{
    // get the set info
    int width = initwin->widthlineEdit->text().toInt();
    int height = initwin->heightlineEdit->text().toInt();
    int speed = initwin->speedlineEdit->text().toInt();
    int time = initwin->timelineEdit->text().toInt();

    MainWindow *main = new MainWindow;

    main->show();
    this->close();

}

