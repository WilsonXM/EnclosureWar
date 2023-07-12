#include "Model/Model.h"

Model::Model() : map(QSharedPointer<Map>::create()) {}

//对外函数
void Model::BuildGame(const int &&player) noexcept
{
    int pn = player;
    map->GameStart(pn);
}

void Model::PlayerMove(const int &&playernum, const enum Move &&playermove) noexcept
{
    int pnt = playernum;
    enum Move movet = playermove;
    map->MoveControl(pnt, movet);
}

void Model::Move() noexcept
{
    //撞墙
    map->PlayerHitSide();
    //撞人
    map->HitPlayer();
    //移动模块
    map->Player_Move();
    //移动解锁
    map->MoveUnlock();
    //填充
    map->FillToBlock();
}
