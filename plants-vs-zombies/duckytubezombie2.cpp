#include "duckytubezombie2.h".h"
static string name = "鸭子路障僵尸";
static string info ="鸭子救生圈让路障僵尸在水面能横冲直撞。\n韧性:中等\n速度:缓慢\n只在水池关卡出现的强化兵种，\n戴着路障的它比普通鸭子僵尸更耐打，\n但泳圈上的补丁暴露了它拮据的改造经费。\n";
DuckyTubeZombie2::DuckyTubeZombie2()
{
    hp = 270;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    setMovie(":/Picture/Zombie/DuckyTubeZombie2/Walk1.gif");
    setName(name);
    setInfo(info);
}

void DuckyTubeZombie2::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            if(x() < 240 or x()>942)
                setMovie(":/Picture/Zombie/Zombie/ZombieDie.gif");
            else
                setMovie(":/Picture/Zombie/DuckyTubeZombie1/Die.gif");
            setHead(":/Picture/Zombie/Zombie/ZombieHead.gif");
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
            setMovie(":/Picture/Zombie/DuckyTubeZombie2/Attack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/Picture/Zombie/DuckyTubeZombie2/Walk2.gif");
    }
    if(x() < 942 and x()>240)
        setMovie(":/Picture/Zombie/DuckyTubeZombie2/Walk2.gif");
    if(x() < 240)
        setMovie(":/Picture/Zombie/DuckyTubeZombie2/Walk1.gif");
    setX(x() - speed);
}
