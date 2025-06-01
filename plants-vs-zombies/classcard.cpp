#include "classcard.h"
#include "classicshop.h"
#include<classicshop.h>

const QMap<QString, int> classCard::map = {{"SunFlower", 0}, {"Peashooter", 1}, {"CherryBomb", 2}, {"WallNut", 3},
                                      {"SnowPea", 4}, {"PotatoMine", 5}, {"Repeater", 6}};
const QVector<QString> classCard::name = {"SunFlower", "Peashooter", "CherryBomb", "WallNut",
                                     "SnowPea", "PotatoMine", "Repeater"};
const QVector<int> classCard::cost = {50, 100, 150, 50, 175, 25, 200};
const QVector<int> classCard::cool = {227, 227, 606, 606, 227, 606, 227};

classCard::classCard(QString s)
{
    text = s;
    counter = 0;
}

QRectF classCard::boundingRect() const
{
    return QRectF(-50, -30, 100, 60);
}

void classCard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->scale(0.6, 0.58);
    painter->drawPixmap(QRect(-50, -70, 100, 140), QPixmap(":/Picture/shop/card_"+text+".png"));
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    if (counter < cool[map[text]])
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(-48, -68, 98, 132 * (1 - qreal(counter) / cool[map[text]])));
    }
    classicshop *shop = qgraphicsitem_cast<classicshop *>(parentItem());
    if(cost[map[text]] > shop->sun)
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(-48, -68, 98, 136));
    }
}

void classCard::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (counter < cool[map[text]])
        ++counter;
}

void classCard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    if (counter < cool[map[text]])
        event->setAccepted(false);
    classicshop * Classicshop = qgraphicsitem_cast<classicshop *>(parentItem());
    if (cost[map[text]] > Classicshop->sun)
        event->setAccepted(false);
    setCursor(Qt::ArrowCursor);
}

void classCard::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

void classCard::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}
