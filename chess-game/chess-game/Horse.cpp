#include "Horse.h"
#include "Game.h"

/// This method is Horse default constructor
/// @param type figure type
/// @param color figure color
/// @param position position on the board field
/// @param owner which player owns the figure
Horse::Horse(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
	, ExtendedDiagonalMovement(this)
{
}

Horse::~Horse()
{
}

/// This method gives all possible moves for the Horse on the board field
/// @param game pointer to the game, from where we can get the board field state
/// @return vector of possible possitions on the board field
std::vector<Position> Horse::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_forward_extended_diagonal_possible_moves(game, all_possible_moves);
	set_backwards_extended_diagonal_possible_moves(game, all_possible_moves);
	set_left_extended_diagonal_possible_moves(game, all_possible_moves);
	set_right_extended_diagonal_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}