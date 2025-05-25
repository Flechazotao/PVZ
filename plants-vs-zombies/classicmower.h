#ifndef CLASSICMOWER_H
#define CLASSICMOWER_H

#include "other.h"
#include "zombie.h"

class classicMower : public Other
{
public:
    classicMower();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;

private:
    bool flag;
    qreal speed;
};

#endif
