#pragma once

#include "AllDirectionsOneStepMovement.h"

class ForwardMovement : public AllDirectionsOneStepMovement
{
public:
	ForwardMovement(Figure* figure);
	ForwardMovement(const ForwardMovement& other) = delete;
	ForwardMovement& operator=(const ForwardMovement& other) = delete;
	~ForwardMovement();

protected:
	void set_two_steps_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);

private:
	void set_two_steps_forward(Position& position, Position current);
	Position get_two_steps_forward_black_figure(Position& position);
	Position get_two_steps_forward_white_figure(Position& position);

	void set_two_diagonal_moves(Position& left_diagonal, Position& right_diagonal);
	std::vector<Position> get_two_diagonal_moves_black_figure();
	std::vector<Position> get_two_diagonal_moves_white_figure();
};