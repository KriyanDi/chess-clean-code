#include "Rook.h"
#include "Game.h"

Rook::Rook(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
{
}

Rook::~Rook()
{
}

std::vector<Position> Rook::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_forward_possible_moves(game, all_possible_moves);
	set_backwards_possible_moves(game, all_possible_moves);
	set_left_possible_moves(game, all_possible_moves);
	set_right_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}

void Rook::set_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_forward;
	set_step_forward(step_forward, get_position());

	while (step_forward.is_valid_position() && is_position_empty(game, step_forward))
	{
		all_possible_moves.push_back(step_forward);

		set_step_forward(step_forward, step_forward);
	}

	if (step_forward.is_valid_position() && has_position_enemy_figure(game, step_forward))
	{
		all_possible_moves.push_back(step_forward);
	}
}

void Rook::set_step_forward(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_step_forward_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_step_forward_white_figure(current);
	}
}

Position Rook::get_step_forward_black_figure(Position position)
{
	Position step_forward(position.get_row() + 1, position.get_col());
	return step_forward;
}

Position Rook::get_step_forward_white_figure(Position position)
{
	Position step_forward(position.get_row() - 1, position.get_col());
	return step_forward;
}

void Rook::set_backwards_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_backwards;
	set_step_backwards(step_backwards, get_position());

	while (step_backwards.is_valid_position() && is_position_empty(game, step_backwards))
	{
		all_possible_moves.push_back(step_backwards);

		set_step_backwards(step_backwards, step_backwards);
	}

	if (step_backwards.is_valid_position() && has_position_enemy_figure(game, step_backwards))
	{
		all_possible_moves.push_back(step_backwards);
	}
}

void Rook::set_step_backwards(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_step_backwards_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_step_backwards_white_figure(current);
	}
}

Position Rook::get_step_backwards_black_figure(Position position)
{
	Position step_backwards(position.get_row() - 1, position.get_col());
	return step_backwards;
}

Position Rook::get_step_backwards_white_figure(Position position)
{
	Position step_backwards(position.get_row() + 1, position.get_col());
	return step_backwards;
}

void Rook::set_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_left;
	set_step_left(step_left, get_position());

	while (step_left.is_valid_position() && is_position_empty(game, step_left))
	{
		all_possible_moves.push_back(step_left);

		set_step_left(step_left, step_left);
	}

	if (step_left.is_valid_position() && has_position_enemy_figure(game, step_left))
	{
		all_possible_moves.push_back(step_left);
	}
}

void Rook::set_step_left(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_step_left_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_step_left_white_figure(current);
	}
}

Position Rook::get_step_left_black_figure(Position position)
{
	Position step_left(position.get_row(), position.get_col() + 1);
	return step_left;
}

Position Rook::get_step_left_white_figure(Position position)
{
	Position step_left(position.get_row(), position.get_col() - 1);
	return step_left;
}

void Rook::set_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_right;
	set_step_right(step_right, get_position());

	while (step_right.is_valid_position() && is_position_empty(game, step_right))
	{
		all_possible_moves.push_back(step_right);

		set_step_right(step_right, step_right);
	}

	if (step_right.is_valid_position() && has_position_enemy_figure(game, step_right))
	{
		all_possible_moves.push_back(step_right);
	}
}

void Rook::set_step_right(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_step_right_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_step_right_white_figure(current);
	}
}

Position Rook::get_step_right_black_figure(Position position)
{
	Position step_right(position.get_row(), position.get_col() - 1);
	return step_right;
}

Position Rook::get_step_right_white_figure(Position position)
{
	Position step_right(position.get_row(), position.get_col() + 1);
	return step_right;
}

bool Rook::is_position_empty(Game* game, Position& position)
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

bool Rook::has_position_enemy_figure(Game* game, Position& position)
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