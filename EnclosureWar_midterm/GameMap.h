#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QWidget>
#include <QList>
#include <QPainter>
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
    GameMap(int x, int y, int member)
    {
        x_ = x;
        y_= y;
        QList<Block> line;
        for(int i = 1; i <= x; i++)
        {
            for(int j = 1; j <= y; j++)
            {
                Block temp(i, j);
                line.push_back(temp);
            }
            blocks_.push_back(line);
            line.clear();
        }
        players_.push_back(Player(5, 5, Color::BLUE));
        players_.push_back(Player(x - 4, y - 4, Color::RED));
        if (member >= 3)
            players_.push_back(Player(5, y - 4, Color::GREEN));
        if (member >= 4)
            players_.push_back(Player(x - 4, 5, Color::PURPLE));
        member_ = players_.size();
    }
    ~GameMap() {}

public:
    void DrawBlock(Block block, Color color);
    void DrawBound();

private:
    int x_;
    int y_;
    QList<QList<Block>> blocks_;
    int member_;
    QList<Player> players_;
};

#endif // GAMEMAP_H
