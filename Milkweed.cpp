#include "Milkweed.h"
#include <iostream>

Milkweed::Milkweed(const Position &position)
    : Plant(0, position)
{
    setSpecies("D");
    setInitiative(0);
    setLiveLength(6);
    setPowerToReproduce(5);
}

Milkweed::Milkweed() : Plant(0, Position(0, 0))
{
    setSpecies("D");
    setInitiative(0);
    setLiveLength(6);
    setPowerToReproduce(5);
}

Organism *Milkweed::Reproduce(const Position &newPos) const
{
    return new Milkweed(newPos);
}

void Milkweed::serialize(std::ostream &out) const
{
    int power = getPower();
    int x = position.getX();
    int y = position.getY();
    out.write((char *)&power, sizeof(int));
    out.write((char *)&x, sizeof(int));
    out.write((char *)&y, sizeof(int));
}

void Milkweed::deserialize(std::istream &in)
{
    int power, x, y;
    in.read((char *)&power, sizeof(int));
    in.read((char *)&x, sizeof(int));
    in.read((char *)&y, sizeof(int));
    setPower(power);
    position = Position(x, y);
}

Milkweed::~Milkweed() {}
