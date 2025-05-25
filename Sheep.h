#pragma once
#include "Animal.h"

class Sheep : public Animal
{
    public:
        Sheep(const Position &position);
        Sheep();
        virtual ~Sheep() {} // virtual destructor, stops memory leaks
};