#include "footballzombie.h"

static string name = "橄榄球僵尸";
static string info ="橄榄球僵尸的表演秀。\n韧性:极高\n速度:快\n在球场上，橄榄球僵尸表现出110%的激情，\n他进攻防守样样在行。\n虽然他完全不知道橄球是什么。";
FootballZombie::FootballZombie()
{
    hp = 1670;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 2.5;
    setName(name);
    setInfo(info);
    setMovie(":/pvz.res/FootballZombieWalk.gif");
}

void FootballZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie(":/pvz.res/FootballZombieDie.gif");
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
            setMovie(":/pvz.res/FootballZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/pvz.res/FootballZombieWalk.gif");
    }
    setX(x() - speed);
}
