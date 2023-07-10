#include "Paint.h"

void Paint::paintEvent(QPaintEvent *)
{
    DrawBound();
    DrawSnake();
    DrawTemp();

    //Drawtest();//测试输出

    update();
}

void Paint::DrawBlock(Block block, Color color)
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

void Paint::DrawBound()
{
    for(int x = 1; x < x_; x++)
    {
        blocks_[x][1].SetBound(true);
        DrawBlock(blocks_[x][1], Color::Gray);
        blocks_[x][y_].SetBound(true);
        DrawBlock(blocks_[x][y_], Color::Gray);
    }
    for(int y = 1; y < y_; y++)
    {
        blocks_[1][y].SetBound(true);
        DrawBlock(blocks_[1][y], Color::Gray);
        blocks_[x_][y].SetBound(true);
        DrawBlock(blocks_[x_][y], Color::Gray);
    }
}

void Paint::DrawSnake()
{
    QPainter painter(this);
    painter.setBrush(QColor("#DC143C"));
    //    painter.setPen(QPen(QColor(Qt::black),1));
    painter.setPen(Qt::black);
    foreach (QPoint pt, mSnake)
    {
        painter.drawRect( pt.x()*MAP_WIDTH,pt.y()*MAP_HEIGHT,MAP_WIDTH,MAP_HEIGHT);
    }
}
