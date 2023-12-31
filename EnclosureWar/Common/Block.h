#ifndef BLOCK_H
#define BLOCK_H

#include "Common/Common.h"

class Block
{
public:
    Block()
    {
        is_bound_ = false;
        is_prop_ = false;
        occupant_ = Color::WHITE;
        passing_ = Color::WHITE;
    }
    ~Block() {}

public://构造
    void InitBlock() noexcept;//区域初始化
    void SetBound(const bool &&bound) noexcept;//边界
    void SetProp(const bool &&prop) noexcept;
    void SetPassing(const Color &&PlayerColor) noexcept;
    void SetOccupied(const Color &&PlayerColor) noexcept;
    void Recover() noexcept;

public://输出
    bool IsBound() { return is_bound_; }
    bool IsProp() { return is_prop_; }
    Color GetOccupant() { return occupant_; }
    Color GetCurColor() { return passing_; }

private:
    bool is_bound_;
    bool is_prop_;
    Color occupant_;
    Color passing_;

};

#endif // BLOCK_H
