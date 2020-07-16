#include "King.h"
#include "Game.h"

King::King(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
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

void King::set_one_step_all_directions_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	set_one_step_forward_possible_moves(game, all_possible_moves);
	set_one_step_backwards_possible_moves(game, all_possible_moves);
	set_one_step_left_possible_moves(game, all_possible_moves);
	set_one_step_right_possible_moves(game, all_possible_moves);

	set_one_step_forward_left_possible_moves(game, all_possible_moves);
	set_one_step_forward_right_possible_moves(game, all_possible_moves);
	set_one_step_backwards_left_possible_moves(game, all_possible_moves);
	set_one_step_backwards_right_possible_moves(game, all_possible_moves);
}

void King::set_one_step_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_forward;
	set_one_step_forward(step_forward, get_position());

	if (step_forward.is_valid_position() && is_position_empty(game, step_forward))
	{
		all_possible_moves.push_back(step_forward);
	}
}

void King::set_one_step_forward(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_one_step_forward_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_one_step_forward_white_figure(current);
	}
}

Position King::get_one_step_forward_black_figure(Position& position)
{
	Position step_forward(position.get_row() + 1, position.get_col());
	return step_forward;
}

Position King::get_one_step_forward_white_figure(Position& position)
{
	Position step_forward(position.get_row() - 1, position.get_col());
	return step_forward;
}

void King::set_one_step_backwards_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_backwards;
	set_one_step_backwards(step_backwards, get_position());

	if (step_backwards.is_valid_position() && is_position_empty(game, step_backwards))
	{
		all_possible_moves.push_back(step_backwards);
	}
}

void King::set_one_step_backwards(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_one_step_backwards_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_one_step_backwards_white_figure(current);
	}
}

Position King::get_one_step_backwards_black_figure(Position& position)
{
	Position step_backwards(position.get_row() - 1, position.get_col());
	return step_backwards;
}

Position King::get_one_step_backwards_white_figure(Position& position)
{
	Position step_forward(position.get_row() + 1, position.get_col());
	return step_forward;
}

void King::set_one_step_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_left;
	set_one_step_left(step_left, get_position());

	if (step_left.is_valid_position() && is_position_empty(game, step_left))
	{
		all_possible_moves.push_back(step_left);
	}
}

void King::set_one_step_left(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_one_step_left_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_one_step_left_white_figure(current);
	}
}

Position King::get_one_step_left_black_figure(Position& position)
{
	Position step_left(position.get_row(), position.get_col() - 1);
	return step_left;
}

Position King::get_one_step_left_white_figure(Position& position)
{
	Position step_left(position.get_row(), position.get_col() + 1);
	return step_left;
}

void King::set_one_step_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_right;
	set_one_step_right(step_right, get_position());

	if (step_right.is_valid_position() && is_position_empty(game, step_right))
	{
		all_possible_moves.push_back(step_right);
	}
}

void King::set_one_step_right(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_one_step_right_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_one_step_right_white_figure(current);
	}
}

Position King::get_one_step_right_black_figure(Position& position)
{
	Position step_right(position.get_row(), position.get_col() + 1);
	return step_right;
}

Position King::get_one_step_right_white_figure(Position& position)
{
	Position step_right(position.get_row(), position.get_col() - 1);
	return step_right;
}

void King::set_one_step_forward_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_forward_left;
	set_one_step_forward_left(step_forward_left, get_position());

	if (step_forward_left.is_valid_position() && is_position_empty(game, step_forward_left))
	{
		all_possible_moves.push_back(step_forward_left);
	}
}

void King::set_one_step_forward_left(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_one_step_forward_left_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_one_step_forward_left_white_figure(current);
	}
}

Position King::get_one_step_forward_left_black_figure(Position& position)
{
	Position step_forward_left(position.get_row() + 1, position.get_col() + 1);
	return step_forward_left;
}

Position King::get_one_step_forward_left_white_figure(Position& position)
{
	Position step_forward_left(position.get_row() - 1, position.get_col() - 1);
	return step_forward_left;
}

void King::set_one_step_backwards_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_backwards_left;
	set_one_step_backwards_left(step_backwards_left, get_position());

	if (step_backwards_left.is_valid_position() && is_position_empty(game, step_backwards_left))
	{
		all_possible_moves.push_back(step_backwards_left);
	}
}

void King::set_one_step_backwards_left(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_one_step_backwards_left_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_one_step_backwards_left_white_figure(current);
	}
}

Position King::get_one_step_backwards_left_black_figure(Position& position)
{
	Position step_forward_left(position.get_row() - 1, position.get_col() + 1);
	return step_forward_left;
}

Position King::get_one_step_backwards_left_white_figure(Position& position)
{
	Position step_forward_left(position.get_row() + 1, position.get_col() - 1);
	return step_forward_left;
}

void King::set_one_step_forward_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_forward_right;
	set_one_step_forward_right(step_forward_right, get_position());

	if (step_forward_right.is_valid_position() && is_position_empty(game, step_forward_right))
	{
		all_possible_moves.push_back(step_forward_right);
	}
}

void King::set_one_step_forward_right(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_one_step_forward_right_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_one_step_forward_right_white_figure(current);
	}
}

Position King::get_one_step_forward_right_black_figure(Position& position)
{
	Position step_forward_right(position.get_row() + 1, position.get_col() - 1);
	return step_forward_right;
}

Position King::get_one_step_forward_right_white_figure(Position& position)
{
	Position step_forward_right(position.get_row() - 1, position.get_col() + 1);
	return step_forward_right;
}

void King::set_one_step_backwards_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_backwards_right;
	set_one_step_backwards_right(step_backwards_right, get_position());

	if (step_backwards_right.is_valid_position() && is_position_empty(game, step_backwards_right))
	{
		all_possible_moves.push_back(step_backwards_right);
	}
}

void King::set_one_step_backwards_right(Position& position, Position current)
{
	if (this->color == Color::BLACK)
	{
		position = get_one_step_backwards_right_black_figure(current);
	}
	else if (this->color == Color::WHITE)
	{
		position = get_one_step_backwards_right_white_figure(current);
	}
}

Position King::get_one_step_backwards_right_black_figure(Position& position)
{
	Position step_backwards_right(position.get_row() - 1, position.get_col() - 1);
	return step_backwards_right;
}

Position King::get_one_step_backwards_right_white_figure(Position& position)
{
	Position step_backwards_right(position.get_row() + 1, position.get_col() + 1);
	return step_backwards_right;
}

bool King::is_position_empty(Game* game, Position& position)
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

bool King::has_position_enemy_figure(Game* game, Position& position)
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
