#include "King.h"
#include "Game.h"

/// This method is King default constructor
/// @param type figure type
/// @param color figure color
/// @param position position on the board field
/// @param owner which player owns the figure
King::King(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
	, AllDirectionsOneStepMovement(this)
{
}

King::~King()
{
}

/// This method gives all possible moves for the King on the board field
/// @param game pointer to the game, from where we can get the board field state
/// @return vector of possible possitions on the board field
std::vector<Position> King::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_one_step_all_directions_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}