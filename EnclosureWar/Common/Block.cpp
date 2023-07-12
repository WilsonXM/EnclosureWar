#include "Common/Block.h"

void Block::InitBlock() noexcept
{
    occupant_ = Color::WHITE;
    passing_ = Color::WHITE;
}

void Block::SetBound(const bool &&bound) noexcept
{
    is_bound_ = bound;
}

void Block::SetProp(const bool &&prop) noexcept
{
    is_prop_ = prop;
}

void Block::SetPassing(const Color &&PlayerColor) noexcept
{
    passing_ = PlayerColor;
}

void Block::SetOccupied(const Color &&PlayerColor) noexcept
{
    occupant_ = PlayerColor;
}

void Block::Recover() noexcept
{
    passing_ = occupant_;
}
