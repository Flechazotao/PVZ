#include "swimmingpoolmap.h"
#include "swimmingpoolshop.h"

QRectF swimmingpoolmap::boundingRect() const {
    return QRectF(-369, -235, 738, 470);
}

void swimmingpoolmap::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
    // painter->setPen(Qt::black);
    // painter->drawRect(boundingRect());
}

//开始拖拽
void swimmingpoolmap::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasText())
    {
        event->setAccepted(true);
        dragOver = true;
        update();
    }
    else
        event->setAccepted(false);
}

//拖拽离开
void swimmingpoolmap::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();
}

//显示拖拽之后的结果：1.铲除植物 2.种植植物
void swimmingpoolmap::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    if (event->mimeData()->hasText())
    {
        //确定位置
        QString s = event->mimeData()->text();
        QPointF pos = mapToScene(event->pos());
        pos.setX((int(pos.x()) - 249) / 82 * 82 + 295);
        pos.setY((int(pos.y()) - 81) / 82 * 82 + 135);

        //铲除植物
        if (s == "Shovel")
        {
            Shovel *shovel = qgraphicsitem_cast<Shovel *>(scene()->items(QPointF(830, 15))[0]);
            shovel->removePlant(pos);
        }
        //种植植物
        else
        {
            swimmingpoolshop * shop = qgraphicsitem_cast<swimmingpoolshop *>(scene()->items(QPointF(300, 15))[0]);
            shop->addPlant(s, pos);
        }
    }
    //重新绘制窗口内容
    update();
}
