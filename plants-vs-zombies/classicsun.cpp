
#include "classicsun.h"
#include "classicshop.h"

classicSun::classicSun()
{
    dest = QPointF(290 + rand() % (82 * 7), 130 + rand() % (98 * 5));
    setPos(QPointF(dest.x(), 70));
    speed = 60.0 * 50 / 1000;
    counter = 0;
    time = int(10.0 * 1000 / 33);
    movie = new QMovie(":/pvz.res/Sun.gif");
    movie->start();
    setAcceptedMouseButtons(Qt::LeftButton);
}

classicSun::classicSun(QPointF pos)
{
    dest = QPointF(pos.x() + rand() % 30 - 15, pos.y() + rand() % 30 + 15);
    setPos(QPointF(dest.x(), pos.y()));
    speed = 60 * 50 / 1000;
    counter = 0;
    time = int(10.0 * 1000 / 33);
    movie = new QMovie(":/pvz.res/Sun.gif");
    movie->start();
    setAcceptedMouseButtons(Qt::LeftButton);
}

classicSun::~classicSun()
{
    if (movie)
        delete movie;
}

QRectF classicSun::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

void classicSun::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(boundingRect(), movie->currentImage());
}

void classicSun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    classicshop *shop = qgraphicsitem_cast<classicshop *>(scene()->items(QPointF(300, 15))[0]);
    shop->sun += 25;
    counter = time;
    event->setAccepted(true);
}

void classicSun::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (++counter >= time)
        delete this;
    else if (y() < dest.y())
        setY(y() + speed);
}
