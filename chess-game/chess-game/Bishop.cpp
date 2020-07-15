#include "Bishop.h"
#include "Game.h"

Bishop::Bishop(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
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

void Bishop::set_right_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	set_right_top_diagonal_possible_moves(game, all_possible_moves);
	set_right_bottom_diagonal_possible_moves(game, all_possible_moves);
}

void Bishop::set_left_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	set_left_top_diagonal_possible_moves(game, all_possible_moves);
	set_left_bottom_diagonal_possible_moves(game, all_possible_moves);
}

void Bishop::set_right_top_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_right_top_diagonal;
	set_step_right_top_diagonal(step_right_top_diagonal, get_position());

	while (step_right_top_diagonal.is_valid_position() && is_position_empty(game, step_right_top_diagonal))
	{
		all_possible_moves.push_back(step_right_top_diagonal);

		set_step_right_top_diagonal(step_right_top_diagonal, step_right_top_diagonal);
	}

	if (step_right_top_diagonal.is_valid_position() && has_position_enemy_figure(game, step_right_top_diagonal))
	{
		all_possible_moves.push_back(step_right_top_diagonal);
	}
}

void Bishop::set_step_right_top_diagonal(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_step_right_top_diagonal_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_step_right_top_diagonal_white_figure(current);
	}
}

Position Bishop::get_step_right_top_diagonal_black_figure(Position position)
{
	Position step_right_top_diagonal(position.get_row() + 1, position.get_col() - 1);
	return step_right_top_diagonal;
}

Position Bishop::get_step_right_top_diagonal_white_figure(Position position)
{
	Position step_right_top_diagonal(position.get_row() - 1, position.get_col() + 1);
	return step_right_top_diagonal;
}

void Bishop::set_right_bottom_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_right_bottom_diagonal;
	set_step_right_bottom_diagonal(step_right_bottom_diagonal, get_position());

	while (step_right_bottom_diagonal.is_valid_position() && is_position_empty(game, step_right_bottom_diagonal))
	{
		all_possible_moves.push_back(step_right_bottom_diagonal);

		set_step_right_top_diagonal(step_right_bottom_diagonal, step_right_bottom_diagonal);
	}

	if (step_right_bottom_diagonal.is_valid_position() && has_position_enemy_figure(game, step_right_bottom_diagonal))
	{
		all_possible_moves.push_back(step_right_bottom_diagonal);
	}
}

void Bishop::set_step_right_bottom_diagonal(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_step_right_bottom_diagonal_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_step_right_bottom_diagonal_white_figure(current);
	}
}

Position Bishop::get_step_right_bottom_diagonal_black_figure(Position position)
{
	Position step_right_bottom_diagonal(position.get_row() - 1, position.get_col() + 1);
	return step_right_bottom_diagonal;
}

Position Bishop::get_step_right_bottom_diagonal_white_figure(Position position)
{
	Position step_right_bottom_diagonal(position.get_row() + 1, position.get_col() - 1);
	return step_right_bottom_diagonal;
}

void Bishop::set_left_top_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_left_top_diagonal;
	set_step_left_top_diagonal(step_left_top_diagonal, get_position());

	while (step_left_top_diagonal.is_valid_position() && is_position_empty(game, step_left_top_diagonal))
	{
		all_possible_moves.push_back(step_left_top_diagonal);

		set_step_left_top_diagonal(step_left_top_diagonal, step_left_top_diagonal);
	}

	if (step_left_top_diagonal.is_valid_position() && has_position_enemy_figure(game, step_left_top_diagonal))
	{
		all_possible_moves.push_back(step_left_top_diagonal);
	}
}

void Bishop::set_step_left_top_diagonal(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_step_left_top_diagonal_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_step_left_top_diagonal_white_figure(current);
	}
}

Position Bishop::get_step_left_top_diagonal_black_figure(Position position)
{
	Position step_left_top_diagonal(position.get_row() - 1, position.get_col() - 1);
	return step_left_top_diagonal;
}

Position Bishop::get_step_left_top_diagonal_white_figure(Position position)
{
	Position step_left_top_diagonal(position.get_row() - 1, position.get_col() + 1);
	return step_left_top_diagonal;
}

void Bishop::set_left_bottom_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_left_bottom_diagonal;
	set_step_left_bottom_diagonal(step_left_bottom_diagonal, get_position());

	while (step_left_bottom_diagonal.is_valid_position() && is_position_empty(game, step_left_bottom_diagonal))
	{
		all_possible_moves.push_back(step_left_bottom_diagonal);

		set_step_left_bottom_diagonal(step_left_bottom_diagonal, step_left_bottom_diagonal);
	}

	if (step_left_bottom_diagonal.is_valid_position() && has_position_enemy_figure(game, step_left_bottom_diagonal))
	{
		all_possible_moves.push_back(step_left_bottom_diagonal);
	}
}

void Bishop::set_step_left_bottom_diagonal(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_step_left_bottom_diagonal_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_step_left_bottom_diagonal_white_figure(current);
	}
}

Position Bishop::get_step_left_bottom_diagonal_black_figure(Position position)
{
	Position step_left_bottom_diagonal(position.get_row() + 1, position.get_col() + 1);
	return step_left_bottom_diagonal;
}

Position Bishop::get_step_left_bottom_diagonal_white_figure(Position position)
{
	Position step_left_bottom_diagonal(position.get_row() + 1, position.get_col() - 1);
	return step_left_bottom_diagonal;
}

bool Bishop::is_position_empty(Game* game, Position& position)
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

bool Bishop::has_position_enemy_figure(Game* game, Position& position)
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