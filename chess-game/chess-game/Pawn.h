#pragma once
#include "ForwardMovement.h"

/// This is Pawn piece
///
/// This class is about Pawn piece as piece and can give Pawn possible moves on the board field
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