#include <iostream>
#include "Position.h"
#include "Organism.h"
#include "Plant.h"
#include "Animal.h"
#include "World.h"
#include "Grass.h"
#include "Sheep.h"

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
	World world;
	Position posP1{4, 5};
	Position posP2{5, 4};
	Position posW2{3, 2};
	Position posW3{2, 3};

	world.addOrganism(new Grass(posP1));
	world.addOrganism(new Sheep(posW2));
	world.addOrganism(new Grass(posP2));
	world.addOrganism(new Sheep(posW3));

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

	// Tura 0
	cout << world.toString() << endl;

	// Tura 1
	world.makeTurn();
	cout << world.toString() << endl;

	// Tura 2
	world.makeTurn();
	cout << world.toString() << endl;

	world.writeWorld("world.bin");

	// Tura 3
	world.makeTurn();
	cout << world.toString() << endl;

	// Tura 4
	world.makeTurn();
	cout << world.toString() << endl;

	// Tura 5
	world.makeTurn();
	cout << world.toString() << endl;

	// Tura 6
	world.makeTurn();
	cout << world.toString() << endl;

	// Tura 7
	world.makeTurn();
	cout << world.toString() << endl;

	// Tura 8
	world.makeTurn();
	cout << world.toString() << endl;

	// powrot do Tury 2
	// world.readWorld("world.bin");
	// cout << world.toString() << endl;

	return 0;
}