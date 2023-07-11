#include "Common.h"

Color GetDarkColor(Color lightcolor)
{
    if(lightcolor == Color::LIGHTRED)
        return Color::RED;
    else if(lightcolor == Color::LIGHTBLUE)
        return Color::BLUE;
    else if(lightcolor == Color::LIGHTGREEN)
        return Color::GREEN;
    else if(lightcolor == Color::LIGHTPURPLE)
        return Color::PURPLE;
    else
        return lightcolor;
}

Color GetLightColor(Color darkcolor)
{
    if(darkcolor == Color::RED)
        return Color::LIGHTRED;
    else if(darkcolor == Color::BLUE)
        return Color::LIGHTBLUE;
    else if(darkcolor == Color::GREEN)
        return Color::LIGHTGREEN;
    else if(darkcolor == Color::PURPLE)
        return Color::LIGHTPURPLE;
    else
        return darkcolor;
}
