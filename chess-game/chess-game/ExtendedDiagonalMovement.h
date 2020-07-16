#pragma once

#include "AllDirectionsOneStepMovement.h"

class ExtendedDiagonalMovement : public AllDirectionsOneStepMovement
{
public:
	ExtendedDiagonalMovement(Figure* figure);
	ExtendedDiagonalMovement(const ExtendedDiagonalMovement& other) = delete;
	ExtendedDiagonalMovement& operator=(const ExtendedDiagonalMovement& other) = delete;
	~ExtendedDiagonalMovement();

protected:
	void set_forward_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_backwards_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_left_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);
	void set_right_extended_diagonal_possible_moves(Game* game, std::vector<Position>& all_possible_moves);

private:
	void set_forward_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal);
	std::vector<Position> get_forward_extended_diagonal_moves_black_figure();
	std::vector<Position> get_forward_extended_diagonal_moves_white_figure();

	void set_backwards_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal);
	std::vector<Position> get_backwards_extended_diagonal_moves_black_figure();
	std::vector<Position> get_backwards_extended_diagonal_moves_white_figure();

	void set_left_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal);
	std::vector<Position> get_left_extended_diagonal_moves_black_figure();
	std::vector<Position> get_left_extended_diagonal_moves_white_figure();

	void set_right_extended_diagonal(Position& left_extended_diagonal, Position& right_extended_diagonal);
	std::vector<Position> get_right_extended_diagonal_moves_black_figure();
	std::vector<Position> get_right_extended_diagonal_moves_white_figure();
};