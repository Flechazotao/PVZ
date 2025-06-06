#ifndef CLASSICSUN_H
#define CLASSICSUN_H

#include "other.h"

class classicSun : public Other
{
public:
    classicSun();
    classicSun(QPointF pos);
    ~classicSun() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void advance(int phase) override;

private:
    QMovie *movie;
    QPointF dest;
    int counter;
    int time;
    qreal speed;
};

#endif // SUN_H
