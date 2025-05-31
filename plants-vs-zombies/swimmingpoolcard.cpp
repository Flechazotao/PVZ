#include "swimmingpoolcard.h"
#include "swimmingpoolshop.h"

const QMap<QString, int> swimmingpoolcard::map = {{"SunFlower", 0}, {"Peashooter", 1}, {"CherryBomb", 2}, {"WallNut", 3},
                                      {"SnowPea", 4}, {"LilyPad", 5}, {"Repeater", 6}};
const QVector<QString> swimmingpoolcard::name = {"SunFlower", "Peashooter", "CherryBomb", "WallNut",
                                     "SnowPea", "LilyPad", "Repeater"};
const QVector<int> swimmingpoolcard::cost = {50, 100, 150, 50, 175, 25, 200};
const QVector<int> swimmingpoolcard::cool = {227, 227, 606, 606, 227, 227, 227};

swimmingpoolcard::swimmingpoolcard(QString s)
{
    text = s;
    counter = 0;
}

QRectF swimmingpoolcard::boundingRect() const
{
    return QRectF(-50, -30, 100, 60);
}

void swimmingpoolcard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->scale(0.6, 0.58);
    painter->drawPixmap(QRect(-50, -70, 100, 140), QPixmap(":/pvz.res/Card.png"));
    painter->drawPixmap(QRect(-35, -42, 70, 70), QPixmap(":/pvz.res/" + text + ".png"));
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(-30, 60, QString().asprintf("%3d", cost[map[text]]));
    if (counter < cool[map[text]])
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(-48, -68, 98, 132 * (1 - qreal(counter) / cool[map[text]])));
    }
    swimmingpoolshop *shop = qgraphicsitem_cast<swimmingpoolshop *>(parentItem());
    if(cost[map[text]] > shop->sun)
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(-48, -68, 98, 136));
    }
}

void swimmingpoolcard::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (counter < cool[map[text]])
        ++counter;
}

void swimmingpoolcard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if (counter < cool[map[text]])
        event->setAccepted(false);
    swimmingpoolshop *shop = qgraphicsitem_cast<swimmingpoolshop *>(parentItem());
    if (cost[map[text]] > shop->sun)
        event->setAccepted(false);
    setCursor(Qt::ArrowCursor);
}

void swimmingpoolcard::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
        < QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    QImage image(":/pvz.res/" + text + ".png");
    mime->setText(text);
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image));
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}

void swimmingpoolcard::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}
