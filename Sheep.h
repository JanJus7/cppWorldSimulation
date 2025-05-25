#pragma once
#include "Animal.h"

class Sheep : public Animal
{
    public:
        Sheep(const Position &position);
        Sheep();
        Organism* Reproduce(const Position& newPos) const override;
        virtual ~Sheep(); // virtual destructor, stops memory leaks
};