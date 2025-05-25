#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>

class Zombie : public QGraphicsItem
{
public:
    //僵尸的血量
    int hp;
    //僵尸的攻击伤害
    int atk;
    //僵尸的移动速度
    int state;
    qreal speed;
    enum { Type = UserType + 2};
    Zombie();
    ~Zombie() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    int type() const override;
    void setMovie(QString path);
    void setHead(QString path);

protected:
    QMovie *movie;
    QMovie *head;
};

#endif // ZOOMBIE_H
