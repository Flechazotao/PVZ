#ifndef SWIMMINGPOOLCARD_H
#define SWIMMINGPOOLCARD_H

#include "other.h"

class swimmingpoolcard : public Other
{
public:
    int counter;
    QString text;
    swimmingpoolcard(QString s);
    const static QMap<QString, int> map;
    const static QVector<QString> name;
    const static QVector<int> cost;
    const static QVector<int> cool;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
};

#endif // SWIMMINGPOOLCARD_H
