#pragma once

#include "Figure.h"

class Queen : virtual public Figure
{
	Queen(Type type, Color color, Position position, Player owner);
	Queen(const Queen& other) = delete;
	Queen& operator=(const Queen& other) = delete;
	virtual ~Queen();
};