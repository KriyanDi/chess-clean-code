#pragma once
#include "HorizontalMovement.h"
#include "VerticalMovement.h"

/// This is Rook piece
///
/// This class is about Rook piece as piece and can give Rook possible moves on the board field
class Rook 
	: virtual public Figure
	, public HorizontalMovement
	, public VerticalMovement
{
public:
	Rook(Type& type, Color& color, Position& position, Player& owner);
	Rook(const Rook& other) = delete;
	Rook& operator=(const Rook& other) = delete;
	virtual ~Rook();

public:
	std::vector<Position> get_all_possible_moves(Game* game) override;
};