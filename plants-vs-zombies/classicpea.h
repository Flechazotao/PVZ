#ifndef CLASSICPEA_H
#define CLASSICPEA_H

#include "other.h"

class classicPea : public Other
{
public:
    classicPea(int attack = 0, bool flag = false);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;

private:
    bool snow;
    int atk;
    qreal speed;
};

#endif // PEA_H
