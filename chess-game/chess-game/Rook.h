#pragma once

#include "Figure.h"

class Rook : virtual public Figure
{
public:
	Rook(Type& type, Color& color, Position& position, Player& owner);
	Rook(const Rook& other) = delete;
	Rook& operator=(const Rook& other) = delete;
	virtual ~Rook();

public:
	std::vector<Position> get_all_possible_moves(Game* game) override;

private:
	void set_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_step_forward(Position& position, Position current);
	Position get_step_forward_black_figure(Position position);
	Position get_step_forward_white_figure(Position position);

	void set_backwards_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_step_backwards(Position& position, Position current);
	Position get_step_backwards_black_figure(Position position);
	Position get_step_backwards_white_figure(Position position);

	void set_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_step_left(Position& position, Position current);
	Position get_step_left_black_figure(Position position);
	Position get_step_left_white_figure(Position position);

	void set_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_step_right(Position& position, Position current);
	Position get_step_right_black_figure(Position position);
	Position get_step_right_white_figure(Position position);

	bool is_position_empty(Game* game, Position& position);
	bool has_position_enemy_figure(Game* game, Position& position);
};