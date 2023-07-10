#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include "Color.h"

enum class Move
{
    STOP = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Player : public QPoint
{
public:
    Player(int x, int y, Color playercolor) : QPoint(x, y)
    {
        playercolor_ = playercolor;
        move_ = Move::STOP;
        speed_ = 200;
    }
    ~Player() {}

public:
    Color GetPlayerColor() const { return playercolor_; }
    Move GetMove() { return move_; }
    int GetSpeed() { return speed_; }

public:
    void SetMove(Move move) { move_ = move; }
    void SpeedUp(int upper) { speed_ = speed_ + upper; }
    void SpeedDown(int lower) { speed_ = speed_ - lower; }

public:
    void NextMove();
    void ChangeMoveDirection(Move move);

private:
    Color playercolor_;
    Move move_;
    int speed_;
};

#endif // PLAYER_H
