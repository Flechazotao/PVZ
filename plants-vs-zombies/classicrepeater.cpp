#include "classicrepeater.h"

classicRepeater::classicRepeater() {
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/pvz.res/Repeater.gif");
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
