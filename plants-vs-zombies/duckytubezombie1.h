#ifndef DUCKYTUBEZOMBIE1_H
#define DUCKYTUBEZOMBIE1_H

#include "zombie.h"
#include "plant.h"

class DuckyTubeZombie1: public Zombie
{
public:
    DuckyTubeZombie1();
    void advance(int phase) override;
};

#endif // DUCKYTUBEZOMBIE1_H
