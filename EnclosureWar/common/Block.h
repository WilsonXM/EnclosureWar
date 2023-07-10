#ifndef BLOCK_H
#define BLOCK_H

#include <QPoint>
#include "Color.h"

class Block : public QPoint
{
public:
    Block(int x, int y) : QPoint(x ,y)
    {
        is_bound_ = false;
        is_prop_ = false;
        occupant_ = Color::WHITE;
        passing_ = Color::WHITE;
    }
    ~Block() {}

public:
    bool IsBound() { return is_bound_; }
    bool IsProp() { return is_prop_; }
    Color GetOccupant() { return occupant_; }
    Color GetCurColor() { return passing_; }

public:
    void InitBlock()
    {
        occupant_ = Color::WHITE;
        passing_ = Color::WHITE;
    }
    void SetBound(bool bound) { is_bound_ = bound; }
    void SetProp(bool prop) { is_prop_ = prop; }
    void Passing(Color PlayerColor) { passing_ = PlayerColor; }
    void Occupied() { occupant_ = passing_; }
    void Recover() { passing_ = occupant_; }

private:
    bool is_bound_;
    bool is_prop_;
    Color occupant_;
    Color passing_;
};

#endif // BLOCK_H
