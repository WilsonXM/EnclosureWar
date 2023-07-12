#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include "Model/Player.h"
#include "Model/Map.h"

class Model : public QObject
{
    Q_OBJECT
public:
    void BuildGame(const int &&player);//输入玩家人数构建游戏
    void PlayerMove(const int &&playernum, const Move &&playermove) noexcept;// 玩家移动调用函数
    void Move() noexcept;// 间隔刷新的move函数

public:
    QSharedPointer<Map> blocks_;
    QSharedPointer<Player> players_;

};

#endif // MODEL_H
