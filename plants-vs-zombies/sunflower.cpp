#include "sunflower.h"
#include <QDebug>
#include <string>
using namespace std;

static string name = "向日葵";
static string info = "向日葵，为你生产额外阳光的经济作物。\n尝试尽可能多种植吧！\n阳光产量：中等\n向日葵情不自禁地和着节拍起舞。是什么节拍呢？\n嗨，是大地自己用来提神的爵士节拍，\n这种频率的节拍，只有向日葵才能听到。\n花费:50\t冷却:7s";
SunFlower::SunFlower()
{
    hp = 300;
    time = int(10.0 * 1000 / 33);
    setMovie(":/Picture/Plant/sunflower/1.gif");
    setInfo(info);
    setName(name);
}

void SunFlower::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new Sun(pos()));
    }
}

