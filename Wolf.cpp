#include "Wolf.h"

Wolf::Wolf(const Position &position)
    : Animal(8, position)
{
    setSpecies("W");
    setInitiative(5);
    setLiveLength(20);
    setPowerToReproduce(16);
}

Wolf::Wolf() : Animal(8, Position(0, 0))
{
    setSpecies("W");
    setInitiative(5);
    setLiveLength(20);
    setPowerToReproduce(16);
}

Organism *Wolf::Reproduce(const Position &newPos) const
{
    return new Wolf(newPos);
}

bool Wolf::canEat(const Organism *other) const
{
    return other->getSpecies() == "S";
}

Wolf::~Wolf() {}