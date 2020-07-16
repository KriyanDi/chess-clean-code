#pragma once

#include "ForwardMovement.h"

class Pawn
	: virtual public Figure
	, public ForwardMovement
{
public:
	Pawn(Type& type, Color& color, Position& position, Player& owner);
	Pawn(const Pawn &other) = delete;
	Pawn& operator=(const Pawn& other) = delete;
	virtual ~Pawn();

public:
	std::vector<Position> get_all_possible_moves(Game* game) override;
};	