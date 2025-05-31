#include "Toadstool.h"
#include <iostream>

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

void Toadstool::serialize(std::ostream &out) const
{
    int power = getPower();
    int x = position.getX();
    int y = position.getY();
    out.write((char *)&power, sizeof(int));
    out.write((char *)&x, sizeof(int));
    out.write((char *)&y, sizeof(int));
}

void Toadstool::deserialize(std::istream &in)
{
    int power, x, y;
    in.read((char *)&power, sizeof(int));
    in.read((char *)&x, sizeof(int));
    in.read((char *)&y, sizeof(int));
    setPower(power);
    position = Position(x, y);
}

Toadstool::~Toadstool() {}