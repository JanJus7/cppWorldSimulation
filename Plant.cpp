#include "Plant.h"

Plant::Plant(int power, const Position &position) // added const
	: Organism(power, position)
{
	setSpecies("P");
}

Plant::Plant() : Organism()
{
	setSpecies("P");
}

void Plant::move(int dx, int dy) {}

Plant::~Plant() {}

Organism *Plant::Reproduce(const Position &newPos) const
{
	return new Plant(this->getPower(), newPos);
};