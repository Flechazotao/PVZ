#include "shovel.h"

Shovel::Shovel()
{

}

QRectF Shovel::boundingRect() const
{
    return QRectF(-40, -40, 80, 80);
}

void Shovel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-40, -40, 80, 80), QPixmap(":/pvz.res/ShovelBank.png"));
    painter->drawPixmap(QRect(-35, -35, 70, 70), QPixmap(":/pvz.res/Shovel.png"));
}

void Shovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
        < QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    QImage image(":/pvz.res/Shovel.png");
    mime->setText("Shovel");
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image).scaled(70, 70));
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}

void Shovel::removePlant(QPointF pos) {
    QList<QGraphicsItem*> items = scene()->items(pos);

    foreach (QGraphicsItem *item, items) {
        if (item->type() == Plant::Type) {
            Plant *plant = static_cast<Plant*>(item);

            // 特殊处理莲叶检测
            QRectF detectionRect = plant->boundingRect();
            if (dynamic_cast<lilypad*>(plant)) {   
                detectionRect.translate(0, -20); // 向上补偿20px
            }

            QList<QGraphicsItem*> colliders = scene()->items(
                plant->mapRectToScene(detectionRect)
                );

            foreach (QGraphicsItem *collider, colliders) {
                if (collider != item && collider->type() == lilypad::Type) {
                    qDebug() << "Found lilypad at:" << collider->pos();
                    lilypad *lily = static_cast<lilypad*>(collider); // 转换为lilypad指针
                    lily->clearPlant(); // 调用方法
                }
            }

            delete plant;
            return;
        }
    }
}
