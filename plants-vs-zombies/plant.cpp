#include "plant.h"
#include "zombie.h"

//植物基类的构造函数
Plant::Plant()
{
    movie = nullptr;
    atk = counter = state = time = 0;
    information="";
}

Plant::~Plant()
{
    delete movie;
}


//返回边界矩形坐标数值
QRectF Plant::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

//绘制植物
void Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawImage(boundingRect(), movie->currentImage());
}

//判断是否发生碰撞,如果碰撞，僵尸吃植物
bool Plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    //左右30像素内是否存在僵尸
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

int Plant::type() const
{
    return Type;
}

//设置植物动图
void Plant::setMovie(QString path)
{
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}

//设置植物描述
void Plant::setInfo(string &info){
    information=info;
}

//获取植物描述
string Plant::getInfo(){
    return information;
}
