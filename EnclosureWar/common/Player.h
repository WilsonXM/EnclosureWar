#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include <QList>
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
        curmove_ = resmove_ = Move::STOP;
        speed_ = 200;
    }
    ~Player() {}

public:
    Color GetPlayerColor() const { return playercolor_; }
    Move GetMove() { return curmove_; }
    int GetSpeed() { return speed_; }

public:
    void SetMove(Move move) { resmove_ = curmove_; curmove_ = move; }
    void SwitchStop() { Move temp = resmove_; resmove_ = curmove_; curmove_ = temp; }
    void SpeedUp(int upper) { speed_ = speed_ + upper; }
    void SpeedDown(int lower) { speed_ = speed_ - lower; }

public:
    void NextMove();
    void ChangeMoveDirection(Move move);

private:
    Color playercolor_;
    Move curmove_;
    Move resmove_;
    int speed_;
    QList<QPoint> passinglist_;
    QList<QPoint> occupantlist_;
};

#endif // PLAYER_H
