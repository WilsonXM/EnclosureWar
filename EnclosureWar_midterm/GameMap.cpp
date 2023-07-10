#include "GameMap.h"
#include "Player.h"

GameMap::GameMap(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(MAP_COLUMES*MAP_WIDTH, MAP_ROWS*MAP_HEIGHT);
}

int GameMap::GetScoreSpeed(int nScore)
{
    return 100;
}
