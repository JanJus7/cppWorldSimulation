#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	Animal(int power, const Position &position); // added const
	Animal();
	// virtual Organism *Reproduce(const Position &newPos) const = 0;
	virtual bool canEat(const Organism *other) const = 0;
	virtual ~Animal(); // vitual destructor, stops memory leaks
};
