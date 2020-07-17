#include "Pawn.h"
#include "Game.h"
#include <vector>

/// This method is Pawn default constructor
/// @param type figure type
/// @param color figure color
/// @param position position on the board field
/// @param owner which player owns the figure
Pawn::Pawn(Type& type, Color& color, Position& position, Player& owner)
	:Figure(type, color, position, owner)
	, ForwardMovement(this)
{
}

Pawn::~Pawn()
{
}

/// This method gives all possible moves for the Pawn on the board field
/// @param game pointer to the game, from where we can get the board field state
/// @return vector of possible possitions on the board field
std::vector<Position> Pawn::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_one_step_forward_possible_moves(game, all_possible_moves);
	set_two_steps_forward_possible_moves(game, all_possible_moves);
	set_diagonal_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}
