#include "classicsunflower.h"
#include <QDebug>
#include<classicsun.h>

classicSunFlower::classicSunFlower()
{
    hp = 300;
    time = int(10.0 * 1000 / 33);
    setMovie(":/pvz.res/SunFlower.gif");
}

void classicSunFlower::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new classicSun(pos()));
    }
}
