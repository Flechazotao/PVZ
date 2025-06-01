#include "cherrybomb.h"
#include <string>
using namespace std;

static string name="樱桃炸弹";
static string info="樱桃炸弹，能炸掉一定区域内所有僵尸。\n他们种下就会立刻引爆。\n所以请把他们种在僵尸们的身边。\n伤害：巨大\n范围：一个中等区域内的所有僵尸\n使用方法：单独使用，立即爆炸\n“我要爆‘开了。”樱桃一号说。\n”不，我们是炸‘开了！”它哥哥樱桃二号说。\n经过激烈的商议之后，他们才统一”爆炸这个说法。\n花费：150\t冷却：20秒";

CherryBomb::CherryBomb()
{
    atk = 1800;
    hp = 300;
    setMovie(":/Picture/Plant/cherrybomb/1.gif");
    setName(name);
    setInfo(info);
}

QRectF CherryBomb::boundingRect() const
{
    return state ? QRectF(-150, -150, 300, 300) : Plant::boundingRect();
}

void CherryBomb::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;

    //由正常状态到爆炸状态
    else if (state == 0 && movie->currentFrameNumber() == movie->frameCount() - 1)
    {
        state = 1;
        setMovie(":/Picture/Plant/cherrybomb/Boom.gif");
        QList<QGraphicsItem *> items = collidingItems();
        foreach (QGraphicsItem *item, items)
        {
            Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
            zombie->hp -= atk;
            //附近范围内的僵尸变为烧焦状态
            if (zombie->hp <= 0)
            {
                zombie->state = 3;
                zombie->setMovie(":/Picture/Zombie/Zombie/BoomDie.gif");
            }
        }
    }
    else if (state == 1 && movie->currentFrameNumber() == movie->frameCount() - 1)
        delete this;
}

bool CherryBomb::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && QLineF(pos(), other->pos()).length() < 160;
}
