#include "initwindow.h"
#include "ui_initwindow.h"
#include "mainwindow.h"
#include <QValidator>

initwindow::initwindow(QWidget *parent) :
    QMainWindow(parent),
    initwin(new Ui::initwindow)
{
    initwin->setupUi(this);

    // switch the pages in the initwindow
    initwin->stackedWidget->setCurrentIndex(0);
    connect(initwin->newGame, &QPushButton::clicked, this, &initwindow::switchPage);
    connect(initwin->backButton, &QPushButton::clicked, this, &initwindow::switchPage);

    // create constraints on the lineedit
    initwin->widthlineEdit->setValidator(new QIntValidator(initwin->widthlineEdit));
    initwin->widthlineEdit->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]+$")));

    initwin->heightlineEdit->setValidator(new QIntValidator(initwin->heightlineEdit));
    initwin->heightlineEdit->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]+$")));

    initwin->speedlineEdit->setValidator(new QIntValidator(initwin->speedlineEdit));
    initwin->speedlineEdit->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]+$")));

    initwin->timelineEdit->setValidator(new QIntValidator(initwin->timelineEdit));
    initwin->timelineEdit->setValidator(new QRegExpValidator(QRegExp("[1-9][0-9]+$")));
}

initwindow::~initwindow()
{
    delete initwin;
}

void initwindow::switchPage()
{
    int nIndex = initwin->stackedWidget->currentIndex();
    if(nIndex) {
        // clear the lineedit
        initwin->widthlineEdit->clear();
        initwin->heightlineEdit->clear();
        initwin->speedlineEdit->clear();
        initwin->timelineEdit->clear();

        initwin->stackedWidget->setCurrentIndex(0);
    }
    else
        initwin->stackedWidget->setCurrentIndex(1);
}



void initwindow::on_commitButton_clicked()
{
    // get the set info
    x_ = initwin->widthlineEdit->text().toInt();
    y_ = initwin->heightlineEdit->text().toInt();
    int speed = initwin->speedlineEdit->text().toInt();
    int time = initwin->timelineEdit->text().toInt();
    member_ = initwin->personlineEdit->text().toInt();

    MainWindow *main = new MainWindow;
    main->show();
    this->close();
}

