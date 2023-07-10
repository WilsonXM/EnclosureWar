#include "GameMap.h"

void GameMap::DrawBlock(Block block, Color color)
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

void GameMap::DrawBound()
{
    for(int x = 1; x < x_; x++)
    {
        blocks_[x][1].SetBound(true);
        GameMap::DrawBlock(blocks_[x][1], Color::Gray);
        blocks_[x][y_].SetBound(true);
        GameMap::DrawBlock(blocks_[x][y_], Color::Gray);
    }
    for(int y = 1; y < y_; y++)
    {
        blocks_[1][y].SetBound(true);
        GameMap::DrawBlock(blocks_[1][y], Color::Gray);
        blocks_[x_][y].SetBound(true);
        GameMap::DrawBlock(blocks_[x_][y], Color::Gray);
    }
}
