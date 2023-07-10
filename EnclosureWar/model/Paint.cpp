#include "Paint.h"

Paint::Paint(int x, int y, QList<QList<Block>> bls, GameWidget *gamew) : width(x), height(y)
{
    blocks = bls;
    gamewid = gamew;
}

void Paint::paintEvent(QPaintEvent *)
{
    DrawBlocks();

    //Drawtest();//测试输出

    gamewid->update();
}

void Paint::DrawBlock(Block block, Color color, GameWidget *widget)
{
    QPainter painter(widget);
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

void Paint::DrawBlocks()
{
    for(int i = 0; i < height; i++)
        for(int j = 0; j < width; j++) {
            Block temp = blocks[i][j];
            if(temp.IsBound())
                DrawBlock(temp, Gray, gamewid);
            else if(temp.IsProp())
                DrawBlock(temp, WHITE, gamewid);
            else if(temp.GetOccupant() == WHITE)
                DrawBlock(temp, temp.GetCurColor(), gamewid);
            else
                DrawBlock(temp, temp.GetOccupant(), gamewid);
        }
}
