#include "Game.h"

Game::Game(int x, int y, int member, GameWidget *gamew)
//void Game::NewGameMap(int x, int y, int member)
{
    x_ = x;
    y_= y;
    paint = new Paint(x, y, blocks_, gamew);
    blocks_.clear();
    QList<Block> line;
    for(int i = 1; i <= y; i++)
    {
        for(int j = 1; j <= x; j++)
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
    SetBound();

    timer_ = startTimer(50);
}

void Game::SetBound()
{
    for(int i = 0; i < y_; i++)
    {
        blocks_[i][0].SetBound(true);
        blocks_[i][x_-1].SetBound(true);
    }
    for(int j = 0; j < x_; j++)
    {
        blocks_[0][j].SetBound(true);
        blocks_[y_-1][j].SetBound(true);
    }
}

void Game::KeyPressed(int key)
{
    if(key == Qt::Key_Space)
        players_[0].SwitchStop();

    if(key == Qt::Key_Left)
        players_[0].ChangeMoveDirection((Move)4);
    else if(key == Qt::Key_Right)
        players_[0].ChangeMoveDirection((Move)3);
    else if(key == Qt::Key_Down)
        players_[0].ChangeMoveDirection((Move)1);
    else if(key == Qt::Key_Up)
        players_[0].ChangeMoveDirection((Move)2);

}

void Game::timerEvent(QTimerEvent* e)
{
    if(e->timerId() == timer_)
    {

    }
}
