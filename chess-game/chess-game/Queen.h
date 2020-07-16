#pragma once

#include "HorizontalMovement.h"
#include "VerticalMovement.h"
#include "DiagonalMovement.h"

class Queen 
	: virtual public Figure
	, public HorizontalMovement
	, public VerticalMovement
	, public DiagonalMovement
{
public:
	Queen(Type& type, Color& color, Position& position, Player& owner);
	Queen(const Queen& other) = delete;
	Queen& operator=(const Queen& other) = delete;
	virtual ~Queen();

public:
	std::vector<Position> get_all_possible_moves(Game* game) override;
};