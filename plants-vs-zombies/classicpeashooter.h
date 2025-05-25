#ifndef CLASSICPEASHOOTER_H
#define CLASSICPEASHOOTER_H
#include "plant.h"
#include "zombie.h"
#include "classicpea.h"

class classicpeashooter : public Plant
{
public:
    classicpeashooter();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // PEASHOOTER_H

