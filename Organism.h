#pragma once
#include <string>
#include "Position.h"

using namespace std;

class Organism
{
private:
	int power;
	Position position;
	string species;

public:
	Organism(int power, Position position);
	Organism() : power(0), position(0, 0), species("O") {};

	int getPower() const; // added const
	void setPower(int power);
	Position getPosition() const;				// added const
	void setPosition(const Position &position); // added const
	string getSpecies() const;					// added const
	void setSpecies(const string &spec);		// added const

	string toString() const; // added const

	virtual ~Organism() {} // virtual destructor, stops memory leaks
	virtual void move(int dx, int dy);
};