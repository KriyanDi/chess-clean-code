#include "Queen.h"

/// This method is Queen default constructor
/// @param type figure type
/// @param color figure color
/// @param position position on the board field
/// @param owner which player owns the figure
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

/// This method gives all possible moves for the Queen on the board field
/// @param game pointer to the game, from where we can get the board field state
/// @return vector of possible possitions on the board field
std::vector<Position> Queen::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_horizontal_possible_moves(game, all_possible_moves);
	set_vertical_possible_moves(game, all_possible_moves);
	set_right_diagonal_possible_moves(game, all_possible_moves);
	set_left_diagonal_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}
