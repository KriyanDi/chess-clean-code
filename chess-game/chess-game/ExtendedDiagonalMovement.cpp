#include "ExtendedDiagonalMovement.h"

/// This method is ExtendedDiagonalMovement default constructor.
/// Its role is to set pointer to the figure
/// @param figure pointer to the figure we want to give movement
ExtendedDiagonalMovement::ExtendedDiagonalMovement(Figure* figure)
	:AllDirectionsOneStepMovement(figure)
{
}

ExtendedDiagonalMovement::~ExtendedDiagonalMovement()
{
}

void ExtendedDiagonalMovement::set_forward_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position left_extended_diagonal, right_extended_diagonal;
	set_forward_extended_diagonal(left_extended_diagonal, right_extended_diagonal);

	if (left_extended_diagonal.is_valid_position() && has_position_enemy_figure(game, left_extended_diagonal))
	{
		all_possible_moves.push_back(left_extended_diagonal);
	}

	if (right_extended_diagonal.is_valid_position() && has_position_enemy_figure(game, right_extended_diagonal))
	{
		all_possible_moves.push_back(right_extended_diagonal);
	}
}

void ExtendedDiagonalMovement::set_forward_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal)
{
	std::vector<Position> extended_diagonal_moves;
	if (figure->get_color() == Color::BLACK)
	{
		extended_diagonal_moves = get_forward_extended_diagonal_moves_black_figure();
	}
	else if (figure->get_color() == Color::WHITE)
	{
		extended_diagonal_moves = get_forward_extended_diagonal_moves_white_figure();
	}

	int left_diagonal_index = 0, right_diagonal_index = 1;
	left_extended_diagonal = extended_diagonal_moves[left_diagonal_index];
	right_extended_diagonal = extended_diagonal_moves[right_diagonal_index];
}

std::vector<Position> ExtendedDiagonalMovement::get_forward_extended_diagonal_moves_black_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(figure->get_position().get_row() + 2, figure->get_position().get_col() - 1);
	Position extended_left_diagonal(figure->get_position().get_row() + 2, figure->get_position().get_col() + 1);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

std::vector<Position> ExtendedDiagonalMovement::get_forward_extended_diagonal_moves_white_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(figure->get_position().get_row() - 2, figure->get_position().get_col() - 1);
	Position extended_left_diagonal(figure->get_position().get_row() - 2, figure->get_position().get_col() + 1);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

void ExtendedDiagonalMovement::set_backwards_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position left_extended_diagonal, right_extended_diagonal;
	set_backwards_extended_diagonal(left_extended_diagonal, right_extended_diagonal);

	if (left_extended_diagonal.is_valid_position() && has_position_enemy_figure(game, left_extended_diagonal))
	{
		all_possible_moves.push_back(left_extended_diagonal);
	}

	if (right_extended_diagonal.is_valid_position() && has_position_enemy_figure(game, right_extended_diagonal))
	{
		all_possible_moves.push_back(right_extended_diagonal);
	}
}

void ExtendedDiagonalMovement::set_backwards_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal)
{
	std::vector<Position> extended_diagonal_moves;
	if (figure->get_color() == Color::BLACK)
	{
		extended_diagonal_moves = get_backwards_extended_diagonal_moves_black_figure();
	}
	else if (figure->get_color() == Color::WHITE)
	{
		extended_diagonal_moves = get_backwards_extended_diagonal_moves_white_figure();
	}

	int left_diagonal_index = 0, right_diagonal_index = 1;
	left_extended_diagonal = extended_diagonal_moves[left_diagonal_index];
	right_extended_diagonal = extended_diagonal_moves[right_diagonal_index];
}

std::vector<Position> ExtendedDiagonalMovement::get_backwards_extended_diagonal_moves_black_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(figure->get_position().get_row() - 2, figure->get_position().get_col() - 1);
	Position extended_left_diagonal(figure->get_position().get_row() - 2, figure->get_position().get_col() + 1);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

std::vector<Position> ExtendedDiagonalMovement::get_backwards_extended_diagonal_moves_white_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(figure->get_position().get_row() + 2, figure->get_position().get_col() + 1);
	Position extended_left_diagonal(figure->get_position().get_row() + 2, figure->get_position().get_col() - 1);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

void ExtendedDiagonalMovement::set_left_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position left_extended_diagonal, right_extended_diagonal;
	set_left_extended_diagonal(left_extended_diagonal, right_extended_diagonal);

	if (left_extended_diagonal.is_valid_position() && has_position_enemy_figure(game, left_extended_diagonal))
	{
		all_possible_moves.push_back(left_extended_diagonal);
	}

	if (right_extended_diagonal.is_valid_position() && has_position_enemy_figure(game, right_extended_diagonal))
	{
		all_possible_moves.push_back(right_extended_diagonal);
	}
}

void ExtendedDiagonalMovement::set_left_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal)
{
	std::vector<Position> extended_diagonal_moves;
	if (figure->get_color()== Color::BLACK)
	{
		extended_diagonal_moves = get_left_extended_diagonal_moves_black_figure();
	}
	else if (figure->get_color()== Color::WHITE)
	{
		extended_diagonal_moves = get_left_extended_diagonal_moves_white_figure();
	}

	int left_diagonal_index = 0, right_diagonal_index = 1;
	left_extended_diagonal = extended_diagonal_moves[left_diagonal_index];
	right_extended_diagonal = extended_diagonal_moves[right_diagonal_index];
}

std::vector<Position> ExtendedDiagonalMovement::get_left_extended_diagonal_moves_black_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(figure->get_position().get_row() - 1, figure->get_position().get_col() + 2);
	Position extended_left_diagonal(figure->get_position().get_row() + 1, figure->get_position().get_col() + 2);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

std::vector<Position> ExtendedDiagonalMovement::get_left_extended_diagonal_moves_white_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(figure->get_position().get_row() - 1, figure->get_position().get_col() - 2);
	Position extended_left_diagonal(figure->get_position().get_row() + 1, figure->get_position().get_col() - 2);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

void ExtendedDiagonalMovement::set_right_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position left_extended_diagonal, right_extended_diagonal;
	set_right_extended_diagonal(left_extended_diagonal, right_extended_diagonal);

	if (left_extended_diagonal.is_valid_position() && has_position_enemy_figure(game, left_extended_diagonal))
	{
		all_possible_moves.push_back(left_extended_diagonal);
	}

	if (right_extended_diagonal.is_valid_position() && has_position_enemy_figure(game, right_extended_diagonal))
	{
		all_possible_moves.push_back(right_extended_diagonal);
	}
}

void ExtendedDiagonalMovement::set_right_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal)
{
	std::vector<Position> extended_diagonal_moves;
	if (figure->get_color() == Color::BLACK)
	{
		extended_diagonal_moves = get_right_extended_diagonal_moves_black_figure();
	}
	else if (figure->get_color() == Color::WHITE)
	{
		extended_diagonal_moves = get_right_extended_diagonal_moves_white_figure();
	}

	int left_diagonal_index = 0, right_diagonal_index = 1;
	left_extended_diagonal = extended_diagonal_moves[left_diagonal_index];
	right_extended_diagonal = extended_diagonal_moves[right_diagonal_index];
}

std::vector<Position> ExtendedDiagonalMovement::get_right_extended_diagonal_moves_black_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(figure->get_position().get_row() - 1, figure->get_position().get_col() - 2);
	Position extended_left_diagonal(figure->get_position().get_row() + 1, figure->get_position().get_col() - 2);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

std::vector<Position> ExtendedDiagonalMovement::get_right_extended_diagonal_moves_white_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(figure->get_position().get_row() - 1, figure->get_position().get_col() + 2);
	Position extended_left_diagonal(figure->get_position().get_row() + 1, figure->get_position().get_col() + 2);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}
