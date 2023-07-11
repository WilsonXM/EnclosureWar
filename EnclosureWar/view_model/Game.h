#ifndef GAME_H
#define GAME_H

#include <QKeyEvent>
#include <QTime>
#include <QTimerEvent>
#include <QMessageBox>
#include "model/GameWidget.h"
#include "common/Player.h"

extern int member_;

class Game : public QObject
{
    Q_OBJECT
public:
    Game(GameWidget *gamew);
    ~Game() {}

public:
    void KeyPressed(int key);
    void timerEvent(QTimerEvent *);
    void SetBound();

private:
    QList<QList<Block>> blocks_;
    QList<Player> players_;
    GameWidget *gwTEST;
    int timer_;
};

#endif // GAME_H

