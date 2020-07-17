#pragma once
#include "DiagonalMovement.h"

/// This is Bishop piece
///
/// This class is about Bishop piece as piece and can give Bishop possible moves on the board field
class Bishop
	: virtual public Figure
	, public DiagonalMovement
{
public:
	Bishop(Type& type, Color& color, Position& position, Player& owner);
	Bishop(const Bishop& other) = delete;
	Bishop& operator=(const Bishop& other) = delete;
	virtual ~Bishop();

public:
	std::vector<Position> get_all_possible_moves(Game* game) override;
};
