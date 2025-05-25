#include "World.h"
#include "Plant.h"
#include "Animal.h"
#include "Grass.h"
#include "Sheep.h"
#include <fstream>
#include <algorithm> // Added that for remove_if

using namespace std;

string World::getOrganismFromPosition(int x, int y) const // added const
{
	for (Organism *org : organisms)
		if (org->getPosition().getX() == x && org->getPosition().getY() == y)
			return org->getSpecies();
	return "";
}

bool World::isPositionOnWorld(int x, int y) const // added const
{
	return (x >= 0 && y >= 0 && x < getWorldX() && y < getWorldY());
}

bool World::isPositionFree(const Position &position) const // added const
{
	return this->getOrganismFromPosition(position.getX(), position.getY()).empty();
}

vector<Position> World::getVectorOfFreePositionsAround(const Position &position) const // added const
{
	int pos_x = position.getX(), pos_y = position.getY();
	vector<Position> result;
	for (int x = -1; x < 2; ++x)
		for (int y = -1; y < 2; ++y)
			if ((x != 0 || y != 0) &&
				isPositionOnWorld(pos_x + x, pos_y + y))
			{
				result.push_back(Position(pos_x + x, pos_y + y));
			}
	auto iter = remove_if(result.begin(), result.end(),
						  [this](Position pos)
						  { return !isPositionFree(pos); });
	result.erase(iter, result.end());

	return result;
}

World::World(int worldX, int worldY)
{
	setWorldX(worldX);
	setWorldY(worldY);
}

int World::getWorldX() const // added const
{
	return worldX; // no need of this->
}

void World::setWorldX(int worldX)
{
	this->worldX = worldX;
}

int World::getWorldY() const // added const
{
	return worldY; // no need of this->
}

void World::setWorldY(int worldY)
{
	this->worldY = worldY;
}

int World::getTurn() const // added const
{
	return turn; // no need of this->
}

void World::addOrganism(Organism *organism)
{
	this->organisms.push_back(organism);
}

void World::makeTurn()
{
	vector<Position> newPositions;
	int numberOfNewPositions;
	int randomIndex;

	srand(time(0));
	vector<Organism *> snapshot = organisms;
	for (Organism *org : snapshot)
	{
		newPositions = getVectorOfFreePositionsAround(org->getPosition());
		numberOfNewPositions = newPositions.size();
		org->setPower(org->getPower() + 1);
		if (numberOfNewPositions > 0)
		{
			Position newPos = newPositions[rand() % numberOfNewPositions];
			int dx = newPos.getX() - org->getPosition().getX();
			int dy = newPos.getY() - org->getPosition().getY();
			org->move(dx, dy);
		}

		if (org->getPower() >= org->getPowerToReproduce())
		{
			if (numberOfNewPositions > 0)
			{
				Position newPos = newPositions[rand() % numberOfNewPositions];
				Organism *child = org->Reproduce(newPos);
				addOrganism(child);
				org->setPower(0);
			}
		}
	}
	turn++;
}

void World::writeWorld(const string &fileName) const // added const
{
	fstream my_file;
	my_file.open(fileName, ios::out | ios::binary);
	if (my_file.is_open())
	{
		my_file.write((char *)&this->worldX, sizeof(int));
		my_file.write((char *)&this->worldY, sizeof(int));
		my_file.write((char *)&this->turn, sizeof(int));
		int orgs_size = this->organisms.size();
		my_file.write((char *)&orgs_size, sizeof(int));
		for (int i = 0; i < orgs_size; i++)
		{
			int data;
			data = this->organisms[i]->getPower();
			my_file.write((char *)&data, sizeof(int));
			data = this->organisms[i]->getPosition().getX();
			my_file.write((char *)&data, sizeof(int));
			data = this->organisms[i]->getPosition().getY();
			my_file.write((char *)&data, sizeof(int));
			string s_data = this->organisms[i]->getSpecies();
			int s_size = s_data.size();
			my_file.write((char *)&s_size, sizeof(int));
			my_file.write(s_data.data(), s_data.size());
		}
		my_file.close();
	}
}

void World::readWorld(const string &fileName) // added const
{
	fstream my_file;
	my_file.open(fileName, ios::in | ios::binary);
	if (my_file.is_open())
	{
		int result;
		my_file.read((char *)&result, sizeof(int));
		this->worldX = result;
		my_file.read((char *)&result, sizeof(int));
		this->worldY = result;
		my_file.read((char *)&result, sizeof(int));
		this->turn = result;
		my_file.read((char *)&result, sizeof(int));
		int orgs_size = result;

		for (Organism *org : organisms)
			delete org;
		organisms.clear();

		for (int i = 0; i < orgs_size; i++)
		{
			int power, pos_x, pos_y, s_size;
			my_file.read((char *)&power, sizeof(int));
			my_file.read((char *)&pos_x, sizeof(int));
			my_file.read((char *)&pos_y, sizeof(int));
			my_file.read((char *)&s_size, sizeof(int));

			string species;
			species.resize(s_size);
			my_file.read(&species[0], s_size);

			Position pos{pos_x, pos_y};
			Organism *org = nullptr;

			if (species == "P")
				org = new Plant(power, pos);
			else if (species == "A")
				org = new Animal(power, pos);
			else if (species == "S")
				org = new Sheep(pos); // Sheep ma stałe atrybuty
			else if (species == "G")
				org = new Grass(pos);
			else
				continue;

			if (org)
				organisms.push_back(org);
		}
		my_file.close();
	}
}

string World::toString() const // added const
{
	string result = "\nturn: " + to_string(getTurn()) + "\n";
	string spec;

	for (int wY = 0; wY < getWorldY(); ++wY)
	{
		for (int wX = 0; wX < getWorldX(); ++wX)
		{
			spec = getOrganismFromPosition(wX, wY);
			if (spec != "")
				result += spec;
			else
				result += separator;
		};
		result += "\n";
	}
	return result;
}

World::~World()
{
	for (Organism *org : organisms)
	{
		delete org;
	}
}
