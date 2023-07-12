#ifndef COMMON_H
#define COMMON_H

enum GameState
{
    PLAYING = 0,
    TIMEOUT,        // 倒计时结束
    PAUSE,          // 游戏暂停
    RESET           // 重新开始
};

enum Color
{
    WHITE = 0,
    RED,
    BLUE,
    GREEN,
    PURPLE,
    LIGHTRED,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTPURPLE,
    Gray
};

enum class Move
{
    STOP = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

#define InitSpeed 150   // 初始速度
#define UpSpeed 100     // 加速后速度
#define GCD 50          // 每隔50ms刷新一次

#define SideLength 10   // 每个block的大小

#endif // COMMON_H
