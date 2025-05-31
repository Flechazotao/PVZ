#include "duckytubezombie1.h".h"
static string name = "鸭子游泳圈僵尸";
static string info ="鸭子救生圈能让僵尸能浮在水面上。\n韧性:低\n只在水池关卡出现只有特定的僵尸才能成\n为救生圈僵尸。\n并不是每个僵尸都能胜任的。\n有些救生圈有点漏气，但他们没能注意到，\n所以他们离开并放弃了对脑子的渴求。";
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
