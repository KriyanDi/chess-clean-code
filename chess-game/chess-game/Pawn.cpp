#include "Pawn.h"
#include "Game.h"

#include <vector>

Pawn::Pawn(Type& type, Color& color, Position& position, Player& owner)
	:Figure(type, color, position, owner)
	, ForwardMovement(this)
{
}

Pawn::~Pawn()
{
}

std::vector<Position> Pawn::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_one_step_forward_possible_moves(game, all_possible_moves);
	set_two_steps_forward_possible_moves(game, all_possible_moves);
	set_diagonal_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}
