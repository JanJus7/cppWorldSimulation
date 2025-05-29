#pragma once

#include <vector>
#include <ctime>
#include "Organism.h"

class World
{
private:
	int worldX;
	int worldY;
	int turn = 0;
	std::vector<Organism *> organisms;
	char separator = '.';

	std::string getOrganismFromPosition(int x, int y) const; // added const
	bool isPositionOnWorld(int x, int y) const;				 // added const
	bool isPositionFree(const Position &position) const;	 // added const
	std::vector<Organism *> getEdibleOrganismsAround(const Organism *predator) const;
	void removeOrganismAt(const Position &pos);

public:
	World(int worldX, int worldY);
	World() : World(6, 6) {};
	~World();

	int getWorldX() const; // added const
	void setWorldX(int worldX);
	int getWorldY() const; // added const
	void setWorldY(int worldY);

	int getTurn() const; // added const

	void addOrganism(Organism *organism);
	std::vector<Position> getVectorOfFreePositionsAround(const Position &position) const; // added const
	void makeTurn();

	void writeWorld(const std::string &fileName) const; // added const
	void readWorld(const std::string &fileName);		// added const

	std::string toString() const; // added const
};
