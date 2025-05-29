#include "basiczombie.h"

static string name = "普通僵尸";
static string info ="韧性:低\n这种僵尸喜爱脑髓，贪婪而不知足。\n脑髓，脑髓，脑髓，夜以继日地追求着。\n老而臭的脑髓?腐烂的脑髓?\n都没关系。僵尸需要它们。";
//普通僵尸的构造函数
BasicZombie::BasicZombie()
{
    hp = 270;//血量
    atk = 100 * 33 / 1000;//攻击
    speed = 80.0 * 33 / 1000 / 4.7;//移动速度
    setName(name);
    setInfo(info);

    //随机设置两种移动状态
    if (rand() % 2)
        setMovie(":/pvz.res/ZombieWalk1.gif");
    else
        setMovie(":/pvz.res/ZombieWalk2.gif");
}

//有三种状态，行走，攻击，死亡，分别记为0，1，2。
void BasicZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {//死亡
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
    {//吃植物
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        plant->hp -= atk;
        if (state != 1)
        {
            state = 1;
            setMovie(":/pvz.res/ZombieAttack.gif");
        }
        return;
    }
    if (state)
    {//行走
        state = 0;
        if (rand() % 2)
            setMovie(":/pvz.res/ZombieWalk1.gif");
        else
            setMovie(":/pvz.res/ZombieWalk2.gif");
    }
    setX(x() - speed);
}
