#include "VerticalMovement.h"

VerticalMovement::VerticalMovement(Figure* figure)
	:AllDirectionsOneStepMovement(figure)
{
}

VerticalMovement::~VerticalMovement()
{
}

void VerticalMovement::set_vertical_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	set_forward_possible_moves(game, all_possible_moves);
	set_backwards_possible_moves(game, all_possible_moves);
}

void VerticalMovement::set_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_forward;
	set_one_step_forward(step_forward, figure->get_position());

	while (step_forward.is_valid_position() && is_position_empty(game, step_forward))
	{
		all_possible_moves.push_back(step_forward);

		set_one_step_forward(step_forward, step_forward);
	}

	if (step_forward.is_valid_position() && has_position_enemy_figure(game, step_forward))
	{
		all_possible_moves.push_back(step_forward);
	}
}

void VerticalMovement::set_backwards_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_backwards;
	set_one_step_backwards(step_backwards, figure->get_position());

	while (step_backwards.is_valid_position() && is_position_empty(game, step_backwards))
	{
		all_possible_moves.push_back(step_backwards);

		set_one_step_backwards(step_backwards, step_backwards);
	}

	if (step_backwards.is_valid_position() && has_position_enemy_figure(game, step_backwards))
	{
		all_possible_moves.push_back(step_backwards);
	}
}