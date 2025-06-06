#ifndef CLASSICSHOP_H
#define CLASSICSHOP_H


#include "plant.h"
#include "other.h"
#include "classcard.h"
#include "classicsun.h"
#include "classicsunflower.h"
#include "classicpeashooter.h"
#include "cherrybomb.h"
#include "wallnut.h"
#include "classicsnowpea.h"
#include "potatomine.h"
#include "classicrepeater.h"
#include "basiczombie.h"

class classicshop : public Other
{
public:
    int sun;
    classicshop();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void addPlant(QString s, QPointF pos);
private:
    int counter;
    int time;
};

#endif

