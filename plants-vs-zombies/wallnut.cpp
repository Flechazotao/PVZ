#include "wallnut.h"
#include <QDebug>
#include <string>
using namespace std;

static string name="坚果墙";
static string info="坚果墙拥有足以让你用来保护其它植物的坚硬外壳。\n韧性：高坚果墙：“人们想知道，经常被僵尸啃的感觉怎样？\n他们不知道，我有限的感官，\n只能让我感到一种麻麻的感觉，\n像是，令人放松的背部按摩。\n花费：50\t冷却：15.5秒";
WallNut::WallNut()
{
    hp = 4000;
    setMovie(":/pvz.res/WallNut.gif");
    setInfo(info);
    setName(name);
}
//坚果墙有1，2状态，2：血量多，1：血量少
void WallNut::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (hp <= 1333 && state != 2)
    {
        state = 2;
        setMovie(":/pvz.res/WallNut2.gif");
    }
    else if (1333 < hp && hp <= 2667 && state != 1)
    {
        state = 1;
        setMovie(":/pvz.res/WallNut1.gif");
    }
}
