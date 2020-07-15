#include "Rook.h"

Rook::Rook(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
{
}

Rook::~Rook()
{
}

std::vector<Position> Rook::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_forward_possible_moves(game, all_possible_moves);
	set_backwards_possible_moves(game, all_possible_moves);
	set_left_possible_moves(game, all_possible_moves);
	set_right_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}
