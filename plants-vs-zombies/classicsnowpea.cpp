#include "classicsnowpea.h"


static string name="寒冰射手";
static string info="寒冰射手会发射寒冰豌豆来攻击敌人，并具有减速效果。\n伤害：中等，带有减速效果\n人们经常告诉寒冰射手他是多么“冷酷”\n或者告诫他要“冷静”。\n他们叫他要“保持镇静”。\n寒冰射手只是转转他的眼睛。其实他都听见了。\n花费:175\t冷却：7.5秒";

classicSnowPea::classicSnowPea() {
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/pvz.res/SnowPea.gif");
    setName(name);
    setInfo(info);
}

void classicSnowPea::advance(int phase)
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
            classicPea *pea = new classicPea(atk, true);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool classicSnowPea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y());
}
