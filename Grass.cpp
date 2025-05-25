#include "Grass.h"

Grass::Grass(const Position &position)
    : Plant(0, position)
{
    setSpecies("G");
    setInitiative(0);
    setLiveLength(6);
    setPowerToReproduce(3);
}

Grass::Grass() : Plant(0, Position(0, 0))
{
    setSpecies("G");
    setInitiative(0);
    setLiveLength(6);
    setPowerToReproduce(3);
}