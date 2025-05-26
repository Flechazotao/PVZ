#ifndef BASICZOMBIE_H
#define BASICZOMBIE_H

#include "zombie.h"
#include "plant.h"

class BasicZombie : public Zombie
{
public:
    BasicZombie();
    void advance(int phase) override;
    QMovie* getMovie();
};

#endif // BASICZOMBIE_H
