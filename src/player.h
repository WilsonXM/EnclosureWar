#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "color.h"

enum class Move
{
    STOP = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player
{
public:
    Player(Color playercolor) : playercolor_(playercolor)
    {
        playerrow_ = 0;
        playercolumn_ = 0;
        move_ = Move::STOP;
        speed_ = 0;
    }
    Player(Color playercolor,int row,int column) : playercolor_(playercolor)
    {
        playerrow_ = row;
        playercolumn_ = column;
        move_ = Move::STOP;
        speed_ = 0;
    }
    ~Player() {}

public:
    Color GetPlayerColor() const { return playercolor_; }
    int GetPlayerRow() { return playerrow_; }
    int GetPlayerColumn() { return playercolumn_; }
    Move GetMove() { return move_; }
    int GetSpeed() { return speed_; }

public:
    void SetPlayerRow(int row) { playerrow_ = row; }
    void SetPlayerColumn(int column) { playercolumn_ = column; }
    void SetMove(Move move) { move_ = move; }
    void SpeedUp(int upper) { speed_ = speed_ + upper; }
    void SpeedDown(int lower) { speed_ = speed_ - lower; }

private:
    const Color playercolor_;
    int playerrow_;
    int playercolumn_;
    Move move_;
    int speed_;
};

#endif