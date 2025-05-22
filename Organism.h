#pragma once
#include <string>
#include "Position.h"

class Organism
{
private:
	int power;
	Position position;
	std::string species;

public:
	Organism(int power, Position position);
	Organism() : power(0), position(0, 0), species("O") {};

	int getPower() const; // added const
	void setPower(int power);
	Position getPosition() const;				// added const
	void setPosition(const Position &position); // added const
	std::string getSpecies() const;					// added const
	void setSpecies(const std::string &spec);		// added const

	std::string toString() const; // added const

	virtual ~Organism() {} // virtual destructor, stops memory leaks
	virtual void move(int dx, int dy);
};