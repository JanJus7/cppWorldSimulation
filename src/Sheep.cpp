#include "Sheep.h"
#include <iostream>

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

void Sheep::serialize(std::ostream &out) const
{
    int power = getPower();
    int x = getPosition().getX();
    int y = getPosition().getY();
    out.write((char *)&power, sizeof(int));
    out.write((char *)&x, sizeof(int));
    out.write((char *)&y, sizeof(int));
}

void Sheep::deserialize(std::istream &in)
{
    int power, x, y;
    in.read((char *)&power, sizeof(int));
    in.read((char *)&x, sizeof(int));
    in.read((char *)&y, sizeof(int));
    setPower(power);
    position = Position(x, y);
}

Sheep::~Sheep() {}