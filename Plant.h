#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	Plant(int power, const Position &position); // added const
	Plant();

	void move(int dx, int dy) override;
	virtual ~Plant() {} // virtual destructor, stops memory leaks
};
