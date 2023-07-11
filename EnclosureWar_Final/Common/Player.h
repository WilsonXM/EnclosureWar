#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include <Qlist.h>
#include "Color.h"

#define InitSpeed 150
#define UpSpeed 100
#define GCD 50

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
    Player(Color playercolor);
    Player(int x, int y, Color playercolor);
    ~Player() {}

public:
    Color GetPlayerColor();
    Move GetMove();
    bool IsLocked();
    bool IsOut();
    int GetSpeed();
    QList<QPoint> GetPassingList();
    QList<QPoint> GetOccupantList();
    QPoint GetLeftUp();
    QPoint GetRightDown();

public:
    void SetMove(Move move);
    void Lock();
    void UnLock();
    void SetOut(bool out);
    void SpeedUp();
    void SpeedDown();
    void SetPassingList(QList<QPoint> passinglist);
    void SetOccupantList(QList<QPoint> occupantlist);
    void SetLeftUp(QPoint leftup);
    void SetRightDown(QPoint rightdown);

private:
    Color playercolor_;
    Move move_;
    bool is_locked_;
    bool is_out_;
    int speed_;
    QList<QPoint> passinglist_;
    QList<QPoint> occupantlist_;
    QPoint leftup_;
    QPoint rightdown_;
};

#endif // PLAYER_H
