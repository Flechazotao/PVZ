#ifndef LILYPAD_H
#define LILYPAD_H

#include "other.h"
#include "plant.h"
#include "zombie.h"

class lilypad: public Plant
{
public:
    lilypad();
    void advance(int phase) override;
    bool hasPlant();
    void setHostedPlant(Plant *newplant);
    QRectF boundingRect() const override;
private:
    Plant*p=nullptr;    //表示莲上的植物;
};

#endif // LILYPAD_H
