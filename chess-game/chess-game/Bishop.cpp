#include "Bishop.h"
#include "Game.h"

Bishop::Bishop(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
	, DiagonalMovement(this)
{
}

Bishop::~Bishop()
{
}

std::vector<Position> Bishop::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_right_diagonal_possible_moves(game, all_possible_moves);
	set_left_diagonal_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}