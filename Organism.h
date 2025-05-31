#pragma once
#include <string>
#include <vector>
#include "Position.h"

class Organism
{
private:
	std::string species;
	int initiative;
	int liveLength;
	int powerToReproduce;
	std::vector<std::pair<int, int>> ancestors; // Ancestrors vector

protected:
	Position position;
	int power;
	bool markedForRemoval = false;

public:
	Organism(int power, Position position);
	Organism() : power(0), position(0, 0), species("O") {};

	// History copy and move constructors
	Organism(const Organism &other);
	Organism(Organism &&other) noexcept;

	Organism &operator=(const Organism &other);
	Organism &operator=(Organism &&other) noexcept;

	void addAncestor(int birthTurn, int deathTurn);
	const std::vector<std::pair<int, int>> &getAncestors() const;
	void printAncestors() const;

	int getPower() const; // added const
	void setPower(int power);
	Position getPosition() const;				// added const
	void setPosition(const Position &position); // added const
	std::string getSpecies() const;				// added const
	void setSpecies(const std::string &spec);	// added const

	int getInitiative() const;
	void setInitiative(int initiative);
	int getLiveLength() const;
	void setLiveLength(int length);
	int getPowerToReproduce() const;
	void setPowerToReproduce(int power);
	void markForRemoval() { markedForRemoval = true; }
	bool isMarkedForRemoval() const { return markedForRemoval; }

	std::string toString() const; // added const

	virtual ~Organism(); // virtual destructor, stops memory leaks
	virtual void move(int dx, int dy);
	virtual Organism *Reproduce(const Position &newPos) const = 0;
	virtual void serialize(std::ostream &out) const = 0;
	virtual void deserialize(std::istream &in) = 0;
};