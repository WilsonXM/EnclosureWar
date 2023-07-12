#include "Model/Player.h"

//设置函数
void Player::SetDirection(const QPoint &&dir) noexcept
{
    direction_ = dir;
}

void Player::SetMove(const Move &&move) noexcept
{
    curmove_ = move;
}

void Player::SetTurn(const bool &&ifturn) noexcept
{
    IfTurn_ = ifturn;
}

void Player::SetOut(const bool &&ifout) noexcept
{
    IfOut_ = ifout;
}

void Player::SetSpeed(const int &&speed) noexcept
{
    speed_ = speed;
}

void Player::SetScore(const int &&score) noexcept
{
    score_ = score;
}

void Player::AddPass(const QPoint &&pass) noexcept
{
    passinglist_.append(pass);
}

void Player::AddOccup(const QPoint &&occup) noexcept
{
    occupantlist_.append(occup);
}

void Player::SetRange(const QPoint r0, const QPoint r1) noexcept
{
    range_[0] = r0;
    range_[1] = r1;
}

//返回函数
Color Player::GetPlayerColor()  noexcept
{
    return playercolor_;
}

QPoint Player::GetDirection() noexcept
{
    return direction_;
}

Move Player::GetMove()  noexcept
{
    return curmove_;
}

int Player::GetSpeed()  noexcept
{
    return speed_;
}

int Player::GetScore() noexcept
{
    return score_;
}

QPoint Player::GetSmallRange() noexcept
{
    return range_[0];
}

QPoint Player::GetBigRange() noexcept
{
    return range_[1];
}

//功能函数
void Player::ChangeMoveDirection(const Move &&move)
{
    if(!IfTurn_) return;
    bool flag = true;
    switch((int) move)
    {
    case 1:
        if(this->GetMove() == Move::DOWN)
            flag = false;
        break;
    case 2:
        if(this->GetMove() == Move::UP)
            flag = false;
        break;
    case 3:
        if(this->GetMove() == Move::RIGHT)
            flag = false;
        break;
    case 4:
        if(this->GetMove() == Move::LEFT)
            flag = false;
        break;
    default:
        break;
    }
    if(flag)
        this->curmove_ = move;
}
