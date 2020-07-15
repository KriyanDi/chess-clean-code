#pragma once

#include "Figure.h"

class Bishop : virtual public Figure
{
public:
	Bishop(Type& type, Color& color, Position& position, Player& owner);
	Bishop(const Bishop& other) = delete;
	Bishop& operator=(const Bishop& other) = delete;
	virtual ~Bishop();

public:
	std::vector<Position> get_all_possible_moves(Game* game) override;

private:
	void set_right_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_left_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);

	void set_right_top_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_step_right_top_diagonal(Position& position, Position current);
	Position get_step_right_top_diagonal_black_figure(Position position);
	Position get_step_right_top_diagonal_white_figure(Position position);

	void set_right_bottom_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_step_right_bottom_diagonal(Position& position, Position current);
	Position get_step_right_bottom_diagonal_black_figure(Position position);
	Position get_step_right_bottom_diagonal_white_figure(Position position);

	void set_left_top_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_step_left_top_diagonal(Position& position, Position current);
	Position get_step_left_top_diagonal_black_figure(Position position);
	Position get_step_left_top_diagonal_white_figure(Position position);

	void set_left_bottom_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_step_left_bottom_diagonal(Position& position, Position current);
	Position get_step_left_bottom_diagonal_black_figure(Position position);
	Position get_step_left_bottom_diagonal_white_figure(Position position);

	bool is_position_empty(Game* game, Position& position);
	bool has_position_enemy_figure(Game* game, Position& position);
};
