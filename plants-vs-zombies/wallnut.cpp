#include "wallnut.h"
#include <QDebug>

WallNut::WallNut()
{
    hp = 4000;
    setMovie(":/pvz.res/WallNut.gif");
}
//坚果墙有1，2状态，2：血量多，1：血量少
void WallNut::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (hp <= 1333 && state != 2)
    {
        state = 2;
        setMovie(":/pvz.res/WallNut2.gif");
    }
    else if (1333 < hp && hp <= 2667 && state != 1)
    {
        state = 1;
        setMovie(":/pvz.res/WallNut1.gif");
    }
}
