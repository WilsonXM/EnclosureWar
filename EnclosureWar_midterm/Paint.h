#ifndef PAINT_H
#define PAINT_H

#include "Block.h"
#include "Color.h"
#include "GameMap.h"
#include <QPainter>
#include <QWidget>

class Paint : public GameMap
{
public:
    Paint();
    void paintEvent(QPaintEvent *);

    void DrawBlock(Block block, Color color);
    void DrawBound();        //画边框
    void DrawSnake();       //画蛇
    void DrawTemp();        //画未占领区
    void Drawtest();        //测试显示

    ~Paint();

};

#endif // PAINT_H
