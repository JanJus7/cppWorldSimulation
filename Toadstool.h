#pragma once
#include "Plant.h"

class Toadstool : public Plant
{
public:
    Toadstool(const Position &position);
    Toadstool();
    Organism *Reproduce(const Position &newPos) const override;
    void placeholder() const override {}
    void serialize(std::ostream &out) const override;
    void deserialize(std::istream &in) override;
    virtual ~Toadstool();
};