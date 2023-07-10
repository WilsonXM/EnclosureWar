#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GameMap.h"

#include <QSettings>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //    setFixedSize(1000,800);
    resize(MAP_COLUMES*MAP_WIDTH + 300, MAP_ROWS*MAP_HEIGHT);

    connect(ui->widgetGameMap,&GameMap::sigUpdateScore,this,&MainWindow::slotUpdateScore);

    //ui->widgetGameMap->NewGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    //ui->widgetGameMap->KeyPressed(e->key());
    QMainWindow::keyPressEvent(e);
}

void MainWindow::slotUpdateScore(int nScore)
{
    ui->labelScore1->setText(QString::number(nScore));
    //每增加分数都判断是否超当前最高，如果超了就更新
    //本来准备在游戏结束时，与最高分比较，但是这样万一玩到很高分了，异常结束结果导致没更新，比较遗憾
}
