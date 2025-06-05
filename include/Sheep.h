#pragma once
#include "Animal.h"

class Sheep : public Animal
{
public:
    Sheep(const Position &position);
    Sheep();
    Organism *Reproduce(const Position &newPos) const override;
    bool canEat(const Organism *other) const override;
    void serialize(std::ostream &out) const override;
    void deserialize(std::istream &in) override;
    virtual ~Sheep(); // virtual destructor, stops memory leaks
};