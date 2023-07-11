#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mainwin(new Ui::MainWindow)
{
    mainwin->setupUi(this);
    resize(x_ * MAP_WIDTH + 300, y_ * MAP_HEIGHT + 75);

    // 初始化Game
    game = new Game(mainwin->gamewidget);

    // 设置paint和paint *
    //mainwin->gamewidget->SetPaint(game->GetPaint());

    //connect(mainwin->gamewidget,&GameWidget::sigUpdateScore,this,&MainWindow::slotUpdateScore);

}

MainWindow::~MainWindow()
{
    delete mainwin;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    game->KeyPressed(e->key());
    QMainWindow::keyPressEvent(e);
}

void MainWindow::slotUpdateScore(int nScore)
{
    //每增加分数都判断是否超当前最高，如果超了就更新
    //本来准备在游戏结束时，与最高分比较，但是这样万一玩到很高分了，异常结束结果导致没更新，比较遗憾
    mainwin->labelScore1->setText(QString::number(nScore));
}
