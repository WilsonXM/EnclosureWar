#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QPointer>
#include <QMessageBox>
#include "Common/Player.h"
#include "Common/Block.h"
#include "Model/Map.h"

class Model
{
public:
    Model();
    ~Model() {}//析构

public://对外函数
    void BuildGame(const int &&player) noexcept;//输入玩家人数构建游戏
    void PlayerMove(const int &&playernum, const enum Move &&playermove) noexcept;// 玩家移动调用函数
    void Move() noexcept;// 间隔刷新的move函数

public://对外变量
    QSharedPointer<Map> map;
};

#endif // MODEL_H
