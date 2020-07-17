#pragma once
#include "AllDirectionsOneStepMovement.h"

/// This class is Horizontal movement
///
/// This class is inherited by pieces that can move horizontaly
class HorizontalMovement : public AllDirectionsOneStepMovement
{
public:
	HorizontalMovement(Figure* figure);
	HorizontalMovement(const HorizontalMovement& other) = delete;
	HorizontalMovement& operator=(const HorizontalMovement& other) = delete;
	~HorizontalMovement();

protected:
	void set_horizontal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_left_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_right_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
};