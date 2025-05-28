#include "classicrepeater.h"

static string name="双发射手";
static string info="双发射手可以一次发射两颗豌豆\n伤害：中等(每颗)\n发射速度：两倍\n双发射手很凶悍，他是在街头混大的。\n他不在乎任何人的看法，无论是植物还是僵尸，\n他打出豌豆，是为了让别人离他远点。\n其实呢，双发射手一直暗暗地渴望着爱情。\n花费:200\t冷却：7.5秒";

classicRepeater::classicRepeater() {
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/pvz.res/Repeater.gif");
    setName(name);
    setInfo(info);
}

void classicRepeater::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        QList<QGraphicsItem *> items = collidingItems();
        if (!collidingItems().isEmpty())
        {
            classicPea *pea = new classicPea(atk);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            pea = new classicPea(atk);
            pea->setX(x() + 64);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool classicRepeater::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}
