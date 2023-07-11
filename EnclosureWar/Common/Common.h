#ifndef COMMON_H
#define COMMON_H

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

#define InitSpeed 150
#define UpSpeed 100
#define GCD 50

#endif // COMMON_H
