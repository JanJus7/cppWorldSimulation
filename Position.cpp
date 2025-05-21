#include "Position.h"
#include <cmath> // added because of "sqrt is undefined message"

Position::Position(int x, int y)
	: x(x), y(y) {} // Refactored constructor with parameters

int Position::getX() const // added const
{
	return x; // no need of this->
}

void Position::setX(int x)
{
	if (x >= 0)
		this->x = x;
	else
		this->x = 0;
}

int Position::getY() const // added const
{
	return y; // no need of this->
}

void Position::setY(int y)
{
	if (y >= 0)
		this->y = y;
	else
		this->y = 0;
}

string Position::toString() const // added const
{
	return "(" + to_string(getX()) + ", " + to_string(getY()) + ")";
}

double Position::distance(const Position &position)
{
	double dx = (double)getX() - (double)position.getX();
	double dy = (double)getY() - (double)position.getY();
	return sqrt((dx * dx) + (dy * dy));
}

void Position::move(int dx, int dy)
{
	setX(getX() + dx);
	setY(getY() + dy);
}