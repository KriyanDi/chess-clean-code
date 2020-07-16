#include "Queen.h"

Queen::Queen(Type& type, Color& color, Position& position, Player& owner)
	:Figure(type, color, position, owner)
	, HorizontalMovement(this)
	, VerticalMovement(this)
	, DiagonalMovement(this)
{
}

Queen::~Queen()
{
}

std::vector<Position> Queen::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_horizontal_possible_moves(game, all_possible_moves);
	set_vertical_possible_moves(game, all_possible_moves);
	set_right_diagonal_possible_moves(game, all_possible_moves);
	set_left_diagonal_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}
