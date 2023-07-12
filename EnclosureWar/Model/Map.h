#ifndef MAP_H
#define MAP_H

#include "Model/Block.h"
#include "Model/Player.h"

class Map : public QObject
{
    Q_OBJECT

public:
    Map();//游戏初始化
    ~Map() {}
    void SetBound();

public://游戏操作变量
    void PlayerRebirth(int PlayerNumber);//玩家重生
    void PlayerHitSide();//撞墙判定
    void HitPlayer();//撞线判定
    void PlayerMove();//玩家移动
    void FillToBlock();//list向block传参
    //void KillPlayer();

public://工具操作变量
    bool HitSide(QPoint pt);
    bool IfInOccupy(int PlayerNumber);//是否在玩家领地内移动
    void FillPath(int PlayerNumber);//填充玩家路径
    void FliiSpace(int PlayerNumber);//填充玩家区域
    void DeletePoint(int PlayerNumber, int x, int y);//从其他玩家队列删除点

private:
    bool IfSuspend;
};

#endif // MAP_H
