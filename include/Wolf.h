#pragma once
#include "Animal.h"

class Wolf : public Animal
{
public:
    Wolf(const Position &position);
    Wolf();
    Organism *Reproduce(const Position &newPos) const override;
    bool canEat(const Organism *other) const override;
    void serialize(std::ostream &out) const override;
    void deserialize(std::istream &in) override;
    virtual ~Wolf();
};