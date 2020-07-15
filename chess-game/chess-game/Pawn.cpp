#include "Pawn.h"
#include "Game.h"

#include <vector>

Pawn::Pawn(Type& type, Color& color, Position& position, Player& owner)
	:Figure(type, color, position, owner)
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

void Pawn::set_one_step_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_forward;
	set_one_step_forward(step_forward);

	if (step_forward.is_valid_position() && is_position_empty(game, step_forward))
	{
		all_possible_moves.push_back(step_forward);
	}
}

void Pawn::set_one_step_forward(Position& position)
{
	if (this->color == Color::BLACK)
	{
		position = get_one_step_forward_black_figure();
	}
	else if (this->color == Color::WHITE)
	{
		position = get_one_step_forward_white_figure();
	}
}

Position Pawn::get_one_step_forward_black_figure()
{
	Position one_step_forward(this->position.get_row() + 1, this->position.get_col());
	return one_step_forward;
}

Position Pawn::get_one_step_forward_white_figure()
{
	Position one_step_forward(this->position.get_row() - 1, this->position.get_col());
	return one_step_forward;
}

void Pawn::set_two_steps_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	if (!has_figure_been_moved())
	{
		Position step_forward;
		set_one_step_forward(step_forward);

		if (step_forward.is_valid_position() && is_position_empty(game, step_forward))
		{
			set_two_steps_forward(step_forward);

			if (step_forward.is_valid_position() && is_position_empty(game, step_forward))
			{
				all_possible_moves.push_back(step_forward);
			}
		}
	}
}

void Pawn::set_two_steps_forward(Position& position)
{
	if (this->color == Color::BLACK)
	{
		position = get_two_steps_forward_black_figure();
	}
	else if (this->color == Color::WHITE)
	{
		position = get_two_steps_forward_white_figure();
	}
}

Position Pawn::get_two_steps_forward_black_figure()
{
	Position two_steps_forward(this->position.get_row() + 2, this->position.get_col());
	return two_steps_forward;
}

Position Pawn::get_two_steps_forward_white_figure()
{
	Position two_steps_forward(this->position.get_row() - 2, this->position.get_col());
	return two_steps_forward;
}

void Pawn::set_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
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

void Pawn::set_two_diagonal_moves(Position& left_diagonal, Position& right_diagonal)
{
	std::vector<Position> diagonal_moves;
	if (this->color == Color::BLACK)
	{
		diagonal_moves = get_two_diagonal_moves_black_figure();
	}
	else if (this->color == Color::WHITE)
	{
		diagonal_moves = get_two_diagonal_moves_white_figure();
	}

	int left_diagonal_index = 0, right_diagonal_index = 1;
	left_diagonal = diagonal_moves[left_diagonal_index];
	right_diagonal = diagonal_moves[right_diagonal_index];
}

std::vector<Position> Pawn::get_two_diagonal_moves_black_figure()
{
	std::vector<Position> diagonal_moves;
	Position right_diagonal(this->position.get_row() + 1, this->position.get_col() + 1);
	Position left_diagonal(this->position.get_row() + 1, this->position.get_col() - 1);

	diagonal_moves.push_back(right_diagonal);
	diagonal_moves.push_back(left_diagonal);
	return diagonal_moves;
}

std::vector<Position> Pawn::get_two_diagonal_moves_white_figure()
{
	std::vector<Position> diagonal_moves;
	Position right_diagonal(this->position.get_row() - 1, this->position.get_col() - 1);
	Position left_diagonal(this->position.get_row() - 1, this->position.get_col() + 1);

	diagonal_moves.push_back(right_diagonal);
	diagonal_moves.push_back(left_diagonal);
	return diagonal_moves;
}

bool Pawn::is_position_empty(Game* game, Position& position)
{
	if (game->get_board_field()->is_empty(position))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Pawn::has_position_enemy_figure(Game* game, Position& position)
{
	if (game->get_board_field()->get_figure(position)->get_color() != this->get_color())
	{
		return true;
	}
	else
	{
		return false;
	}
}
