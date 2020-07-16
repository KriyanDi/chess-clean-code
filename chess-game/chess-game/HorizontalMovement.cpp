#include "HorizontalMovement.h"

HorizontalMovement::HorizontalMovement(Figure* figure)
	: AllDirectionsOneStepMovement(figure)
{
}

HorizontalMovement::~HorizontalMovement()
{
}

void HorizontalMovement::set_horizontal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	set_left_possible_moves(game, all_possible_moves);
	set_right_possible_moves(game, all_possible_moves);
}

void HorizontalMovement::set_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_left;
	set_one_step_left(step_left, figure->get_position());

	while (step_left.is_valid_position() && is_position_empty(game, step_left))
	{
		all_possible_moves.push_back(step_left);

		set_one_step_left(step_left, step_left);
	}

	if (step_left.is_valid_position() && has_position_enemy_figure(game, step_left))
	{
		all_possible_moves.push_back(step_left);
	}
}

void HorizontalMovement::set_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_right;
	set_one_step_right(step_right, figure->get_position());

	while (step_right.is_valid_position() && is_position_empty(game, step_right))
	{
		all_possible_moves.push_back(step_right);

		set_one_step_right(step_right, step_right);
	}

	if (step_right.is_valid_position() && has_position_enemy_figure(game, step_right))
	{
		all_possible_moves.push_back(step_right);
	}
}
