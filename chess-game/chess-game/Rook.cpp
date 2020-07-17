#include "Rook.h"
#include "Game.h"

/// This method is Rook default constructor
/// @param type figure type
/// @param color figure color
/// @param position position on the board field
/// @param owner which player owns the figure
Rook::Rook(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
	, HorizontalMovement(this)
	, VerticalMovement(this)
{
}

Rook::~Rook()
{
}

/// This method gives all possible moves for the Rook on the board field
/// @param game pointer to the game, from where we can get the board field state
/// @return vector of possible possitions on the board field
std::vector<Position> Rook::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_horizontal_possible_moves(game, all_possible_moves);
	set_vertical_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}
