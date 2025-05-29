#include "Milkweed.h"

Milkweed::Milkweed(const Position &position)
    : Plant(0, position)
{
    setSpecies("D");
    setInitiative(0);
    setLiveLength(6);
    setPowerToReproduce(2);
}

Milkweed::Milkweed() : Plant(0, Position(0, 0))
{
    setSpecies("D");
    setInitiative(0);
    setLiveLength(6);
    setPowerToReproduce(2);
}

Organism *Milkweed::Reproduce(const Position &newPos) const
{
    return new Milkweed(newPos);
}

Milkweed::~Milkweed() {}
