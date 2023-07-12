#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include <QList>
#include <QObject>
#include <QSharedPointer>
#include <vector>
#include <QSet>
#include <QLineF>
#include <QPointF>
#include <QRectF>
#include "Common/Common.h"

class Player : public QObject
{

    Q_OBJECT

public:
    Player(int x, int y, Color playercolor)
    {
        direction_ = QPoint(x,y);
        playercolor_ = playercolor;
        curmove_ = Move::STOP;
        speed_ = InitSpeed;
        score_ = 0;
    }
    ~Player() {}

public://设置函数
    void SetDirection(const QPoint &&dir) noexcept;
    void SetMove(const Move &&move) noexcept;
    void SetTurn(const bool ifturn) noexcept;
    void SetOut(const bool ifout) noexcept;
    void SetSpeed(const int &&speed) noexcept;
    void SetScore(const int &&score) noexcept;
    void AddPass(const QPoint &&pass) noexcept;
    void AddOccup(const QPoint &&occup) noexcept;
    void SetRange(const QPoint r0, const QPoint r1) noexcept;

public://返回函数
    Color GetPlayerColor()  noexcept;//playercolor_
    QPoint GetDirection() noexcept;//direction_
    Move GetMove()  noexcept;//curmove_
    int GetSpeed()  noexcept;//speed_
    int GetScore()  noexcept;//score_
    bool GetOut()  noexcept;//IfOut_
    QPoint GetSmallRange() noexcept;//range_
    QPoint GetBigRange() noexcept;

public:
    void ChangeMoveDirection(Move move);
    QList<QPoint> passinglist_;
    QList<QPoint> occupantlist_;
    QList<QPoint> range_;

private:
    Color playercolor_;

    QPoint direction_;
    Move curmove_;
    bool IfTurn_;
    bool IfOut_;
    int speed_;
    int score_;

};

#endif // PLAYER_H
