#pragma once
#include "HorizontalMovement.h"
#include "VerticalMovement.h"
#include "DiagonalMovement.h"

/// This is Queen piece
///
/// This class is about Queen piece as piece and can give Queen possible moves on the board field
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