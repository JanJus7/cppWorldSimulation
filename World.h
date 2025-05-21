#pragma once

#include <vector>
#include <ctime>
#include "Organism.h"

using namespace std;

class World
{
private:
	int worldX;
	int worldY;
	int turn = 0;
	vector<Organism> organisms;
	char separator = '.';

	string getOrganismFromPosition(int x, int y) const;	 // added const
	bool isPositionOnWorld(int x, int y) const;			 // added const
	bool isPositionFree(const Position &position) const; // added const

public:
	World(int worldX, int worldY);
	World() : World(6, 6) {};

	int getWorldX() const; // added const
	void setWorldX(int worldX);
	int getWorldY() const; // added const
	void setWorldY(int worldY);

	int getTurn() const; // added const

	void addOrganism(Organism *organism);
	vector<Position> getVectorOfFreePositionsAround(const Position &position) const; // added const
	void makeTurn();

	void writeWorld(const string &fileName) const; // added const
	void readWorld(const string &fileName);		   // added const

	string toString() const; // added const
};
