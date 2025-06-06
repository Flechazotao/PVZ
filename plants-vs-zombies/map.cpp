#include "map.h"

Map::Map()
{
    dragOver = false;
    setAcceptDrops(true);
}

//返回边界矩形坐标数值
QRectF Map::boundingRect() const
{
    return QRectF(-369, -235, 738, 470);
}

void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
    // painter->setPen(Qt::black);
    // painter->drawRect(boundingRect());
}

//开始拖拽
void Map::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
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
void Map::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();
}

//显示拖拽之后的结果：1.铲除植物 2.种植植物
void Map::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    if (event->mimeData()->hasText())
    {
        //确定位置
        QString s = event->mimeData()->text();
        QPointF pos = mapToScene(event->pos());
        pos.setX((int(pos.x()) - 249) / 82 * 82 + 290);
        pos.setY((int(pos.y()) - 81) / 98 * 98 + 130);
        //铲除植物
        if (s == "Shovel")
        {
            Shovel *shovel = qgraphicsitem_cast<Shovel *>(scene()->items(QPointF(830, 15))[0]);
            shovel->removePlant(pos);
        }
        //种植植物
        else
        {
            Shop *shop = qgraphicsitem_cast<Shop *>(scene()->items(QPointF(300, 15))[0]);
            shop->addPlant(s, pos);
        }
    }
    //重新绘制窗口内容
    update();
}
