#include "King.h"
#include "Game.h"

King::King(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
	, AllDirectionsOneStepMovement(this)
{
}

King::~King()
{
}

std::vector<Position> King::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_one_step_all_directions_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}