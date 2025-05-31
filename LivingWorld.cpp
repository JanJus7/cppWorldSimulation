#include <iostream>
#include "Position.h"
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
#include "Grass.h"
#include "Sheep.h"
#include "Milkweed.h"
#include "Wolf.h"

using namespace std;

int main()
{
	// Position
	Position p1;
	Position p2{1, 1};
	Position p3{-3, -5};

	// cout << p1.toString() << endl;
	// cout << p2.toString() << endl;
	// cout << p3.toString() << endl;
	// cout << p1.distance(p2) << endl;
	// p2.move(4, 6);
	// cout << p2.toString() << endl;

	// Organism
	// Organism org1;
	// Organism org2{ 10, p2 };

	// cout << org1.toString() << endl;
	// cout << org2.toString() << endl;
	// org1.move(2, 3);
	// cout << org1.toString() << endl;

	// Plant & Animal
	// Plant plant{3, p3};
	// Animal animal{5, p2};
	// Plant plant2;
	// Animal animal2;

	// cout << plant.toString() << endl;
	// cout << animal.toString() << endl;
	// cout << plant2.toString() << endl;
	// cout << animal2.toString() << endl;
	// plant.move(3, 4);
	// cout << plant.toString() << endl;
	// animal.move(1, 2);
	// cout << animal.toString() << endl;

	// World test
	World world(30, 10);
	// Position posP1{4, 5};
	// Position posP2{5, 4};
	// Position posW2{3, 2};
	// Position posW3{2, 3};

	world.addOrganism(new Grass(Position(2, 2)));
	world.addOrganism(new Grass(Position(10, 5)));
	world.addOrganism(new Grass(Position(20, 3)));
	world.addOrganism(new Grass(Position(25, 8)));

	world.addOrganism(new Milkweed(Position(15, 5)));

	world.addOrganism(new Sheep(Position(5, 2)));
	world.addOrganism(new Sheep(Position(12, 4)));
	world.addOrganism(new Sheep(Position(18, 6)));

	world.addOrganism(new Wolf(Position(7, 7)));
	world.addOrganism(new Wolf(Position(25, 10)));

	cout << endl;
	cout << "Ancestors test:" << endl;
	Organism *parent = new Animal(5, Position(1, 1));
	parent->addAncestor(0, 10);

	Organism *child = new Animal(3, Position(2, 2));
	*child = *parent;
	child->addAncestor(0, 10);

	cout << "PARENT:\n";
	cout << parent->toString() << endl;
	parent->printAncestors();

	cout << "CHILD:\n";
	cout << child->toString() << endl;
	child->printAncestors();

	auto positions = world.getVectorOfFreePositionsAround(Position(5, 5));

	for (auto pos : positions)
		cout << pos.toString() << endl;

	world.writeWorld("world.bin");

	for (int i = 0; i < 75; i++)
	{
		world.makeTurn();
		cout << world.toString() << endl;
	}
	

	// powrot do Tury 2
	// world.readWorld("world.bin");
	// cout << world.toString() << endl;

	return 0;
}