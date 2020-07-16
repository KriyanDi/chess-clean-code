#include "Rook.h"
#include "Game.h"

Rook::Rook(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
	, HorizontalMovement(this)
{
}

Rook::~Rook()
{
}

std::vector<Position> Rook::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_horizontal_possible_moves(game, all_possible_moves);
	set_vertical_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}
