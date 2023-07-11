#ifndef BLOCK_H
#define BLOCK_H

#include <QPoint>
#include "Color.h"


class Block : public QPoint
{
public:
    Block(int x, int y);
    ~Block() {}

public:
    bool IsBound();
    bool IsProp();
    Color GetOccupantColor();
    Color GetPassingColor();

public:
    void SetBound(bool bound);
    void SetProp(bool prop);
    void SetOccupantColor(Color playercolor);
    void SetPassingColor(Color playercolor);

private:
    bool is_bound_;
    bool is_prop_;
    Color occupant_;
    Color passing_;
};

#endif // BLOCK_H
