#pragma once
#include "Plant.h"

class Milkweed : public Plant
{
public:
    Milkweed(const Position &position);
    Milkweed();
    Organism *Reproduce(const Position &newPos) const override;
    void placeholder() const override {}
    void serialize(std::ostream &out) const override;
    void deserialize(std::istream &in) override;
    virtual ~Milkweed();
};
