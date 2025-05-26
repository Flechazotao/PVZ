#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "plant.h"
#include "sun.h"

class SunFlower : public Plant
{
public:
    SunFlower();
    void advance(int phase) override;
    QMovie* getMovie();
};

#endif // SUNFLOWER_H
