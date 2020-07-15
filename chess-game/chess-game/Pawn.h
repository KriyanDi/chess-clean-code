#pragma once

#include "Figure.h"

class Pawn : virtual public Figure
{
public:
	Pawn(Type& type, Color& color, Position& position, Player& owner);
	Pawn(const Pawn &other) = delete;
	Pawn& operator=(const Pawn& other) = delete;
	virtual ~Pawn();

public:
	std::vector<Position> get_all_possible_moves(Game* game) override;

private:
	void set_one_step_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_one_step_forward(Position& position);
	Position get_one_step_forward_black_figure();
	Position get_one_step_forward_white_figure();
	
	void set_two_steps_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_two_steps_forward(Position& position);
	Position get_two_steps_forward_black_figure();
	Position get_two_steps_forward_white_figure();

	void set_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_two_diagonal_moves(Position& left_diagonal, Position& right_diagonal);
	std::vector<Position> get_two_diagonal_moves_black_figure();
	std::vector<Position> get_two_diagonal_moves_white_figure();

	bool is_position_empty(Game* game, Position& position);
	bool has_position_enemy_figure(Game* game, Position& position);
};	