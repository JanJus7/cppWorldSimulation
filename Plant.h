#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	Plant(int power, const Position &position); // added const
	Plant();
	// virtual Organism *Reproduce(const Position &newPos) const = 0;
	virtual void placeholder() const = 0;
	void move(int dx, int dy) override;
	virtual ~Plant(); // virtual destructor, stops memory leaks
};
