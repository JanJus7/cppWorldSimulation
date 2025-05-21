#pragma once
#include "Organism.h"

using namespace std;

class Animal : public Organism
{
public:
	Animal(int power, const Position &position); // added const
	Animal();
	virtual ~Animal() {} // vitual destructor, stops memory leaks
};
