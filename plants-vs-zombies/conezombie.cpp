#include "conezombie.h"
static string name = "路障僵尸";
static string info ="他的路障头盔，使他两倍坚韧于普通僵尸。\n韧性:中\n和其他僵尸一样，路障头僵尸盲目地向前。\n但某些事物却使他停下脚步，\n捡起一个交通路障，固实在自己的脑袋上。\n是的，他很喜欢参加聚会。";
ConeZombie::ConeZombie()
{
    hp = 640;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    setMovie(":/pvz.res/ConeZombieWalk.gif");
    setName(name);
    setInfo(info);
}

void ConeZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie(":/pvz.res/ZombieDie.gif");
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
            setMovie(":/pvz.res/ConeZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/pvz.res/ConeZombieWalk.gif");
    }
    setX(x() - speed);
}
