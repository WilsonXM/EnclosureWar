#ifndef _GAME_H_
#define _GAME_H_

#include "block.h"
#include "player.h"
#include <vector>
using std::vector;

class Game
{
public:
    Game(int row, int column, int player_cnt)
    {
        row_ = row;
        column_ = column;
        Block temp_block;
        vector<Block> line(column, temp_block);
        blocks_.resize(row, line);
        blocks_[0][0].SetBound(Bound::UPLEFTBOUND);
        blocks_[0][column - 1].SetBound(Bound::UPRIGHTBOUND);
        blocks_[row - 1][0].SetBound(Bound::DOWNLEFTBOUND);
        blocks_[row - 1][column - 1].SetBound(Bound::DOWNRIGHTBOUND);
        for (int i = 1; i < row - 1; i++)
        {
            blocks_[i][0].SetBound(Bound::LEFTBOUND);
            blocks_[i][column - 1].SetBound(Bound::RIGHTBOUND);
        }
        for (int j = 1; j < column - 1; j++)
        {
            blocks_[0][j].SetBound(Bound::UPBOUND);
            blocks_[row - 1][j].SetBound(Bound::DOWNBOUND);
        }
        players_.clear();
        players_.push_back(Player(Color::BLUE));
        players_.push_back(Player(Color::RED));
        if (player_cnt >= 3)
            players_.push_back(Player(Color::GREEN));
        if (player_cnt >= 4)
            players_.push_back(Player(Color::PURPLE));
        player_cnt_ = players_.size();
    }
    ~Game() {}
// TODO
public:
    void GameBegin(); // 游戏开始
    void PlayersMove(); //移动（调用判断）
    void IsCircle(); // 成环判断
    // 复活
    // 击杀判断
    // 染色
    // 道具生效
    
    void GameOver(); // 游戏结束

public:
    int row_;
    int column_;
    vector<vector<Block>> blocks_;
    int player_cnt_;
    vector<Player> players_;
};

#endif
