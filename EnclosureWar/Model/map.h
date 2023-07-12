#ifndef MAP_H
#define MAP_H

#include <QPoint>
#include <QObject>
#include <QList>
#include <QSharedPointer>
#include <QMessageBox>
#include <vector>
#include <QSet>
#include <QRectF>
#include "Common/Common.h"
#include "Common/Block.h"
#include "Model/Player.h"

class Map : public QObject
{
    Q_OBJECT
public:
    Map();
    ~Map() {}

public://对内函数
    void GameStart(int p);
    void SetBound();
    void MoveControl(int pn, Move move);
    void MoveUnlock();
    void PlayerRebirth(int PlayerNumber);
    void PlayerHitSide();
    bool HitSide(QPoint pt);
    void HitPlayer();
    void Player_Move();
    bool IfInOccupy(int PlayerNumber);
    void FillPath(int PlayerNumber);
    void FliiSpace(int PlayerNumber);
    void DeletePoint(int PlayerNumber, int x, int y);
    void FillToBlock();
    QList<QList<Block>> GetBlocks();
    QList<Player> GetPlayers();

private://对内变量
    QList<QList<Block>> data_block_;
    QList<Player> data_players_;
    int pn;

};

#endif // MAP_H