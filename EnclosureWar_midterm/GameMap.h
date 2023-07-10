#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <QWidget>
#include <QList>
#include "Block.h"

#define MAP_COLUMES	    100//*
#define MAP_ROWS		75//*
#define MAP_WIDTH		10
#define MAP_HEIGHT		10

class GameMap: public QWidget
{
    Q_OBJECT
    friend class Paint;
public:
    explicit GameMap(QWidget *parent = nullptr);
    /*
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
    */
    ~GameMap() {}

signals:
    void sigUpdateScore(int nScore);

private:
    //获取不同分段对应的定时器时间，关卡越高，时间越快(短)
    int GetScoreSpeed(int nScore);
private:
    int x_;
    int y_;
    QList<QList<Block>> blocks_;
};

#endif // GAMEMAP_H
