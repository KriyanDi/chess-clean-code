#include "ForwardMovement.h"

ForwardMovement::ForwardMovement(Figure* figure)
	:AllDirectionsOneStepMovement(figure)
{
}

ForwardMovement::~ForwardMovement()
{
}

void ForwardMovement::set_two_steps_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	if (!figure->has_figure_been_moved())
	{
		Position step_forward;
		set_one_step_forward(step_forward, figure->get_position());

		if (step_forward.is_valid_position() && is_position_empty(game, step_forward))
		{
			set_two_steps_forward(step_forward, figure->get_position());

			if (step_forward.is_valid_position() && is_position_empty(game, step_forward))
			{
				all_possible_moves.push_back(step_forward);
			}
		}
	}
}

void ForwardMovement::set_two_steps_forward(Position& position, Position current)
{
	if (figure->get_color() == Color::BLACK)
	{
		position = get_two_steps_forward_black_figure(current);
	}
	else if (figure->get_color() == Color::WHITE)
	{
		position = get_two_steps_forward_white_figure(current);
	}
}

Position ForwardMovement::get_two_steps_forward_black_figure(Position& position)
{
	Position two_steps_forward(position.get_row() + 2, position.get_col());
	return two_steps_forward;
}

Position ForwardMovement::get_two_steps_forward_white_figure(Position& position)
{
	Position two_steps_forward(position.get_row() - 2, position.get_col());
	return two_steps_forward;
}

void ForwardMovement::set_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position left_diagonal, right_diagonal;
	set_two_diagonal_moves(left_diagonal, right_diagonal);

	if (left_diagonal.is_valid_position() && has_position_enemy_figure(game, left_diagonal))
	{
		all_possible_moves.push_back(left_diagonal);
	}

	if (right_diagonal.is_valid_position() && has_position_enemy_figure(game, right_diagonal))
	{
		all_possible_moves.push_back(right_diagonal);
	}
}

void ForwardMovement::set_two_diagonal_moves(Position& left_diagonal, Position& right_diagonal)
{
	std::vector<Position> diagonal_moves;
	if (figure->get_color() == Color::BLACK)
	{
		diagonal_moves = get_two_diagonal_moves_black_figure();
	}
	else if (figure->get_color() == Color::WHITE)
	{
		diagonal_moves = get_two_diagonal_moves_white_figure();
	}

	int left_diagonal_index = 0, right_diagonal_index = 1;
	left_diagonal = diagonal_moves[left_diagonal_index];
	right_diagonal = diagonal_moves[right_diagonal_index];
}

std::vector<Position> ForwardMovement::get_two_diagonal_moves_black_figure()
{
	std::vector<Position> diagonal_moves;
	Position right_diagonal(figure->get_position().get_row() + 1, figure->get_position().get_col() + 1);
	Position left_diagonal(figure->get_position().get_row() + 1, figure->get_position().get_col() - 1);

	diagonal_moves.push_back(right_diagonal);
	diagonal_moves.push_back(left_diagonal);
	return diagonal_moves;
}

std::vector<Position> ForwardMovement::get_two_diagonal_moves_white_figure()
{
	std::vector<Position> diagonal_moves;
	Position right_diagonal(figure->get_position().get_row() - 1, figure->get_position().get_col() - 1);
	Position left_diagonal(figure->get_position().get_row() - 1, figure->get_position().get_col() + 1);

	diagonal_moves.push_back(right_diagonal);
	diagonal_moves.push_back(left_diagonal);
	return diagonal_moves;
}