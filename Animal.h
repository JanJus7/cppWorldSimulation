#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	Animal(int power, const Position &position); // added const
	Animal();
	virtual ~Animal() {} // vitual destructor, stops memory leaks
};
