#ifndef PAINT_H
#define PAINT_H

#include "common/Block.h"
#include "GameWidget.h"

#define MAP_WIDTH		10
#define MAP_HEIGHT		10

class Paint
{
public:
    Paint();
    void DrawBlock(Block block, Color color, QWidget widget);
};

#endif // PAINT_H
