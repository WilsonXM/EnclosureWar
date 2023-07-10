#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "GameMap.h"

class Game : public QObject
{
    Q_OBJECT
public:
    Game();
    void NewGame();
private:
    int member_;
    QList<Player> players_;
};

#endif // GAME_H
