#pragma once
#include "ExtendedDiagonalMovement.h"

/// This is Horse piece
///
/// This class is about Horse piece as piece and can give Horse possible moves on the board field
class Horse 
	: virtual public Figure
	, public ExtendedDiagonalMovement
{
public:
	Horse(Type& type, Color& color, Position& position, Player& owner);
	Horse(const Horse& other) = delete;
	Horse& operator=(const Horse& other) = delete;
	virtual ~Horse();

public:
	std::vector<Position> get_all_possible_moves(Game* game) override;
};
