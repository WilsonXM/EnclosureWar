#include "GameWidget.h"

GameWidget::GameWidget(QWidget *parent) : QWidget(parent) {}

void GameWidget::ReSize(int width, int height)
{
    setMinimumSize(width * 10, height * 10);
}

/*void GameWidget::paintEvent(QPaintEvent *)
{
    paint->DrawBlocks();

    //Drawtest();//测试输出

    update();
}*/
