#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, int width, int height, int pnum)
    : QMainWindow(parent)
    , mainwin(new Ui::MainWindow)
    , width_(width)
    , height_(height)
    , pnum_(pnum)
{
    mainwin->setupUi(this);
    resize(width_ * MAP_WIDTH + 300, height_ * MAP_HEIGHT);

    // 设置GameWidget大小
    mainwin->gamewidget->ReSize(width_, height_);
    // 初始化Game
    game = new Game(width_, height_, pnum_, mainwin->gamewidget);
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
