#include "Wolf.h"
#include <iostream>

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

void Wolf::serialize(std::ostream &out) const
{
    int power = getPower();
    int x = position.getX();
    int y = position.getY();
    out.write((char *)&power, sizeof(int));
    out.write((char *)&x, sizeof(int));
    out.write((char *)&y, sizeof(int));
}

void Wolf::deserialize(std::istream &in)
{
    int power, x, y;
    in.read((char *)&power, sizeof(int));
    in.read((char *)&x, sizeof(int));
    in.read((char *)&y, sizeof(int));
    setPower(power);
    position = Position(x, y);
}

Wolf::~Wolf() {}