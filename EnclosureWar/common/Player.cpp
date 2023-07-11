#include "Player.h"

void Player::NextMove()
{
    switch((int)curmove_)
    {
    case 1:
        this->setY(this->y() - 1);
        break;
    case 2:
        this->setY(this->y() + 1);
        break;
    case 3:
        this->setX(this->x() - 1);
        break;
    case 4:
        this->setX(this->x() + 1);
        break;
    default:
        break;
    }
}

void Player::ChangeMoveDirection(Move move)
{
    if(!IfTurn) return;
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
    if(flag) this->SetMove(move);
}
