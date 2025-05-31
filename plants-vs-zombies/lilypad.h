#ifndef LILYPAD_H
#define LILYPAD_H

#include "other.h"
#include "plant.h"
#include "zombie.h"

class lilypad: public Plant,public Other
{
public:
    lilypad();
    void advance(int phase) override;
};

#endif // LILYPAD_H
