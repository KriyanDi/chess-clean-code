#pragma once

#include "Figure.h"

class Rook : virtual public Figure
{
public:
	Rook(Type& type, Color& color, Position& position, Player& owner);
	Rook(const Rook& other) = delete;
	Rook& operator=(const Rook& other) = delete;
	virtual ~Rook();

public:
	std::vector<Position> get_all_possible_moves(Game* game);

private:

};