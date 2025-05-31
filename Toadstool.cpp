#include "Toadstool.h"

Toadstool::Toadstool(const Position &position) : Plant(0, position)
{
    setSpecies("T");
    setInitiative(0);
    setLiveLength(12);
    setPowerToReproduce(4);
}

Toadstool::Toadstool() : Plant(0, Position(0, 0))
{
    setSpecies("T");
    setInitiative(0);
    setLiveLength(12);
    setPowerToReproduce(4);
}

Organism *Toadstool::Reproduce(const Position &newPos) const
{
    return new Toadstool(newPos);
}

Toadstool::~Toadstool() {}