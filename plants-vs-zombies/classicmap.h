#ifndef CLASSICMAP_H
#define CLASSICMAP_H

#include "other.h"
#include"plant.h"
#include "classicshop.h"
#include "shovel.h"
#include <QGraphicsSceneDragDropEvent>

class classicMap : public Other
{
public:
    classicMap();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;

private:
    bool dragOver;
};

#endif // BLOCK_H
