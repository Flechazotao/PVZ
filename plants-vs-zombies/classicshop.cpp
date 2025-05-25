#include "classicshop.h"

classicshop::classicshop() {
    sun = 600;
    counter = 0;
    time = int(7.0 * 1000 / 33);
    classCard *card = nullptr;
    for (int i = 0; i < classCard::name.size(); ++i)
    {
        card = new classCard(classCard::name[i]);
        card->setParentItem(this);
        card->setPos(-157 + 65 * i, -2);
    }
}

QRectF classicshop::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

void classicshop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-270, -45, 540, 90), QPixmap(":/pvz.res/Shop.png"));
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(sun));
    painter->drawPoint(-220, 0);
}

void classicshop::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new classicSun);
    }
}

void classicshop::addPlant(QString s, QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    foreach (QGraphicsItem *item, items)
        if (item->type() == Plant::Type)
            return;
    sun -= classCard::cost[classCard::map[s]];
    Plant *plant = nullptr;
    switch (classCard::map[s])
    {
    case 0:
        plant = new classicSunFlower; break;
    case 1:
        plant = new classicpeashooter; break;
    case 2:
        plant = new CherryBomb; break;
    case 3:
        plant = new WallNut; break;
    case 4:
        plant = new classicSnowPea; break;
    case 5:
        plant = new PotatoMine; break;
    case 6:
        plant = new classicRepeater; break;
    }
    plant->setPos(pos);
    scene()->addItem(plant);
    QList<QGraphicsItem *> child = childItems();
    foreach (QGraphicsItem *item, child)
    {
        classCard *card = qgraphicsitem_cast<classCard *>(item);
        if (card->text == s)
            card->counter = 0;
    }
    counter = 0;
}
