#include "classicsnowpea.h"

classicSnowPea::classicSnowPea() {
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/pvz.res/SnowPea.gif");
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
