#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "color.h"
#include "prop.h"

enum class Bound
{
    INSIDE = 0,
    UPBOUND,
    DOWNBOUND,
    LEFTBOUND,
    RIGHTBOUND,
    UPLEFTBOUND,
    UPRIGHTBOUND,
    DOWNLEFTBOUND,
    DOWNRIGHTBOUND
};

class Block
{
public:
    Block()
    {
        bound_ = Bound::INSIDE;
        occupant_ = Color::WHITE;
        passing_ = Color::WHITE;
        prop_ = Prop();
    }
    ~Block() {}

public:
    Bound GetBound() { return bound_; }
    Color GetOccupant() { return occupant_; }
    Color GetCurColor() { return passing_; }
    Prop GetPropType() { return prop_.GetPropType(); }

public:
    void InitBlock()
    {
        occupant_ = Color::WHITE;
        passing_ = Color::WHITE;
    }
    void SetBound(Bound bound) { bound_ = bound; }
    void Passing(Color PlayerColor) { passing_ = PlayerColor; }
    void Occupied() { occupant_ = passing_; }
    void Recover() { passing_ = occupant_; }
    void SetProp(PropType proptype) { prop_.SetPropType(proptype); }


private:
    Bound bound_;
    Color occupant_;
    Color passing_;
    Prop prop_;
};

#endif