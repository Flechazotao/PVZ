#ifndef DUCKYTUBEZOMBIE2_H
#define DUCKYTUBEZOMBIE2_H

#include "zombie.h"
#include "plant.h"

class DuckyTubeZombie2: public Zombie
{
public:
    DuckyTubeZombie2();
    void advance(int phase) override;
};

#endif // DUCKYTUBEZOMBIE2_H
