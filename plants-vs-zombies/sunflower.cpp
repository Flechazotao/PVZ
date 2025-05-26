#include "sunflower.h"
#include <QDebug>

SunFlower::SunFlower()
{
    hp = 300;
    time = int(10.0 * 1000 / 33);
    setMovie(":/pvz.res/SunFlower.gif");
}

void SunFlower::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new Sun(pos()));
    }
}

QMovie* SunFlower::getMovie(){
    return movie;
}
