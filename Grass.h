#pragma once
#include "Plant.h"

class Grass : public Plant
{
    public:
        Grass(const Position &position);
        Grass();
        virtual ~Grass() {}

};