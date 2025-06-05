#pragma once
#include <string>
#include "Organism.h"
#include "Position.h"

class OrganismFactory
{
public:
    static Organism *createOrganism(const std::string &species, const Position &pos);
};
