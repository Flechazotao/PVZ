#include "screenzombie.h"

static string name = "铁栅门僵尸";
static string info ="他的铁栅门是有效的盾牌。\n韧性:低\n铁栅门韧性:高\n弱点:大喷菇和磁力菇\n门板僵尸上次拜访过的房主防守并不专业，\n在吃掉房主的脑子后拿走了他家的铁栅门。";
ScreenZombie::ScreenZombie()
{
    hp = 1370;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    setName(name);
    setInfo(info);
    setMovie(":/Picture/Zombie/ScreenDoorZombie/ScreenDoorZombie.gif");
}

void ScreenZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie(":/Picture/Zombie/Zombie/ZombieDie.gif");
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
            setMovie(":/Picture/Zombie/ScreenDoorZombie/ScreenDoorZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/Picture/Zombie/ScreenDoorZombie/ScreenDoorZombie.gif");
    }
    setX(x() - speed);
}
