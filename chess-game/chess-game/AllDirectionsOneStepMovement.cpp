#include "AllDirectionsOneStepMovement.h"

AllDirectionsOneStepMovement::AllDirectionsOneStepMovement(Figure* figure)
{
	set_figure_pointer(figure);
}

AllDirectionsOneStepMovement::~AllDirectionsOneStepMovement()
{
}

void AllDirectionsOneStepMovement::set_figure_pointer(Figure* figure)
{
	this->figure = figure;
}

void AllDirectionsOneStepMovement::set_one_step_all_directions_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
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

void AllDirectionsOneStepMovement::set_one_step_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_forward;
	set_one_step_forward(step_forward, figure->get_position());

	if (step_forward.is_valid_position() && is_position_empty(game, step_forward))
	{
		all_possible_moves.push_back(step_forward);
	}
}

void AllDirectionsOneStepMovement::set_one_step_forward(Position& position, Position current)
{
	if (figure->get_color() == Color::BLACK)
	{
		position = get_one_step_forward_black_figure(current);
	}
	else if (figure->get_color() == Color::WHITE)
	{
		position = get_one_step_forward_white_figure(current);
	}
}

Position AllDirectionsOneStepMovement::get_one_step_forward_black_figure(Position& position)
{
	Position step_forward(position.get_row() + 1, position.get_col());
	return step_forward;
}

Position AllDirectionsOneStepMovement::get_one_step_forward_white_figure(Position& position)
{
	Position step_forward(position.get_row() - 1, position.get_col());
	return step_forward;
}

void AllDirectionsOneStepMovement::set_one_step_backwards_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_backwards;
	set_one_step_backwards(step_backwards, figure->get_position());

	if (step_backwards.is_valid_position() && is_position_empty(game, step_backwards))
	{
		all_possible_moves.push_back(step_backwards);
	}
}

void AllDirectionsOneStepMovement::set_one_step_backwards(Position& position, Position current)
{
	if (figure->get_color() == Color::BLACK)
	{
		position = get_one_step_backwards_black_figure(current);
	}
	else if (figure->get_color() == Color::WHITE)
	{
		position = get_one_step_backwards_white_figure(current);
	}
}

Position AllDirectionsOneStepMovement::get_one_step_backwards_black_figure(Position& position)
{
	Position step_backwards(position.get_row() - 1, position.get_col());
	return step_backwards;
}

Position AllDirectionsOneStepMovement::get_one_step_backwards_white_figure(Position& position)
{
	Position step_forward(position.get_row() + 1, position.get_col());
	return step_forward;
}

void AllDirectionsOneStepMovement::set_one_step_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_left;
	set_one_step_left(step_left, figure->get_position());

	if (step_left.is_valid_position() && is_position_empty(game, step_left))
	{
		all_possible_moves.push_back(step_left);
	}
}

void AllDirectionsOneStepMovement::set_one_step_left(Position& position, Position current)
{
	if (figure->get_color() == Color::BLACK)
	{
		position = get_one_step_left_black_figure(current);
	}
	else if (figure->get_color() == Color::WHITE)
	{
		position = get_one_step_left_white_figure(current);
	}
}

Position AllDirectionsOneStepMovement::get_one_step_left_black_figure(Position& position)
{
	Position step_left(position.get_row(), position.get_col() - 1);
	return step_left;
}

Position AllDirectionsOneStepMovement::get_one_step_left_white_figure(Position& position)
{
	Position step_left(position.get_row(), position.get_col() + 1);
	return step_left;
}

void AllDirectionsOneStepMovement::set_one_step_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_right;
	set_one_step_right(step_right, figure->get_position());

	if (step_right.is_valid_position() && is_position_empty(game, step_right))
	{
		all_possible_moves.push_back(step_right);
	}
}

void AllDirectionsOneStepMovement::set_one_step_right(Position& position, Position current)
{
	if (figure->get_color() == Color::BLACK)
	{
		position = get_one_step_right_black_figure(current);
	}
	else if (figure->get_color() == Color::WHITE)
	{
		position = get_one_step_right_white_figure(current);
	}
}

Position AllDirectionsOneStepMovement::get_one_step_right_black_figure(Position& position)
{
	Position step_right(position.get_row(), position.get_col() + 1);
	return step_right;
}

Position AllDirectionsOneStepMovement::get_one_step_right_white_figure(Position& position)
{
	Position step_right(position.get_row(), position.get_col() - 1);
	return step_right;
}

void AllDirectionsOneStepMovement::set_one_step_forward_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_forward_left;
	set_one_step_forward_left(step_forward_left, figure->get_position());

	if (step_forward_left.is_valid_position() && is_position_empty(game, step_forward_left))
	{
		all_possible_moves.push_back(step_forward_left);
	}
}

void AllDirectionsOneStepMovement::set_one_step_forward_left(Position& position, Position current)
{
	if (figure->get_color() == Color::BLACK)
	{
		position = get_one_step_forward_left_black_figure(current);
	}
	else if (figure->get_color() == Color::WHITE)
	{
		position = get_one_step_forward_left_white_figure(current);
	}
}

Position AllDirectionsOneStepMovement::get_one_step_forward_left_black_figure(Position& position)
{
	Position step_forward_left(position.get_row() + 1, position.get_col() + 1);
	return step_forward_left;
}

Position AllDirectionsOneStepMovement::get_one_step_forward_left_white_figure(Position& position)
{
	Position step_forward_left(position.get_row() - 1, position.get_col() - 1);
	return step_forward_left;
}

void AllDirectionsOneStepMovement::set_one_step_backwards_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_backwards_left;
	set_one_step_backwards_left(step_backwards_left, figure->get_position());

	if (step_backwards_left.is_valid_position() && is_position_empty(game, step_backwards_left))
	{
		all_possible_moves.push_back(step_backwards_left);
	}
}

void AllDirectionsOneStepMovement::set_one_step_backwards_left(Position& position, Position current)
{
	if (figure->get_color() == Color::BLACK)
	{
		position = get_one_step_backwards_left_black_figure(current);
	}
	else if (figure->get_color() == Color::WHITE)
	{
		position = get_one_step_backwards_left_white_figure(current);
	}
}

Position AllDirectionsOneStepMovement::get_one_step_backwards_left_black_figure(Position& position)
{
	Position step_forward_left(position.get_row() - 1, position.get_col() + 1);
	return step_forward_left;
}

Position AllDirectionsOneStepMovement::get_one_step_backwards_left_white_figure(Position& position)
{
	Position step_forward_left(position.get_row() + 1, position.get_col() - 1);
	return step_forward_left;
}

void AllDirectionsOneStepMovement::set_one_step_forward_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_forward_right;
	set_one_step_forward_right(step_forward_right, figure->get_position());

	if (step_forward_right.is_valid_position() && is_position_empty(game, step_forward_right))
	{
		all_possible_moves.push_back(step_forward_right);
	}
}

void AllDirectionsOneStepMovement::set_one_step_forward_right(Position& position, Position current)
{
	if (figure->get_color() == Color::BLACK)
	{
		position = get_one_step_forward_right_black_figure(current);
	}
	else if (figure->get_color() == Color::WHITE)
	{
		position = get_one_step_forward_right_white_figure(current);
	}
}

Position AllDirectionsOneStepMovement::get_one_step_forward_right_black_figure(Position& position)
{
	Position step_forward_right(position.get_row() + 1, position.get_col() - 1);
	return step_forward_right;
}

Position AllDirectionsOneStepMovement::get_one_step_forward_right_white_figure(Position& position)
{
	Position step_forward_right(position.get_row() - 1, position.get_col() + 1);
	return step_forward_right;
}

void AllDirectionsOneStepMovement::set_one_step_backwards_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
{
	Position step_backwards_right;
	set_one_step_backwards_right(step_backwards_right, figure->get_position());

	if (step_backwards_right.is_valid_position() && is_position_empty(game, step_backwards_right))
	{
		all_possible_moves.push_back(step_backwards_right);
	}
}

void AllDirectionsOneStepMovement::set_one_step_backwards_right(Position& position, Position current)
{
	if (figure->get_color() == Color::BLACK)
	{
		position = get_one_step_backwards_right_black_figure(current);
	}
	else if (figure->get_color() == Color::WHITE)
	{
		position = get_one_step_backwards_right_white_figure(current);
	}
}

Position AllDirectionsOneStepMovement::get_one_step_backwards_right_black_figure(Position& position)
{
	Position step_backwards_right(position.get_row() - 1, position.get_col() - 1);
	return step_backwards_right;
}

Position AllDirectionsOneStepMovement::get_one_step_backwards_right_white_figure(Position& position)
{
	Position step_backwards_right(position.get_row() + 1, position.get_col() + 1);
	return step_backwards_right;
}

bool AllDirectionsOneStepMovement::is_position_empty(Game* game, Position& position)
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

bool AllDirectionsOneStepMovement::has_position_enemy_figure(Game* game, Position& position)
{
	if (game->get_board_field()->get_figure(position)->get_color() != figure->get_color())
	{
		return true;
	}
	else
	{
		return false;
	}
}