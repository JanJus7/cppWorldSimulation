#include "Animal.h"

Animal::Animal(int power, const Position &position) // added const
	: Organism(power, position)
{
	setSpecies("A");
}

Animal::Animal() : Organism()
{
	setSpecies("A");
}
