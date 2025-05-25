#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	Plant(int power, const Position &position); // added const
	Plant();
	Organism *Reproduce(const Position &newPos) const override;
	void move(int dx, int dy) override;
	virtual ~Plant(); // virtual destructor, stops memory leaks
};
