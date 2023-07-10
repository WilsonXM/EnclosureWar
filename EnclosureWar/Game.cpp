#include "Game.h"

void Game::NewGameMap(int x, int y, int member)
{
    x_ = x;
    y_= y;
    blocks_.clear();
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
    players_.clear();
    players_.push_back(Player(5, 5, Color::BLUE));
    players_.push_back(Player(x - 4, y - 4, Color::RED));
    if (member >= 3)
        players_.push_back(Player(5, y - 4, Color::GREEN));
    if (member >= 4)
        players_.push_back(Player(x - 4, 5, Color::PURPLE));
    member_ = players_.size();
}

void Game::SetBound()
{
    for(int i = 1; i <= x_; i++)
    {
        blocks_[i][1].SetBound(true);
        blocks_[i][y_].SetBound(true);
    }
    for(int j = 1; j <= y_; j++)
    {
        blocks_[1][j].SetBound(true);
        blocks_[x_][j].SetBound(true);
    }
}
