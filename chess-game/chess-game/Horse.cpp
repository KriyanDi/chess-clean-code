#include "Horse.h"
#include "Game.h"

Horse::Horse(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
	, ExtendedDiagonalMovement(this)
{
}

Horse::~Horse()
{
}

std::vector<Position> Horse::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_forward_extended_diagonal_possible_moves(game, all_possible_moves);
	set_backwards_extended_diagonal_possible_moves(game, all_possible_moves);
	set_left_extended_diagonal_possible_moves(game, all_possible_moves);
	set_right_extended_diagonal_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}