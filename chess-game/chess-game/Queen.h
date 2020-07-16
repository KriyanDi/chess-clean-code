#pragma once

#include "Figure.h"
#include "Rook.h"
#include "Bishop.h"

class Queen : virtual public Figure, public Rook, public Bishop
{
public:
	Queen(Type& type, Color& color, Position& position, Player& owner);
	Queen(const Queen& other) = delete;
	Queen& operator=(const Queen& other) = delete;
	virtual ~Queen();

public:
	std::vector<Position> get_all_possible_moves(Game* game) override;
};