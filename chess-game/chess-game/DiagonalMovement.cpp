#include "DiagonalMovement.h"

DiagonalMovement::DiagonalMovement(Figure* figure)
	:AllDirectionsOneStepMovement(figure)
{
}

DiagonalMovement::~DiagonalMovement()
{
}

void DiagonalMovement::set_left_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	set_left_top_diagonal_possible_moves(game, all_possible_moves);
	set_left_bottom_diagonal_possible_moves(game, all_possible_moves);
}

void DiagonalMovement::set_right_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	set_right_top_diagonal_possible_moves(game, all_possible_moves);
	set_right_bottom_diagonal_possible_moves(game, all_possible_moves);
}

void DiagonalMovement::set_left_top_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_left_top_diagonal;
	set_one_step_forward_left(step_left_top_diagonal, figure->get_position());

	while (step_left_top_diagonal.is_valid_position() && is_position_empty(game, step_left_top_diagonal))
	{
		all_possible_moves.push_back(step_left_top_diagonal);

		set_one_step_forward_left(step_left_top_diagonal, step_left_top_diagonal);
	}

	if (step_left_top_diagonal.is_valid_position() && has_position_enemy_figure(game, step_left_top_diagonal))
	{
		all_possible_moves.push_back(step_left_top_diagonal);
	}
}

void DiagonalMovement::set_left_bottom_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_left_bottom_diagonal;
	set_one_step_backwards_left(step_left_bottom_diagonal, figure->get_position());

	while (step_left_bottom_diagonal.is_valid_position() && is_position_empty(game, step_left_bottom_diagonal))
	{
		all_possible_moves.push_back(step_left_bottom_diagonal);

		set_one_step_backwards_left(step_left_bottom_diagonal, step_left_bottom_diagonal);
	}

	if (step_left_bottom_diagonal.is_valid_position() && has_position_enemy_figure(game, step_left_bottom_diagonal))
	{
		all_possible_moves.push_back(step_left_bottom_diagonal);
	}
}

void DiagonalMovement::set_right_top_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_right_top_diagonal;
	set_one_step_forward_right(step_right_top_diagonal, figure->get_position());

	while (step_right_top_diagonal.is_valid_position() && is_position_empty(game, step_right_top_diagonal))
	{
		all_possible_moves.push_back(step_right_top_diagonal);

		set_one_step_forward_right(step_right_top_diagonal, step_right_top_diagonal);
	}

	if (step_right_top_diagonal.is_valid_position() && has_position_enemy_figure(game, step_right_top_diagonal))
	{
		all_possible_moves.push_back(step_right_top_diagonal);
	}
}

void DiagonalMovement::set_right_bottom_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_right_bottom_diagonal;
	set_one_step_backwards_right(step_right_bottom_diagonal, figure->get_position());

	while (step_right_bottom_diagonal.is_valid_position() && is_position_empty(game, step_right_bottom_diagonal))
	{
		all_possible_moves.push_back(step_right_bottom_diagonal);

		set_one_step_backwards_right(step_right_bottom_diagonal, step_right_bottom_diagonal);
	}

	if (step_right_bottom_diagonal.is_valid_position() && has_position_enemy_figure(game, step_right_bottom_diagonal))
	{
		all_possible_moves.push_back(step_right_bottom_diagonal);
	}
}