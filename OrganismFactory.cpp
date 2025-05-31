#include "OrganismFactory.h"
#include "Sheep.h"
#include "Wolf.h"
#include "Grass.h"
#include "Milkweed.h"
#include "Toadstool.h"

Organism *OrganismFactory::createOrganism(const std::string &species, const Position &pos)
{
    if (species == "S")
        return new Sheep(pos);
    if (species == "W")
        return new Wolf(pos);
    if (species == "G")
        return new Grass(pos);
    if (species == "M")
        return new Milkweed(pos);
    if (species == "T")
        return new Toadstool(pos);
    return nullptr;
}
