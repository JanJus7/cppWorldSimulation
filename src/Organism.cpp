#include "Organism.h"
#include <iostream>

using namespace std;

Organism::Organism(int power, Position position)
    : power(power), position(position), species("O") {} // Refactored constructor with parametesr

Organism::Organism(const Organism &other)
    : power(other.power),
      position(other.position),
      species(other.species),
      initiative(other.initiative),
      liveLength(other.liveLength),
      powerToReproduce(other.powerToReproduce),
      ancestors(other.ancestors) {}

Organism::Organism(Organism &&other) noexcept
    : power(other.power),
      position(std::move(other.position)),
      species(std::move(other.species)),
      initiative(other.initiative),
      liveLength(other.liveLength),
      powerToReproduce(other.powerToReproduce),
      ancestors(std::move(other.ancestors)) {}

Organism &Organism::operator=(const Organism &other)
{
    if (this != &other)
    {
        power = other.power;
        position = other.position;
        species = other.species;
        initiative = other.initiative;
        liveLength = other.liveLength;
        powerToReproduce = other.powerToReproduce;
        ancestors = other.ancestors;
    }
    return *this;
}

Organism &Organism::operator=(Organism &&other) noexcept
{
    if (this != &other)
    {
        power = other.power;
        position = std::move(other.position);
        species = std::move(other.species);
        initiative = other.initiative;
        liveLength = other.liveLength;
        powerToReproduce = other.powerToReproduce;
        ancestors = std::move(other.ancestors);
    }
    return *this;
}

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

int Organism::getInitiative() const
{
    return initiative;
}

void Organism::setInitiative(int initiative)
{
    this->initiative = initiative;
}

int Organism::getLiveLength() const
{
    return liveLength;
}

void Organism::setLiveLength(int length)
{
    this->liveLength = length;
}

int Organism::getPowerToReproduce() const
{
    return powerToReproduce;
}

void Organism::setPowerToReproduce(int power)
{
    this->powerToReproduce = power;
}

Organism::~Organism() {}

void Organism::addAncestor(int birthTurn, int deathTurn)
{
    ancestors.emplace_back(birthTurn, deathTurn);
}

const vector<pair<int, int>> &Organism::getAncestors() const
{
    return ancestors;
}

void Organism::printAncestors() const
{
    cout << "Ancestors: ";
    for (const auto &[birth, death] : ancestors)
        cout << "(" << birth << ", " << death << ") ";
    cout << endl;
}
