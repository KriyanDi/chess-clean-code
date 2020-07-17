#pragma once
#include "AllDirectionsOneStepMovement.h"

/// This class is Diagonal movement
///
/// This class is inherited by the pieces that can move diagonaly.
/// The class has methods for left and right diagonal movement
class DiagonalMovement : public AllDirectionsOneStepMovement
{
public:
	DiagonalMovement(Figure* figure);
	DiagonalMovement(const DiagonalMovement& other) = delete;
	DiagonalMovement& operator=(const DiagonalMovement& other) = delete;
	~DiagonalMovement();

protected:
	void set_left_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_right_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_left_top_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_right_top_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_left_bottom_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_right_bottom_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
};