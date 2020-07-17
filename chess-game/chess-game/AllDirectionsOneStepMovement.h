#pragma once
#include "Figure.h"
#include "Game.h"

/// This is basic one step movement in all directions
///
/// This class is basis and its inherited by all other movement classes.
/// The class contains methods for movement in any direction by one step
class AllDirectionsOneStepMovement
{
public:
	AllDirectionsOneStepMovement(Figure* figure);
	AllDirectionsOneStepMovement(const AllDirectionsOneStepMovement& other) = delete;
	AllDirectionsOneStepMovement& operator=(const AllDirectionsOneStepMovement& other) = delete;
	~AllDirectionsOneStepMovement();

protected:
	void set_one_step_all_directions_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_one_step_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_one_step_backwards_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_one_step_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_one_step_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_one_step_forward_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_one_step_backwards_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_one_step_forward_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_one_step_backwards_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	bool is_position_empty(Game* game, Position& position);
	bool has_position_enemy_figure(Game* game, Position& position);

	void set_one_step_forward(Position& position, Position current);
	void set_one_step_backwards(Position& position, Position current);
	void set_one_step_left(Position& position, Position current);
	void set_one_step_right(Position& position, Position current);
	void set_one_step_forward_left(Position& position, Position current);
	void set_one_step_backwards_left(Position& position, Position current);
	void set_one_step_forward_right(Position& position, Position current);
	void set_one_step_backwards_right(Position& position, Position current);

protected:
	Figure* figure;

private:
	void set_figure_pointer(Figure* figure);

	Position get_one_step_forward_black_figure(Position& position);
	Position get_one_step_forward_white_figure(Position& position);

	Position get_one_step_backwards_black_figure(Position& position);
	Position get_one_step_backwards_white_figure(Position& position);

	Position get_one_step_left_black_figure(Position& position);
	Position get_one_step_left_white_figure(Position& position);

	Position get_one_step_right_black_figure(Position& position);
	Position get_one_step_right_white_figure(Position& position);

	Position get_one_step_forward_left_black_figure(Position& position);
	Position get_one_step_forward_left_white_figure(Position& position);

	Position get_one_step_backwards_left_black_figure(Position& position);
	Position get_one_step_backwards_left_white_figure(Position& position);

	Position get_one_step_forward_right_black_figure(Position& position);
	Position get_one_step_forward_right_white_figure(Position& position);

	Position get_one_step_backwards_right_black_figure(Position& position);
	Position get_one_step_backwards_right_white_figure(Position& position);
};