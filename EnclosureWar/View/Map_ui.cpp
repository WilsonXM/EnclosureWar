#include "Map_ui.h"

Map_ui::Map_ui(QWidget *parent) : QWidget(parent)
{
    setFixedSize(100, 75);
}

void Map_ui::set_blocks_colors(const QList<QList<Block>> &blocks)
{
    this->blocks_colors = blocks;
}

void Map_ui::paint(QPainter &painter,int width, int height)
{
    painter.setPen(Qt::gray);
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            switch(blocks_colors[i][j].GetOccupant())
            {
                case RED:
                    painter.setBrush(QColor("#FF0000"));
                    break;
                case
                    BLUE: painter.setBrush(QColor("#0000FF"));
                    break;
                case
                    GREEN: painter.setBrush(QColor("#008000"));
                    break;
                case
                    PURPLE: painter.setBrush(QColor("#800080"));
                    break;
                case
                    WHITE: painter.setBrush(QColor("#FFFFFF"));
                    break;
                default:
                    painter.setBrush(QColor("#FFFFFF"));
                    break;
            }
            switch(blocks_colors[i][j].GetCurColor())
            {
                case
                    LIGHTRED: painter.setBrush(QColor("#F08080"));
                    break;
                case
                    LIGHTBLUE: painter.setBrush(QColor("#87CEFA"));
                    break;
                case
                    LIGHTGREEN: painter.setBrush(QColor("#90EE90"));
                    break;
                case
                    LIGHTPURPLE: painter.setBrush(QColor("#EE82EE"));
                    break;
                case
                    WHITE: painter.setBrush(QColor("#FFFFFF"));
                    break;
                default:
                    break;
            }
            if(blocks_colors[i][j].IsBound()) painter.setBrush(Qt::gray);
            painter.drawRect(i*SideLength, j*SideLength, SideLength, SideLength);
        }
    }
}
