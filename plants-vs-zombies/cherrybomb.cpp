#include "cherrybomb.h"

CherryBomb::CherryBomb()
{
    atk = 1800;
    hp = 300;
    setMovie(":/pvz.res/CherryBomb.gif");
}

QRectF CherryBomb::boundingRect() const
{
    return state ? QRectF(-150, -150, 300, 300) : Plant::boundingRect();
}

void CherryBomb::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;

    //由正常状态到爆炸状态
    else if (state == 0 && movie->currentFrameNumber() == movie->frameCount() - 1)
    {
        state = 1;
        setMovie(":/pvz.res/Boom.gif");
        QList<QGraphicsItem *> items = collidingItems();
        foreach (QGraphicsItem *item, items)
        {
            Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
            zombie->hp -= atk;
            //附近范围内的僵尸变为烧焦状态
            if (zombie->hp <= 0)
            {
                zombie->state = 3;
                zombie->setMovie(":/pvz.res/Burn.gif");
            }
        }
    }
    else if (state == 1 && movie->currentFrameNumber() == movie->frameCount() - 1)
        delete this;
}

bool CherryBomb::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && QLineF(pos(), other->pos()).length() < 160;
}
