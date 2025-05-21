#include "Organism.h"

Organism::Organism(int power, Position position)
	: power(power), position(position), species("O") {} // Refactored constructor with parametesr

int Organism::getPower() const // added const necause it doesn't change the object
{
	return power; // no need of this->, no object modification
}

void Organism::setPower(int power)
{
	this->power = power; // this-> stayed cus "set" - it modifes the object
}

Position Organism::getPosition() const // added const
{
	return position; // no need of this->
}

void Organism::setPosition(const Position &position) // added const now it doesn't make a copy of an object
{
	this->position = position;
}

string Organism::toString() const // added const
{
	return "{ species: " + getSpecies() +
		   ", power: " + to_string(getPower()) +
		   ", position: " + getPosition().toString() + "}";
}

void Organism::move(int dx, int dy)
{
	position.move(dx, dy);
}

string Organism::getSpecies() const // added const
{
	return species;
}

void Organism::setSpecies(const string &spec) // added const
{
	species = spec; // no need of this->, no name conflict
}