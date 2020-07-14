#pragma once

#include "Figure.h"

class Rook : virtual public Figure
{
	Rook(Type type, Color color, Position position, Player owner);
	Rook(const Rook& other) = delete;
	Rook& operator=(const Rook& other) = delete;
	virtual ~Rook();
};