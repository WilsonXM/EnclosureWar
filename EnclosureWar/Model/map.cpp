#include "Map.h"

//对内函数
void Map::GameStart(int p)
{
    //场地初始化
    pn = p;
    QList<Block> line;
    for(int i = 1; i <= 100; i++)
    {
        for(int j = 1; j <= 75; j++)
        {
            Block temp;
            line.append(temp);
        }
        data_block_.push_back(line);
        line.clear();
    }

    //玩家初始化
    data_players_.clear();
    data_players_.push_back(Player(5, 5, Color::BLUE));
    PlayerRebirth(1);
    data_players_.push_back(Player(100 - 4, 75 - 4, Color::RED));
    PlayerRebirth(2);
    if (p >= 3)
    {
        data_players_.push_back(Player(5, 75 - 4, Color::GREEN));
        PlayerRebirth(3);
    }
    if (p >= 4)
    {
        data_players_.push_back(Player(100 - 4, 5, Color::PURPLE));
        PlayerRebirth(4);
    }
    for(int i=0; i<p; i++)
        data_players_[i].SetTurn(true);

    //设置边界
    SetBound();

    //指针上传

}

void Map::SetBound()
{
    for(int i = 0; i < 100; i++)
    {
        data_block_[i][0].SetBound(true);
        data_block_[i][75-1].SetBound(true);
    }
    for(int j = 0; j < 75; j++)
    {
        data_block_[0][j].SetBound(true);
        data_block_[100-1][j].SetBound(true);
    }
}

void Map::MoveControl(int pn, enum Move move)
{
    switch(pn)
    {
    case 1:
        data_players_[0].ChangeMoveDirection(move);
        break;
    case 2:
        data_players_[1].ChangeMoveDirection(move);
        break;
    case 3:
        data_players_[2].ChangeMoveDirection(move);
        break;
    case 4:
        data_players_[3].ChangeMoveDirection(move);
        break;
    }
}

void Map::MoveUnlock()
{
    for(int i=0; i<pn; i++)
        data_players_[i].SetTurn(true);
}

void Map::PlayerRebirth(int PlayerNumber)
{
    switch (PlayerNumber)
    {
    case 1:
        data_players_[0].SetDirection(QPoint(5, 5));
        break;
    case 2:
        data_players_[1].SetDirection(QPoint(100 - 4, 75 - 4));
        break;
    case 3:
        data_players_[2].SetDirection(QPoint(5, 75 - 4));
        break;
    case 4:
        data_players_[3].SetDirection(QPoint(100 - 4, 5));
        break;
    default:
        QMessageBox::information(NULL, QStringLiteral("警告"), QStringLiteral("玩家信息错误！"));
        return;
    }

    data_players_[PlayerNumber - 1].SetMove(Move::STOP);
    data_players_[PlayerNumber - 1].SetSpeed(InitSpeed);
    data_players_[PlayerNumber - 1].SetScore(9);
    data_players_[PlayerNumber - 1].SetOut(false);
    data_players_[PlayerNumber - 1].SetTurn(false);

    data_players_[PlayerNumber - 1].passinglist_.clear();
    data_players_[PlayerNumber - 1].passinglist_.append(data_players_[PlayerNumber - 1].GetDirection());

    data_players_[PlayerNumber - 1].occupantlist_.clear();
    data_players_[PlayerNumber - 1].occupantlist_.append(QPoint(data_players_[PlayerNumber - 1].GetDirection().x()-1, data_players_[PlayerNumber - 1].GetDirection().y()-1));
    data_players_[PlayerNumber - 1].occupantlist_.append(QPoint(data_players_[PlayerNumber - 1].GetDirection().x()-1, data_players_[PlayerNumber - 1].GetDirection().y()));
    data_players_[PlayerNumber - 1].occupantlist_.append(QPoint(data_players_[PlayerNumber - 1].GetDirection().x()-1, data_players_[PlayerNumber - 1].GetDirection().y()+1));
    data_players_[PlayerNumber - 1].occupantlist_.append(QPoint(data_players_[PlayerNumber - 1].GetDirection().x(), data_players_[PlayerNumber - 1].GetDirection().y()-1));
    data_players_[PlayerNumber - 1].occupantlist_.append(QPoint(data_players_[PlayerNumber - 1].GetDirection().x(), data_players_[PlayerNumber - 1].GetDirection().y()));
    data_players_[PlayerNumber - 1].occupantlist_.append(QPoint(data_players_[PlayerNumber - 1].GetDirection().x(), data_players_[PlayerNumber - 1].GetDirection().y()+1));
    data_players_[PlayerNumber - 1].occupantlist_.append(QPoint(data_players_[PlayerNumber - 1].GetDirection().x()+1, data_players_[PlayerNumber - 1].GetDirection().y()-1));
    data_players_[PlayerNumber - 1].occupantlist_.append(QPoint(data_players_[PlayerNumber - 1].GetDirection().x()+1, data_players_[PlayerNumber - 1].GetDirection().y()));
    data_players_[PlayerNumber - 1].occupantlist_.append(QPoint(data_players_[PlayerNumber - 1].GetDirection().x()+1, data_players_[PlayerNumber - 1].GetDirection().y()+1));

    data_players_[PlayerNumber - 1].range_.append(QPoint(data_players_[PlayerNumber - 1].GetDirection().x()-1, data_players_[PlayerNumber - 1].GetDirection().y()-1));
    data_players_[PlayerNumber - 1].range_.append(QPoint(data_players_[PlayerNumber - 1].GetDirection().x()+1, data_players_[PlayerNumber - 1].GetDirection().y()+1));

}

void Map::PlayerGo()
{
    for(int i = 0; i < pn; i++)
    {
        if(data_players_[i].GetMove() != Move::STOP)
        {
            switch (data_players_[i].GetMove())
            {
            case Move::UP:
                data_players_[i].SetDirection(QPoint(data_players_[i].GetDirection().x(), data_players_[i].GetDirection().y()-1));
                break;
            case Move::DOWN:
                data_players_[i].SetDirection(QPoint(data_players_[i].GetDirection().x(), data_players_[i].GetDirection().y()+1));
                break;
            case Move::LEFT:
                data_players_[i].SetDirection(QPoint(data_players_[i].GetDirection().x()-1, data_players_[i].GetDirection().y()));
                break;
            case Move::RIGHT:
                data_players_[i].SetDirection(QPoint(data_players_[i].GetDirection().x()+1, data_players_[i].GetDirection().y()));
                break;
            default:
                break;
            }
        }
        else;
    }
}

void Map::PlayerHitSide()
{
    for(int i = 0; i < pn; i++)
    {
        if(HitSide(data_players_[i].GetDirection()))
        {
            PlayerRebirth(i+1);
        }
        else;
    }
}

bool Map::HitSide(QPoint pt)
{
    int x = pt.x();
    int y = pt.y();
    if(x <= 0 || x >= 100 - 1 || y <= 0 || y >= 75 - 1)
    {
        return true;
    }
    return false;
}

void Map::HitPlayer()
{
    for(int i = 0; i < pn; i++)
    {
        bool ifkill = false;
        //检测路径
        for(int ii = 0; ii < data_players_[i].passinglist_.size(); ii++)
        {            
            for(int iii = 0; iii < pn; iii++)
            {
                if(data_players_[iii].GetDirection() == data_players_[i].passinglist_[ii])
                {
                    PlayerRebirth(i+1);
                    ifkill = true;
                    break;
                }
            }
            if(ifkill) break;
        }
    }
}

void Map::Player_Move()
{
    for(int i = 0; i < pn; i++)
    {
        data_players_[i].passinglist_.append(data_players_[i].GetDirection());
        if(IfInOccupy(i + 1))//领地内移动
        {
            if(!data_players_[i].GetOut())
            {
                data_players_[i].passinglist_.clear();
                data_players_[i].passinglist_.append(data_players_[i].GetDirection());
            }
            else//首次进入
            {
                //圈地算法
                FillPath(i + 1);
                FliiSpace(i + 1);
                data_players_[i].SetOut(false);
                data_players_[i].SetScore(data_players_[i].occupantlist_.size());
                //分数传参
            }
        }
        else//领地外移动
        {
            if(!data_players_[i].GetOut())//首次出界
            {
                data_players_[i].SetOut(true);
            }
            //更新领地外围
            if(data_players_[i].GetDirection().x() < data_players_[i].range_[0].x())
            {
                data_players_[i].range_[0].setX(data_players_[i].GetDirection().x());
            }
            if(data_players_[i].GetDirection().y() < data_players_[i].range_[0].y())
            {
                data_players_[i].range_[0].setY(data_players_[i].GetDirection().y());
            }
            if(data_players_[i].GetDirection().x() > data_players_[i].range_[1].x())
            {
                data_players_[i].range_[1].setX(data_players_[i].GetDirection().x());
            }
            if(data_players_[i].GetDirection().y() > data_players_[i].range_[1].y())
            {
                data_players_[i].range_[1].setY(data_players_[i].GetDirection().y());
            }
        }
    }

}

bool Map::IfInOccupy(int PlayerNumber)
{
    for(int i = 0; i < data_players_[PlayerNumber - 1].occupantlist_.size(); i++)
    {
        if(data_players_[PlayerNumber - 1].GetDirection() == data_players_[PlayerNumber - 1].occupantlist_[i])
            return true;
    }
    return false;
}

void Map::FillPath(int PlayerNumber)
{
    data_players_[PlayerNumber - 1].passinglist_.removeFirst();
    data_players_[PlayerNumber - 1].passinglist_.removeLast();
    for(int i = 0 ; i < data_players_[PlayerNumber - 1].passinglist_.size() ; i++)
    {
        data_players_[PlayerNumber - 1].occupantlist_.append(data_players_[PlayerNumber - 1].passinglist_[i]);
        //从其他玩家列里删除该点
        DeletePoint(PlayerNumber, data_players_[PlayerNumber - 1].passinglist_[i].x(), data_players_[PlayerNumber - 1].passinglist_[i].y());
    }
    data_players_[PlayerNumber - 1].passinglist_.clear();
    data_players_[PlayerNumber - 1].passinglist_.append(data_players_[PlayerNumber - 1].GetDirection());
}

void Map::FliiSpace(int PlayerNumber)
{
    int ifjudge [100][75];
    QList<QPoint> tempoint;
    tempoint = data_players_[PlayerNumber - 1].occupantlist_;

    //标记定义：0未搜索，1非领地，2领地，3已搜索未定性
    for(int i = data_players_[PlayerNumber - 1].range_[0].x() - 1; i <= data_players_[PlayerNumber - 1].range_[1].x() + 1; i++)
    {
        ifjudge[i][data_players_[PlayerNumber - 1].range_[0].y() - 1] = 1;
        ifjudge[i][data_players_[PlayerNumber - 1].range_[1].y() + 1] = 1;
    }
    for(int i = data_players_[PlayerNumber - 1].range_[0].y() - 1; i <= data_players_[PlayerNumber - 1].range_[1].y() + 1; i++)
    {
        ifjudge[data_players_[PlayerNumber - 1].range_[0].x() - 1][i] = 1;
        ifjudge[data_players_[PlayerNumber - 1].range_[1].x() + 1][i] = 1;
    }

    for(int i = data_players_[PlayerNumber - 1].range_[0].x(); i<= data_players_[PlayerNumber - 1].range_[1].x(); i++)
    {
        for(int ii = data_players_[PlayerNumber - 1].range_[0].y(); ii<= data_players_[PlayerNumber - 1].range_[1].y(); ii++)
        {
            if(tempoint.removeOne(QPoint(i, ii)))
            {
                ifjudge[i][ii] = 2;
                continue;
            }
            else ifjudge[i][ii] = 0;
        }
    }

    for(int i = data_players_[PlayerNumber - 1].range_[0].x(); i<= data_players_[PlayerNumber - 1].range_[1].x(); i++)
    {
        for(int ii = data_players_[PlayerNumber - 1].range_[0].y(); ii<= data_players_[PlayerNumber - 1].range_[1].y(); ii++)
        {
            if(ifjudge[i][ii] > 0) continue;
            else
            {
                QList<QPoint> temstack;//栈
                temstack.clear();
                tempoint.clear();

                tempoint.append(QPoint(i,ii));
                ifjudge[i][ii] = 3;

                temstack.append(QPoint(i,ii));
                while(!temstack.isEmpty())//BFS
                {
                    QPoint temp = temstack.last();
                    temstack.removeLast();

                    //向右侧搜索
                    if(temp.x() + 1 > data_players_[PlayerNumber - 1].range_[1].x() + 2);
                    else
                    {
                        if(ifjudge[temp.x()+1][temp.y()] == 0)//未搜索的点
                        {
                            tempoint.append(QPoint(temp.x()+1, temp.y()));
                            ifjudge[temp.x()+1][temp.y()] = 3;
                            temstack.append(QPoint(temp.x()+1, temp.y()));
                        }
                        else if(ifjudge[temp.x()+1][temp.y()] == 1)//遇到非领地
                        {
                            for(int t = 0; t < tempoint.size(); t++)
                            {
                                ifjudge[tempoint[t].x()][tempoint[t].y()] = 1;
                            }
                            tempoint.clear();
                            temstack.clear();
                            break;
                        }
                        else if(ifjudge[temp.x()+1][temp.y()] == 2);//遇到领地
                        else if(ifjudge[temp.x()+1][temp.y()] == 3);//遇到已检索
                        else//错误报告
                        {
                            QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("数据异常，游戏结束！"));
                            return;
                        }
                    }

                    //向右下搜索

                    if(temp.x() + 1 > data_players_[PlayerNumber - 1].range_[1].x() + 2 || temp.y() + 1 > data_players_[PlayerNumber - 1].range_[1].y() + 2);
                    else
                    {
                        if(ifjudge[temp.x()+1][temp.y()+1] == 0)//未搜索的点
                        {
                            tempoint.append(QPoint(temp.x()+1, temp.y()+1));
                            ifjudge[temp.x()+1][temp.y()+1] = 3;
                            temstack.append(QPoint(temp.x()+1, temp.y()+1));
                        }
                        else if(ifjudge[temp.x()+1][temp.y()+1] == 1)//遇到非领地
                        {
                            for(int t = 0; t < tempoint.size(); t++)
                            {
                                ifjudge[tempoint[t].x()][tempoint[t].y()] = 1;
                            }
                            tempoint.clear();
                            temstack.clear();
                            break;
                        }
                        else if(ifjudge[temp.x()+1][temp.y()+1] == 2);//遇到领地
                        else if(ifjudge[temp.x()+1][temp.y()+1] == 3);//遇到已检索
                        else//错误报告
                        {
                            QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("数据异常，游戏结束！"));
                            return;
                        }
                    }

                    //向下方搜索
                    if(temp.y() + 1 > data_players_[PlayerNumber - 1].range_[1].y() + 2);
                    else
                    {
                        if(ifjudge[temp.x()][temp.y()+1] == 0)//未搜索的点
                        {
                            tempoint.append(QPoint(temp.x(), temp.y()+1));
                            ifjudge[temp.x()][temp.y()+1] = 3;
                            temstack.append(QPoint(temp.x(), temp.y()+1));
                        }
                        else if(ifjudge[temp.x()][temp.y()+1] == 1)//遇到非领地
                        {
                            for(int t = 0; t < tempoint.size(); t++)
                            {
                                ifjudge[tempoint[t].x()][tempoint[t].y()] = 1;
                            }
                            tempoint.clear();
                            temstack.clear();
                            break;
                        }
                        else if(ifjudge[temp.x()][temp.y()+1] == 2);//遇到领地
                        else if(ifjudge[temp.x()][temp.y()+1] == 3);//遇到已检索
                        else//错误报告
                        {
                            QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("数据异常，游戏结束！"));
                            return;
                        }
                    }


                    //向左下搜索
                    if(temp.x() - 1 < data_players_[PlayerNumber - 1].range_[1].x() - 2 || temp.y() + 1 > data_players_[PlayerNumber - 1].range_[1].y() + 2);
                    else
                    {
                        if(ifjudge[temp.x()-1][temp.y()+1] == 0)//未搜索的点
                        {
                            tempoint.append(QPoint(temp.x()-1, temp.y()+1));
                            ifjudge[temp.x()-1][temp.y()+1] = 3;
                            temstack.append(QPoint(temp.x()-1, temp.y()+1));
                        }
                        else if(ifjudge[temp.x()-1][temp.y()+1] == 1)//遇到非领地
                        {
                            for(int t = 0; t < tempoint.size(); t++)
                            {
                                ifjudge[tempoint[t].x()][tempoint[t].y()] = 1;
                            }
                            tempoint.clear();
                            temstack.clear();
                            break;
                        }
                        else if(ifjudge[temp.x()-1][temp.y()+1] == 2);//遇到领地
                        else if(ifjudge[temp.x()-1][temp.y()+1] == 3);//遇到已检索
                        else//错误报告
                        {
                            QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("数据异常，游戏结束！"));
                            return;
                        }
                    }


                    //向左侧搜索
                    if(temp.x() - 1 < data_players_[PlayerNumber - 1].range_[0].x() - 2);
                    else
                    {
                        if(ifjudge[temp.x()-1][temp.y()] == 0)//未搜索的点
                        {
                            tempoint.append(QPoint(temp.x()-1, temp.y()));
                            ifjudge[temp.x()-1][temp.y()] = 3;
                            temstack.append(QPoint(temp.x()-1, temp.y()));
                        }
                        else if(ifjudge[temp.x()-1][temp.y()] == 1)//遇到非领地
                        {
                            for(int t = 0; t < tempoint.size(); t++)
                            {
                                ifjudge[tempoint[t].x()][tempoint[t].y()] = 1;
                            }
                            tempoint.clear();
                            temstack.clear();
                            break;
                        }
                        else if(ifjudge[temp.x()-1][temp.y()] == 2);//遇到领地
                        else if(ifjudge[temp.x()-1][temp.y()] == 3);//遇到已检索
                        else//错误报告
                        {
                            QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("数据异常，游戏结束！"));
                            return;
                        }
                    }

                    //向左上搜索
                    if(temp.x() - 1 < data_players_[PlayerNumber - 1].range_[0].x() - 2 || temp.y() - 1 < data_players_[PlayerNumber - 1].range_[0].y() - 2);
                    else
                    {
                        if(ifjudge[temp.x()-1][temp.y()-1] == 0)//未搜索的点
                        {
                            tempoint.append(QPoint(temp.x()-1, temp.y()-1));
                            ifjudge[temp.x()-1][temp.y()-1] = 3;
                            temstack.append(QPoint(temp.x()-1, temp.y()-1));
                        }
                        else if(ifjudge[temp.x()-1][temp.y()-1] == 1)//遇到非领地
                        {
                            for(int t = 0; t < tempoint.size(); t++)
                            {
                                ifjudge[tempoint[t].x()][tempoint[t].y()] = 1;
                            }
                            tempoint.clear();
                            temstack.clear();
                            break;
                        }
                        else if(ifjudge[temp.x()-1][temp.y()-1] == 2);//遇到领地
                        else if(ifjudge[temp.x()-1][temp.y()-1] == 3);//遇到已检索
                        else//错误报告
                        {
                            QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("数据异常，游戏结束！"));
                            return;
                        }
                    }

                    //向上方搜索
                    if(temp.y() - 1 < data_players_[PlayerNumber - 1].range_[0].y() - 2);
                    else
                    {
                        if(ifjudge[temp.x()][temp.y()-1] == 0)//未搜索的点
                        {
                            tempoint.append(QPoint(temp.x(), temp.y()-1));
                            ifjudge[temp.x()][temp.y()-1] = 3;
                            temstack.append(QPoint(temp.x(), temp.y()-1));
                        }
                        else if(ifjudge[temp.x()][temp.y()-1] == 1)//遇到非领地
                        {
                            for(int t = 0; t < tempoint.size(); t++)
                            {
                                ifjudge[tempoint[t].x()][tempoint[t].y()] = 1;
                            }
                            tempoint.clear();
                            temstack.clear();
                            break;
                        }
                        else if(ifjudge[temp.x()][temp.y()-1] == 2);//遇到领地
                        else if(ifjudge[temp.x()][temp.y()-1] == 3);//遇到已检索
                        else//错误报告
                        {
                            QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("数据异常，游戏结束！"));
                            return;
                        }
                    }

                    //向右上搜索
                    if(temp.x() + 1 > data_players_[PlayerNumber - 1].range_[1].x() + 2 || temp.y() - 1 < data_players_[PlayerNumber - 1].range_[0].y() - 2);
                    else
                    {
                        if(ifjudge[temp.x()+1][temp.y()-1] == 0)//未搜索的点
                        {
                            tempoint.append(QPoint(temp.x()+1, temp.y()-1));
                            ifjudge[temp.x()+1][temp.y()-1] = 3;
                            temstack.append(QPoint(temp.x()+1, temp.y()-1));
                        }
                        else if(ifjudge[temp.x()+1][temp.y()-1] == 1)//遇到非领地
                        {
                            for(int t = 0; t < tempoint.size(); t++)
                            {
                                ifjudge[tempoint[t].x()][tempoint[t].y()] = 1;
                            }
                            tempoint.clear();
                            temstack.clear();
                            break;
                        }
                        else if(ifjudge[temp.x()+1][temp.y()-1] == 2);//遇到领地
                        else if(ifjudge[temp.x()+1][temp.y()-1] == 3);//遇到已检索
                        else//错误报告
                        {
                            QMessageBox::information(NULL, QStringLiteral("提示"), QStringLiteral("数据异常，游戏结束！"));
                            return;
                        }
                    }

                }
                while(!tempoint.isEmpty())
                {
                    data_players_[PlayerNumber - 1].occupantlist_.append(tempoint.last());
                    DeletePoint(PlayerNumber, tempoint.last().x(), tempoint.last().y());
                    ifjudge[tempoint.last().x()][tempoint.last().y()] = 2;
                    tempoint.removeLast();
                }
            }
        }
    }
}

void Map::DeletePoint(int PlayerNumber, int x, int y)
{
    switch(data_block_[x][y].GetOccupant())
    {
    case WHITE:
        break;
    case RED:
        if(PlayerNumber != 1)
            data_players_[0].occupantlist_.removeOne(QPoint(x, y));
        break;
    case BLUE:
        if(PlayerNumber != 2)
            data_players_[1].occupantlist_.removeOne(QPoint(x, y));
        break;
    case GREEN:
        if(PlayerNumber != 3)
            data_players_[2].occupantlist_.removeOne(QPoint(x, y));
        break;
    case PURPLE:
        if(PlayerNumber != 4)
            data_players_[3].occupantlist_.removeOne(QPoint(x, y));
        break;
    default:
        break;
    }
}

void Map::FillToBlock()
{
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < 75; j++)
        {
            data_block_[i][j].Recover();
        }
    }
    SetBound();

    for(int i = 0; i < data_players_.size(); i++)
    {
        //占领
        for(int ii = 0; ii < data_players_[i].occupantlist_.size(); ii++)
        {
            switch(i)
            {
            case 0:
                data_block_[data_players_[i].occupantlist_[ii].x()][data_players_[i].occupantlist_[ii].y()].SetOccupied(RED);
                //data_block_[data_players_[i].occupantlist_[ii].x()][data_players_[i].occupantlist_[ii].y()].SetPassing(RED);
                break;
            case 1:
                data_block_[data_players_[i].occupantlist_[ii].x()][data_players_[i].occupantlist_[ii].y()].SetOccupied(BLUE);
                //data_block_[data_players_[i].occupantlist_[ii].x()][data_players_[i].occupantlist_[ii].y()].SetPassing(BLUE);
                break;
            case 2:
                data_block_[data_players_[i].occupantlist_[ii].x()][data_players_[i].occupantlist_[ii].y()].SetOccupied(GREEN);
                //data_block_[data_players_[i].occupantlist_[ii].x()][data_players_[i].occupantlist_[ii].y()].SetPassing(GREEN);
                break;
            case 3:
                data_block_[data_players_[i].occupantlist_[ii].x()][data_players_[i].occupantlist_[ii].y()].SetOccupied(PURPLE);
                //data_block_[data_players_[i].occupantlist_[ii].x()][data_players_[i].occupantlist_[ii].y()].SetPassing(PURPLE);
                break;
            default:
                break;
            }
        }
        //经过
        for(int ii = 0; ii < data_players_[i].passinglist_.size(); ii++)
        {
            switch(i)
            {
            case 0:
                data_block_[data_players_[i].passinglist_[ii].x()][data_players_[i].passinglist_[ii].y()].SetPassing(LIGHTRED);
                break;
            case 1:
                data_block_[data_players_[i].passinglist_[ii].x()][data_players_[i].passinglist_[ii].y()].SetPassing(LIGHTBLUE);
                break;
            case 2:
                data_block_[data_players_[i].passinglist_[ii].x()][data_players_[i].passinglist_[ii].y()].SetPassing(LIGHTGREEN);
                break;
            case 3:
                data_block_[data_players_[i].passinglist_[ii].x()][data_players_[i].passinglist_[ii].y()].SetPassing(LIGHTPURPLE);
                break;
            default:
                break;
            }
        }
    }
}

QList<QList<Block>> Map::GetBlocks()
{
    return data_block_;
}

QList<Player> Map::GetPlayers()
{
    return data_players_;
}
