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

void Plant::move(int dx, int dy)
{
	Organism::move(0, 0);
}
