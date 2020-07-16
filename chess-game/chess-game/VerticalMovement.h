#pragma once
#include "AllDirectionsOneStepMovement.h"

class VerticalMovement : public AllDirectionsOneStepMovement
{
public:
	VerticalMovement(Figure* figure);
	VerticalMovement(const VerticalMovement& other) = delete;
	VerticalMovement& operator=(const VerticalMovement& other) = delete;
	~VerticalMovement();

protected:
	void set_vertical_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_forward_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_backwards_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
};