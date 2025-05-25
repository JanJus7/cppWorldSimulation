#pragma once
#include "Plant.h"

class Grass : public Plant
{
public:
    Grass(const Position &position);
    Grass();
    Organism *Reproduce(const Position &newPos) const override;
    virtual ~Grass();
};
