#ifndef GAME_H
#define GAME_H

#include <QKeyEvent>
#include <QTime>
#include <QTimerEvent>
#include <QMessageBox>
#include "model/Paint.h"
#include "common/Player.h"

class Game : public QObject
{
    Q_OBJECT

friend class Player;

public:
    Game(int x, int y, int member, GameWidget *gamew);
    ~Game() {}
    void SetBound();

public://游戏操作变量
    void PlayerRebirth(int PlayerNumber);//玩家重生

public://工具操作变量
    bool HitSide(QPoint pt);


public:
    //void NewGameMap(int x, int y, int member);    
    void KeyPressed(int key);

public:
    Paint *GetPaint() { return paint; }
    void timerEvent(QTimerEvent *);

private:
    int x_;//场地大小
    int y_;

    QList<QList<Block>> blocks_;//所有块

    int member_;//玩家人数
    QList<Player> players_;

    Paint *paint;
    int timer_;

private:
    bool IfSuspend;
};

#endif // GAME_H

