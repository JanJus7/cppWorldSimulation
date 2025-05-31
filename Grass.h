#pragma once
#include "Plant.h"

class Grass : public Plant
{
public:
    Grass(const Position &position);
    Grass();
    Organism *Reproduce(const Position &newPos) const override;
    void placeholder() const override {}
    void serialize(std::ostream &out) const override;
    void deserialize(std::istream &in) override;
    virtual ~Grass();
};
