#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	Animal(int power, const Position &position); // added const
	Animal();
	Organism* Reproduce(const Position& newPos) const override;
	virtual ~Animal(); // vitual destructor, stops memory leaks
};
