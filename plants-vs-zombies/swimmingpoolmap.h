#ifndef SWIMMINGPOOLMAP_H
#define SWIMMINGPOOLMAP_H

#include "other.h"
#include "plant.h"
#include "classicshop.h"
#include "shovel.h"
#include <QGraphicsSceneDragDropEvent>

class swimmingpoolmap : public Other
{
public:
    swimmingpoolmap() {
        dragOver = false;
        setAcceptDrops(true);
    }
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;

private:
    bool dragOver;
};

#endif // BLOCK_H
