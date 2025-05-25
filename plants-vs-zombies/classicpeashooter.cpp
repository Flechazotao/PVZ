#include "classicpeashooter.h"

classicpeashooter::classicpeashooter() {
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/pvz.res/Peashooter.gif");
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


