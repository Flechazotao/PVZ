#include "peashooter.h"

Peashooter::Peashooter()
{
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/pvz.res/Peashooter.gif");
}

void Peashooter::advance(int phase)
{
    if (!phase)
        return;
    //重绘
    update();
    //死亡
    if (hp <= 0)
        delete this;
    //装弹完成
    else if (++counter >= time)
    {
        counter = 0;
        //检测到有僵尸
        if (!collidingItems().isEmpty())
        {
            //发射豌豆
            Pea *pea = new Pea(atk);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool Peashooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}
