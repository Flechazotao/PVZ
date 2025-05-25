#ifndef CLASSICREPEATER_H
#define CLASSICREPEATER_H

#include "plant.h"
#include "zombie.h"
#include "classicpea.h"

class classicRepeater : public Plant
{
public:
    classicRepeater();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // REAPTER_H
