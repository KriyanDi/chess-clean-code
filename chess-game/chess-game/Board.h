#pragma once

#include "Square.h"

//const
const int BOARD_HIGH = 8;
const int BOARD_WIDTH = 8;

class Board
{
public:
	Board();
	Board(const Board& other) = delete;
	Board& operator=(const Board& other) = delete;
	~Board();

public:
	void set_board_field();
	void set_figure(Position position, Figure* figure);
	Figure* get_figure(Position position);
	void remove_figure(Position position);

private:
	Square** board_field;

private:
	void clear();

	void place_all_figures();

	void place_pawns();
	void place_black_pawns();
	void place_white_pawns();

	void place_rooks();
	void place_black_rooks();
	void place_white_rooks();

	void place_knights();
	void place_black_knights();
	void place_white_knights();

	void place_bishops();
	void place_black_bishops();
	void place_white_bishops();

	void place_queens();
	void place_black_queen();
	void place_white_queen();

	void place_kings();
	void place_black_king();
	void place_white_king();
};