#include "classicpeashooter.h"

static string name="豌豆射手";
static string info="豌豆射手，你的第一道防线。\n它们通过发射豌豆来攻击僵尸。\n伤害：中等\n一棵植物，怎么能如此快地生长，并发射如此多的豌豆呢？\n豌豆射手：“努力工作，奉献自己，再加上一份阳光，\n高纤维和氧化碳均衡搭配，\n这种健康早餐让一切成为可能。\n花费：100\t冷却：7.5秒";

classicpeashooter::classicpeashooter() {
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/Picture/Plant/peashooter/1.gif");
    setName(name);
    setInfo(info);
}

void classicpeashooter::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            classicPea *pea = new classicPea(atk);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool classicpeashooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}


