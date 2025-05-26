#include "basiczombie.h"

//普通僵尸的构造函数
BasicZombie::BasicZombie()
{
    hp = 270;//血量
    atk = 100 * 33 / 1000;//攻击
    speed = 80.0 * 33 / 1000 / 4.7;//移动速度

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


QMovie* BasicZombie::getMovie(){
    return movie;
}

