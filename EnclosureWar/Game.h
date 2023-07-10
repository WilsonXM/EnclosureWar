#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QList>
#include <QPainter>
#include "Paint.h"
#include "common/Player.h"

class Game
{
    Q_OBJECT
public:
    Game() {}
    ~Game() {}

public:
    void NewGameMap(int x, int y, int member);
    void SetBound();


private:
    int x_;
    int y_;
    QList<QList<Block>> blocks_;
    int member_;
    QList<Player> players_;
    int timer_;
};

#endif // GAME_H

