#include "Block.h"

Block::Block(int x, int y) : QPoint(x, y)
{
    is_bound_ = false;
    is_prop_ = false;
    occupant_ = Color::WHITE;
    passing_ = Color::WHITE;
}

bool Block::IsBound() { return is_bound_; }

bool Block::IsProp() { return is_prop_; }

Color Block::GetOccupantColor() { return occupant_; }

Color Block::GetPassingColor() { return passing_;}

void Block::SetBound(bool bound) { is_bound_ = bound; }

void Block::SetProp(bool prop) { is_prop_ = prop; }

void Block::SetOccupantColor(Color playerColor) { occupant_ = playerColor; }

void Block::SetPassingColor(Color playerColor) { passing_ = playerColor; }
