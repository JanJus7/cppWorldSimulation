#pragma once
#include "Plant.h"

class Milkweed : public Plant
{
public:
    Milkweed(const Position &position);
    Milkweed();
    Organism *Reproduce(const Position &newPos) const override;
    virtual ~Milkweed();
};
