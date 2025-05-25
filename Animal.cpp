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

Animal::~Animal() {}

Organism* Animal::Reproduce(const Position& newPos) const {
    return new Animal(this->getPower(), newPos);
}