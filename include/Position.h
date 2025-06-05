#pragma once
#include <string>

class Position
{
private:
	int x;
	int y;

public:
	Position(int x, int y);
	Position() : x(0), y(0) {}

	int getX() const; // added const
	void setX(int x);
	int getY() const; // added const
	void setY(int y);

	std::string toString() const; // added const

	double distance(const Position &position); // added const
	void move(int dx, int dy);
};