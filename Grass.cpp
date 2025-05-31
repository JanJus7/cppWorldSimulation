#include "Grass.h"
#include <iostream>

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

Organism *Grass::Reproduce(const Position &newPos) const
{
    return new Grass(newPos);
}

void Grass::serialize(std::ostream &out) const
{
    int power = getPower();
    int x = position.getX();
    int y = position.getY();
    out.write((char *)&power, sizeof(int));
    out.write((char *)&x, sizeof(int));
    out.write((char *)&y, sizeof(int));
}

void Grass::deserialize(std::istream &in)
{
    int power, x, y;
    in.read((char *)&power, sizeof(int));
    in.read((char *)&x, sizeof(int));
    in.read((char *)&y, sizeof(int));
    setPower(power);
    position = Position(x, y);
}

Grass::~Grass() {}
