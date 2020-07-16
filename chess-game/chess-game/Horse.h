#pragma once

#include "Figure.h"

class Horse : virtual public Figure
{
public:
	Horse(Type& type, Color& color, Position& position, Player& owner);
	Horse(const Horse& other) = delete;
	Horse& operator=(const Horse& other) = delete;
	virtual ~Horse();

public:
	std::vector<Position> get_all_possible_moves(Game* game) override;

private:
	void set_forward_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_forward_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal);
	std::vector<Position> get_forward_extended_diagonal_moves_black_figure();
	std::vector<Position> get_forward_extended_diagonal_moves_white_figure();

	void set_backwards_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_backwards_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal);
	std::vector<Position> get_backwards_extended_diagonal_moves_black_figure();
	std::vector<Position> get_backwards_extended_diagonal_moves_white_figure();

	void set_left_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_left_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal);
	std::vector<Position> get_left_extended_diagonal_moves_black_figure();
	std::vector<Position> get_left_extended_diagonal_moves_white_figure();

	void set_right_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_right_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal);
	std::vector<Position> get_right_extended_diagonal_moves_black_figure();
	std::vector<Position> get_right_extended_diagonal_moves_white_figure();

	bool is_position_empty(Game* game, Position& position);
	bool has_position_enemy_figure(Game* game, Position& position);
};
