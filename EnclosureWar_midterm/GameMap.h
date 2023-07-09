#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QWidget>
#include <QList>
#include "Block.h"
#include "Player.h"

#define MAP_COLUMES	    100
#define MAP_ROWS		75
#define MAP_WIDTH		10
#define MAP_HEIGHT		10

class GameMap: public QWidget
{
    Q_OBJECT
public:
    GameMap();

private:
    int row_;
    int column_;
    QList<QList<Block>> blocks_;
    int member_;
    QList<Player> players_;
};

#endif // GAMEMAP_H
