#ifndef CLASSICSNOWPEA_H
#define CLASSICSNOWPEA_H

#include "plant.h"
#include "zombie.h"
#include "classicpea.h"

class classicSnowPea : public Plant
{
public:
    classicSnowPea();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // SNOWPEA_H
