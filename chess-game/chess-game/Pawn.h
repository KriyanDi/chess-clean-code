#pragma once

#include "Figure.h"

class Pawn : virtual public Figure
{
public:
	Pawn(Type type, Color color, Position position, Player owner);
	Pawn(const Pawn &other) = delete;
	Pawn& operator=(const Pawn& other) = delete;
	virtual ~Pawn();
};