#include "swimmingpoolshop.h"
#include "classicsunflower.h"
#include "lilypad.h"
#include "swimmingpoolcard.h"

swimmingpoolshop::swimmingpoolshop()
{
    sun = 600;
    counter = 0;
    time = int(7.0 * 1000 / 33);
    swimmingpoolcard *card = nullptr;
    for (int i = 0; i < swimmingpoolcard::name.size(); ++i)
    {
        card = new swimmingpoolcard(swimmingpoolcard::name[i]);
        card->setParentItem(this);
        card->setPos(-157 + 65 * i, -2);
    }
}

QRectF swimmingpoolshop::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

void swimmingpoolshop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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

void swimmingpoolshop::advance(int phase)
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

// 辅助函数：判断是否是水面格子
bool swimmingpoolshop::isWaterTile(QPointF pos) const
{
    int gridY = (int(pos.y()) - 81) / 82;
    return (gridY == 2 || gridY == 3); //
}

//种植植物;
void swimmingpoolshop::addPlant(QString s, QPointF pos)
{

    QList<QGraphicsItem *> items = scene()->items(pos);

    //获取植物类型;
    int plantType = swimmingpoolcard::map[s];

    //判断当前是否为泳池区域;
    bool isWater = isWaterTile(pos);

    //选择的不是莲叶且是泳池区域
    //需要种在莲叶上面;
    if (plantType != 5 && isWater) { // 5是荷叶的编号
        qDebug() << "进入水域检查";
        lilypad *targetPad = nullptr;

        // 查找点击位置的所有莲叶
        foreach (QGraphicsItem *item, items) {
            if (item->type() == Plant::Type) {
                lilypad *pad = qgraphicsitem_cast<lilypad *>(item);
                if (pad) {
                    // 找到莲叶后检查是否已有植物
                    if (!pad->hasPlant()) {
                        targetPad = pad;
                        break; // 使用第一个可用的莲叶
                    } else {
                        qDebug() << "莲叶上已有植物";
                    }
                }
            }
        }
        if (!targetPad) {
            // 提示需要先放置莲叶或莲叶已被占用
            qDebug() << "Cannot plant on water without available lily pad!";
            return;
        }

        // 检查阳光是否足够
        if (sun < swimmingpoolcard::cost[plantType]) {
            qDebug() << "Not enough sun!";
            return;
        }
        //扣除阳光;
        sun -= swimmingpoolcard::cost[swimmingpoolcard::map[s]];

        Plant *plant = nullptr;
        switch (swimmingpoolcard::map[s])
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
            plant = new lilypad; break;
        case 6:
            plant = new classicRepeater; break;
        }
        targetPad->setHostedPlant(plant);
        plant->setZValue(1);//图层1;
        plant->setPos(pos);
        scene()->addItem(plant);
        QList<QGraphicsItem *> child = childItems();
        foreach (QGraphicsItem *item, child)
        {
            swimmingpoolcard *card = qgraphicsitem_cast<swimmingpoolcard *>(item);
            if (card->text == s)
                card->counter = 0;
        }
        counter = 0;
        return;
    }
    //选择的是莲叶,那么只能种植在泳池区域.否则直接return;
    else if(plantType==5 && !isWater){
        return;
    }

        //先检查位置是否已经被种植
        foreach (QGraphicsItem *item, items)
            if (item->type() == Plant::Type)
                return;

        // 检查阳光是否足够
        if (sun < swimmingpoolcard::cost[plantType]) {
            qDebug() << "Not enough sun!";
            return;
        }
        //扣除阳光;
        sun -= swimmingpoolcard::cost[swimmingpoolcard::map[s]];

        //顺利种植;
        Plant *plant = nullptr;
        switch (swimmingpoolcard::map[s])
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
            plant = new lilypad; break;
        case 6:
            plant = new classicRepeater; break;
        }
        if(plantType==5)
        {
            QPointF adjustedPos = pos;
            adjustedPos.setY(pos.y() + 20);
            plant->setZValue(1);//图层1;
            plant->setPos(adjustedPos);
        }
        else
        {
            plant->setPos(pos);
            plant->setZValue(1);//图层1;
        }

        scene()->addItem(plant);
        QList<QGraphicsItem *> child = childItems();
        foreach (QGraphicsItem *item, child)
        {
            swimmingpoolcard *card = qgraphicsitem_cast<swimmingpoolcard *>(item);
            if (card->text == s)
                card->counter = 0;
        }
        counter = 0;
        return;
}
