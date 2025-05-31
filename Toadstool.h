#pragma once
#include "Plant.h"

class Toadstool : public Plant
{
public:
    Toadstool(const Position &position);
    Toadstool();
    Organism *Reproduce(const Position &newPos) const override;
    void placeholder() const override {}
    virtual ~Toadstool();
};