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
    return (gridY == 2 || gridY == 3);
}

// 种植植物
void swimmingpoolshop::addPlant(QString s, QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    int plantType = swimmingpoolcard::map[s];
    bool isWater = isWaterTile(pos);

    // 非莲叶植物水上种植逻辑
    if (plantType != 5 && isWater) {
        if (sun < swimmingpoolcard::cost[plantType]) {
            qDebug() << "阳光不足!";
            return;
        }

        //定位到荷叶坐标;
        QPointF adjustedPos = pos;
        adjustedPos.setY(pos.y() + 20);
        QList<QGraphicsItem*> items = scene()->items(adjustedPos);
        lilypad *targetPad = nullptr;
        foreach (QGraphicsItem *item, items) {
            if (item->type() == lilypad::Type) {
                lilypad *pad = static_cast<lilypad*>(item);
                if (!pad->hasPlant()) {
                    targetPad = pad;
                    break;
                } else {
                    qDebug() << "莲叶上已有植物，无法种植！";
                    return;
                }
            }
        }
        if (!targetPad) {
            qDebug() << "水面上没有可用的莲叶！";
            return;
        }

        sun -= swimmingpoolcard::cost[plantType];
        Plant *plant = createPlantByType(plantType);
        scene()->addItem(plant);
        plant->setZValue(1);
        targetPad->setHostedPlant(plant);
        updateCardState(s);
        return;
    }

    // 莲叶只能种在水上
    if (plantType == 5 && !isWater) return;

    // 陆地种植逻辑
    if (isPositionOccupied(items)) return;

    if (sun < swimmingpoolcard::cost[plantType]) {
        qDebug() << "阳光不足!";
        return;
    }

    sun -= swimmingpoolcard::cost[plantType];
    Plant *plant = createPlantByType(plantType);

    // 特殊处理莲叶位置
    QPointF adjustedPos = pos;
    if (plantType == 5)     adjustedPos.setY(pos.y() + 20);
    plant->setPos(adjustedPos);
    scene()->addItem(plant);
    plant->setZValue(1);

    updateCardState(s);
}

// 辅助函数：创建植物
Plant* swimmingpoolshop::createPlantByType(int type)
{
    switch (type) {
    case 0: return new classicSunFlower;
    case 1: return new classicpeashooter;
    case 2: return new CherryBomb;
    case 3: return new WallNut;
    case 4: return new classicSnowPea;
    case 5: return new lilypad;
    case 6: return new classicRepeater;
    default: return nullptr;
    }
}

// 辅助函数：检查位置是否被占用
bool swimmingpoolshop::isPositionOccupied(const QList<QGraphicsItem*>& items)
{
    foreach (QGraphicsItem *item, items)
    if (item->type() == Plant::Type || item->type() == lilypad::Type)
        return true;
    return false;
}

// 辅助函数：更新卡片状态
void swimmingpoolshop::updateCardState(const QString& cardText)
{
    foreach (QGraphicsItem *item, childItems()) {
        if (auto card = dynamic_cast<swimmingpoolcard *>(item)) {
            if (card->text == cardText) card->counter = 0;
        }
    }
    counter = 0;
}
