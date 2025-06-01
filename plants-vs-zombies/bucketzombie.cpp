#include "bucketzombie.h"

static string name = "铁桶僵尸";
static string info ="他的铁桶头盔，能极大程度的承受伤害。\n韧性:高\n弱点:土豆雷\n铁桶头僵尸经常戴着水桶，在冷漠的世界里\n显得独一无二。但事实上，他只是忘记了，\n那铁桶还在他头上而已。。";
//铁桶僵尸
BucketZombie::BucketZombie()
{
    hp = 1370;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    setName(name);
    setInfo(info);
    setMovie(":/Picture/Zombie/BucketheadZombie/BucketheadZombie.gif");
}

void BucketZombie::advance(int phase)
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
            setMovie(":/Picture/Zombie/BucketheadZombie/BucketheadZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/Picture/Zombie/BucketheadZombie/BucketheadZombie.gif");
    }
    setX(x() - speed);
}
