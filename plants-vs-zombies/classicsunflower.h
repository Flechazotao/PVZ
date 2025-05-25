#ifndef CLASSICSUNFLOWER_H
#define CLASSICSUNFLOWER_H

#include "plant.h"
#include "classicsun.h"

class classicSunFlower : public Plant
{
public:
    classicSunFlower();
    void advance(int phase) override;
};

#endif // SUNFLOWER_H
