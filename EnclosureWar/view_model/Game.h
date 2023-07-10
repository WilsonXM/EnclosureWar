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
public:
    Game(int x, int y, int member, GameWidget *gamew);
    ~Game() {}

public:
    //void NewGameMap(int x, int y, int member);
    Paint *GetPaint() { return paint; }
    void KeyPressed(int key);
    void timerEvent(QTimerEvent *);
    void SetBound();

private:
    int x_;
    int y_;
    QList<QList<Block>> blocks_;
    int member_;
    QList<Player> players_;
    Paint *paint;
    int timer_;
};

#endif // GAME_H

