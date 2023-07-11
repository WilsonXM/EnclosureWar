#include "GameWidget.h"

int x_;
int y_;

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    setMinimumSize((x_+1) * 10, (y_+1) * 10);
}


void GameWidget::paintEvent(QPaintEvent *)
{
    DrawBlocks();

    //Drawtest();//测试输出

    update();
}

void GameWidget::DrawBlock(Block block, Color color)
{
    QPainter painter(this);
    switch(int(color))
    {
    case 1:
        painter.setBrush(QColor("#FF0000"));
        break;
    case 2:
        painter.setBrush(QColor("#0000FF"));
        break;
    case 3:
        painter.setBrush(QColor("#008000"));
        break;
    case 4:
        painter.setBrush(QColor("#800080"));
        break;
    case 5:
        painter.setBrush(QColor("#F08080"));
        break;
    case 6:
        painter.setBrush(QColor("#87CEFA"));
        break;
    case 7:
        painter.setBrush(QColor("#90EE90"));
        break;
    case 8:
        painter.setBrush(QColor("#EE82EE"));
        break;
    case 9:
        painter.setBrush(QColor("#696969"));
        break;
    default:
        painter.setBrush(QColor("#FFFFFF"));
        break;
    }
    painter.setPen(Qt::NoPen);
    painter.drawRect(block.x() * MAP_WIDTH, block.y() * MAP_HEIGHT, MAP_WIDTH, MAP_HEIGHT);
}

void GameWidget::DrawBlocks()
{
    for(int i = 0; i < x_; i++) {
        for(int j = 0; j < y_; j++) {
            Block temp = (*blocks)[i][j];
            DrawBlock(temp, temp.GetOccupant());
            DrawBlock(temp, temp.GetCurColor());
            if(temp.IsBound()) DrawBlock(temp, Gray);
        }
    }
}
