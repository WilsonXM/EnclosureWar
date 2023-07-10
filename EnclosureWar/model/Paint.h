#ifndef PAINT_H
#define PAINT_H

#include <QPainter>
#include "qwidget.h"
#include "common/Block.h"
#include "view_model/GameWidget.h"

class Paint
{
public:
    Paint();
    Paint(int x, int y, QList<QList<Block>> bls, GameWidget *gamew);
    void DrawBlock(Block block, Color color, GameWidget *widget);
    void DrawBlocks();      // 画整个游戏区域
    ~Paint();

protected:
    void paintEvent(QPaintEvent *);

private:
    int width;
    int height;
    QList<QList<Block>> blocks;
    GameWidget *gamewid;
};

#endif // PAINT_H
