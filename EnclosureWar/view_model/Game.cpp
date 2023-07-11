#include "Game.h"

//时钟
void Game::timerEvent(QTimerEvent* e)
{
    if(e->timerId() == timer_)
    {
        if(IfSuspend)
            return;

        PlayerHitSide();

        //移动控制恢复
        for(int i=0;i<players_.size();i++) players_[i].IfTurn = true;
    }
}

//游戏初始化
Game::Game(int x, int y, int member, GameWidget *gamew)
//void Game::NewGameMap(int x, int y, int member)
{
    //场地初始化
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

    //玩家初始化
    players_.clear();
    players_.push_back(Player(5, 5, Color::BLUE));
    PlayerRebirth(1);
    players_.push_back(Player(x - 4, y - 4, Color::RED));
    PlayerRebirth(2);
    if (member >= 3)
    {
        players_.push_back(Player(5, y - 4, Color::GREEN));
        PlayerRebirth(3);
    }
    if (member >= 4)
    {
        players_.push_back(Player(x - 4, 5, Color::PURPLE));
        PlayerRebirth(4);
    }
    member_ = players_.size();
    for(int i=0;i<players_.size();i++)
        players_[i].IfTurn = true;

    //设置边界
    SetBound();

    //暂停变量
    IfSuspend = false;

    timer_ = startTimer(50);
}

//设置边界
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

//按键操作
void Game::KeyPressed(int key)
{
    //暂停控制
    if(key == Qt::Key_Space)  IfSuspend = !IfSuspend;

    //玩家一
    if(key == Qt::Key_A)
    {
        players_[0].ChangeMoveDirection((Move)4);
        players_[0].IfTurn = false;
    }
    else if(key == Qt::Key_D)
    {
        players_[0].ChangeMoveDirection((Move)3);
        players_[0].IfTurn = false;
    }
    else if(key == Qt::Key_S)
    {
        players_[0].ChangeMoveDirection((Move)1);
        players_[0].IfTurn = false;
    }
    else if(key == Qt::Key_W)
    {
        players_[0].ChangeMoveDirection((Move)2);
        players_[0].IfTurn = false;
    }
    //玩家二
    if(key == Qt::Key_Left)
    {
        players_[0].ChangeMoveDirection((Move)4);
        players_[0].IfTurn = false;
    }
    else if(key == Qt::Key_Right)
    {
        players_[1].ChangeMoveDirection((Move)3);
        players_[1].IfTurn = false;
    }
    else if(key == Qt::Key_Down)
    {
        players_[1].ChangeMoveDirection((Move)1);
        players_[1].IfTurn = false;
    }
    else if(key == Qt::Key_Up)
    {
        players_[1].ChangeMoveDirection((Move)2);
        players_[1].IfTurn = false;
    }
    //玩家三
    if(member_ >= 3)
    {
        if(key == Qt::Key_1)
        {
            players_[2].ChangeMoveDirection((Move)4);
            players_[2].IfTurn = false;
        }
        else if(key == Qt::Key_3)
        {
            players_[2].ChangeMoveDirection((Move)3);
            players_[2].IfTurn = false;
        }
        else if(key == Qt::Key_2)
        {
            players_[2].ChangeMoveDirection((Move)1);
            players_[2].IfTurn = false;
        }
        else if(key == Qt::Key_5)
        {
            players_[2].ChangeMoveDirection((Move)2);
            players_[2].IfTurn = false;
        }
    }
    //玩家四
    if(member_ == 4)
    {
        if(key == Qt::Key_J)
        {
            players_[3].ChangeMoveDirection((Move)4);
            players_[3].IfTurn = false;
        }
        else if(key == Qt::Key_L)
        {
            players_[3].ChangeMoveDirection((Move)3);
            players_[3].IfTurn = false;
        }
        else if(key == Qt::Key_K)
        {
            players_[3].ChangeMoveDirection((Move)1);
            players_[3].IfTurn = false;
        }
        else if(key == Qt::Key_I)
        {
            players_[3].ChangeMoveDirection((Move)2);
            players_[3].IfTurn = false;
        }
    }
}

//玩家重生
void Game::PlayerRebirth(int PlayerNumber)
{


    switch (PlayerNumber)
    {
    case 1:
        players_[0].setX(5);
        players_[0].setY(5);
        break;
    case 2:
        players_[1].setX(x_ - 4);
        players_[1].setY(y_ - 4);
        break;
    case 3:
        players_[2].setX(5);
        players_[2].setY(y_ - 4);
        break;
    case 4:
        players_[3].setX(x_ - 4);
        players_[3].setY(5);
        break;
    default:
        QMessageBox::information(NULL, QStringLiteral("警告"), QStringLiteral("玩家信息错误！"));
        return;
    }

    players_[PlayerNumber - 1].curmove_ = Move::STOP;
    players_[PlayerNumber - 1].speed_ = 200;
    players_[PlayerNumber - 1].score_ = 9;

    players_[PlayerNumber - 1].passinglist_.clear();
    players_[PlayerNumber - 1].passinglist_.append(QPoint(players_[PlayerNumber - 1].x(), players_[PlayerNumber - 1].y()));

    players_[PlayerNumber - 1].occupantlist_.clear();
    players_[PlayerNumber - 1].occupantlist_.append(QPoint(players_[PlayerNumber - 1].x() - 1, players_[PlayerNumber - 1].y() - 1));
    players_[PlayerNumber - 1].occupantlist_.append(QPoint(players_[PlayerNumber - 1].x() - 1, players_[PlayerNumber - 1].y()));
    players_[PlayerNumber - 1].occupantlist_.append(QPoint(players_[PlayerNumber - 1].x() - 1, players_[PlayerNumber - 1].y() + 1));
    players_[PlayerNumber - 1].occupantlist_.append(QPoint(players_[PlayerNumber - 1].x(), players_[PlayerNumber - 1].y() - 1));
    players_[PlayerNumber - 1].occupantlist_.append(QPoint(players_[PlayerNumber - 1].x(), players_[PlayerNumber - 1].y()));
    players_[PlayerNumber - 1].occupantlist_.append(QPoint(players_[PlayerNumber - 1].x(), players_[PlayerNumber - 1].y() + 1));
    players_[PlayerNumber - 1].occupantlist_.append(QPoint(players_[PlayerNumber - 1].x() + 1, players_[PlayerNumber - 1].y() - 1));
    players_[PlayerNumber - 1].occupantlist_.append(QPoint(players_[PlayerNumber - 1].x() + 1, players_[PlayerNumber - 1].y()));
    players_[PlayerNumber - 1].occupantlist_.append(QPoint(players_[PlayerNumber - 1].x() + 1, players_[PlayerNumber - 1].y() + 1));
}

//玩家撞墙
void Game::PlayerHitSide()
{
    for(int i = 0; i < member_; i++)
    {
        if(HitSide(players_[i]))
        {
            PlayerRebirth(i+1);
        }
        else;
    }
}

//是否撞墙
bool Game::HitSide(QPoint pt)
{
    int x = pt.x();
    int y = pt.y();
    if(x <= 0 || x >= x_ - 1 || y <= 0 || y >= y_ - 1)
    {
        return true;
    }
    return false;
}

//是否撞玩家
int Game::HitPlayer(QPoint pt)
{

}
