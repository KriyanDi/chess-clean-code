#include "Horse.h"
#include "Game.h"

Horse::Horse(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
{
}

Horse::~Horse()
{
}

std::vector<Position> Horse::get_all_possible_moves(Game* game)
{
	std::vector<Position> all_possible_moves;
	set_forward_extended_diagonal_possible_moves(game, all_possible_moves);
	set_backwards_extended_diagonal_possible_moves(game, all_possible_moves);
	set_left_extended_diagonal_possible_moves(game, all_possible_moves);
	set_right_extended_diagonal_possible_moves(game, all_possible_moves);

	return all_possible_moves;
}

void Horse::set_forward_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
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

void Horse::set_forward_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal)
{
	std::vector<Position> extended_diagonal_moves;
	if (this->color == Color::BLACK)
	{
		extended_diagonal_moves = get_forward_extended_diagonal_moves_black_figure();
	}
	else if (this->color == Color::WHITE)
	{
		extended_diagonal_moves = get_forward_extended_diagonal_moves_white_figure();
	}

	int left_diagonal_index = 0, right_diagonal_index = 1;
	left_extended_diagonal = extended_diagonal_moves[left_diagonal_index];
	right_extended_diagonal = extended_diagonal_moves[right_diagonal_index];
}

std::vector<Position> Horse::get_forward_extended_diagonal_moves_black_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(this->position.get_row() + 2, this->position.get_col() - 1);
	Position extended_left_diagonal(this->position.get_row() + 2, this->position.get_col() + 1);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

std::vector<Position> Horse::get_forward_extended_diagonal_moves_white_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(this->position.get_row() - 2, this->position.get_col() - 1);
	Position extended_left_diagonal(this->position.get_row() - 2, this->position.get_col() + 1);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

void Horse::set_backwards_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
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

void Horse::set_backwards_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal)
{
	std::vector<Position> extended_diagonal_moves;
	if (this->color == Color::BLACK)
	{
		extended_diagonal_moves = get_backwards_extended_diagonal_moves_black_figure();
	}
	else if (this->color == Color::WHITE)
	{
		extended_diagonal_moves = get_backwards_extended_diagonal_moves_white_figure();
	}

	int left_diagonal_index = 0, right_diagonal_index = 1;
	left_extended_diagonal = extended_diagonal_moves[left_diagonal_index];
	right_extended_diagonal = extended_diagonal_moves[right_diagonal_index];
}

std::vector<Position> Horse::get_backwards_extended_diagonal_moves_black_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(this->position.get_row() - 2, this->position.get_col() - 1);
	Position extended_left_diagonal(this->position.get_row() - 2, this->position.get_col() + 1);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

std::vector<Position> Horse::get_backwards_extended_diagonal_moves_white_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(this->position.get_row() + 2, this->position.get_col() + 1);
	Position extended_left_diagonal(this->position.get_row() + 2, this->position.get_col() - 1);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

void Horse::set_left_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
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

void Horse::set_left_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal)
{
	std::vector<Position> extended_diagonal_moves;
	if (this->color == Color::BLACK)
	{
		extended_diagonal_moves = get_left_extended_diagonal_moves_black_figure();
	}
	else if (this->color == Color::WHITE)
	{
		extended_diagonal_moves = get_left_extended_diagonal_moves_white_figure();
	}

	int left_diagonal_index = 0, right_diagonal_index = 1;
	left_extended_diagonal = extended_diagonal_moves[left_diagonal_index];
	right_extended_diagonal = extended_diagonal_moves[right_diagonal_index];
}

std::vector<Position> Horse::get_left_extended_diagonal_moves_black_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(this->position.get_row() - 1, this->position.get_col() - 2 );
	Position extended_left_diagonal(this->position.get_row() + 1, this->position.get_col() - 2);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

std::vector<Position> Horse::get_left_extended_diagonal_moves_white_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(this->position.get_row() - 1, this->position.get_col() + 2);
	Position extended_left_diagonal(this->position.get_row() + 1, this->position.get_col() + 2);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

void Horse::set_right_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves)
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

void Horse::set_right_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal)
{
	std::vector<Position> extended_diagonal_moves;
	if (this->color == Color::BLACK)
	{
		extended_diagonal_moves = get_right_extended_diagonal_moves_black_figure();
	}
	else if (this->color == Color::WHITE)
	{
		extended_diagonal_moves = get_right_extended_diagonal_moves_white_figure();
	}

	int left_diagonal_index = 0, right_diagonal_index = 1;
	left_extended_diagonal = extended_diagonal_moves[left_diagonal_index];
	right_extended_diagonal = extended_diagonal_moves[right_diagonal_index];
}

std::vector<Position> Horse::get_right_extended_diagonal_moves_black_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(this->position.get_row() + 1, this->position.get_col() - 2);
	Position extended_left_diagonal(this->position.get_row() - 1, this->position.get_col() - 2);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

std::vector<Position> Horse::get_right_extended_diagonal_moves_white_figure()
{
	std::vector<Position> extended_diagonal_moves;
	Position extended_right_diagonal(this->position.get_row() - 1, this->position.get_col() +2);
	Position extended_left_diagonal(this->position.get_row() + 1, this->position.get_col() + 2);

	extended_diagonal_moves.push_back(extended_right_diagonal);
	extended_diagonal_moves.push_back(extended_left_diagonal);
	return extended_diagonal_moves;
}

bool Horse::is_position_empty(Game* game, Position& position)
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

bool Horse::has_position_enemy_figure(Game* game, Position& position)
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
