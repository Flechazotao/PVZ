#include "duckytubezombie1.h".h"
static string name = "";
static string info ="";
DuckyTubeZombie1::DuckyTubeZombie1()
{
    hp = 640;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    setMovie(":/Picture/Zombie/DuckyTubeZombie1/Walk1.gif");
    setName(name);
    setInfo(info);
}

void DuckyTubeZombie1::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie(":/Picture/Zombie/DuckyTubeZombie1/Die.gif");
            setHead(":/pvz.res/ZombieHead.gif");
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        plant->hp -= atk;
        if (state != 1)
        {
            state = 1;
            setMovie(":/Picture/Zombie/DuckyTubeZombie1/Attack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/Picture/Zombie/DuckyTubeZombie1/Walk2.gif");
    }
    setX(x() - speed);
}
