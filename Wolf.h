#pragma once
#include "Animal.h"

class Wolf : public Animal
{
    public:
        Wolf(const Position &position);
        Wolf();
        Organism *Reproduce(const Position &newPos) const override;
        bool canEat(const Organism *other) const override;
        virtual ~Wolf();
};