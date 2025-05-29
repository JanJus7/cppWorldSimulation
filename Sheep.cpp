#include "Sheep.h"

Sheep::Sheep(const Position &position)
    : Animal(3, position)
{
    setSpecies("S");
    setInitiative(3);
    setLiveLength(10);
    setPowerToReproduce(6);
}

Sheep::Sheep() : Animal(3, Position(0, 0))
{
    setSpecies("S");
    setInitiative(3);
    setLiveLength(10);
    setPowerToReproduce(6);
}

Organism *Sheep::Reproduce(const Position &newPos) const
{
    return new Sheep(newPos);
}

bool Sheep::canEat(const Organism *other) const
{
    return other->getSpecies() == "G";
}

Sheep::~Sheep() {}