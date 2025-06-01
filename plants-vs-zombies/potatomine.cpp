#include "potatomine.h"
#include <string>
using namespace std;

static string name="土豆雷";
static string info="土豆雷具有强大的威力，\n但是他们需要点时间来武装自己。\n你应把他们种在僵尸前进的路上\n当他们一被接触就会发生爆炸。\n伤害：巨大\n范围：一个小区域内的所有僵尸\n使用方法：单独使用，需要准备时间。\n一些人说土豆雷很懒，\n因为他总是把所有事情留到最后。\n花费：25\t冷却：30秒";

PotatoMine::PotatoMine()
{
    atk = 1800;
    hp = 300;
    time = int(15.0 * 1000 / 33);
    setMovie(":/Picture/Plant/potatomine/1.gif");
    setName(name);
    setInfo(info);
}

QRectF PotatoMine::boundingRect() const
{
    return state == 2 ? QRectF(-75, -75, 150, 150) : Plant::boundingRect();
}

//土豆雷有0，1，2三个状态，0：等CD中，1：准备状态，2：爆炸状态
void PotatoMine::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (state == 0 && ++counter >= time)
    {//CD已满，进入准备状态
        state = 1;
        counter = 0;
        time = int(1.0 * 1000 / 33);
        setMovie(":/Picture/Plant/potatomine/PotatoMine.gif");
    }
    else if (state == 1 && ++counter >= time)
    {
        counter = 0;
        QList<QGraphicsItem *> items = collidingItems();
        if (!items.isEmpty())
        {//爆炸状态
            state = 2;
            setMovie(":/Picture/Plant/potatomine/PotatoMine_mashed.gif");
            foreach (QGraphicsItem *item, items)
            {
                Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
                zombie->hp -= atk;
                if (zombie->hp <= 0)
                    delete zombie;
            }
            //setMovie(":/Picture/Plant/potatomine/ExplosionSpudow.gif");
        }
    }
    //爆炸动画结束
    else if (state == 2 && movie->currentFrameNumber() == movie->frameCount() - 1)
        delete this;
}

bool PotatoMine::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 50;
}
