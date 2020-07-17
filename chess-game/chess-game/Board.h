#pragma once

#include "Square.h"

//const
const int BOARD_HIGH = 8;
const int BOARD_WIDTH = 8;
const int BOARD_FIELD_VIEW_HIGH = 12;
const int BOARD_FIELD_VIEW_WIDTH = 24;

/// This is Chess board field
/// 
/// This class is about setting the board field,
/// printing the board field on the console. It 
/// also has the rules of putting the figures in
/// the correct order on the board field
class Board
{
public:
	Board();
	Board(const Board& other) = delete;
	Board& operator=(const Board& other) = delete;
	~Board();

public:
	void set_figure(Position& position, Figure* figure);
	Figure* get_figure(Position& position);
	void remove_figure(Position& position);

	bool is_empty(Position& position) const;

	void print_board_field_view();

private:
	Square** board_field;
	char board_field_view[BOARD_FIELD_VIEW_HIGH][BOARD_FIELD_VIEW_WIDTH];

private:
	void clear();

	void set_board_field();
	
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

	void update_board_field_view_center();
	void set_board_field_view();
	void set_board_field_view_center();
	void set_board_field_view_outlines();
	void set_all_chars_with_spaces_board_field_view();
	void set_top_numbers_board_field_view();
	void set_bottom_numbers_board_field_view();
	void set_left_side_numbers_board_field_view();
	void set_right_side_numbers_board_field_view();

	int convert_row_board_field_view_to_row_board_view_index(int& row);
	int convert_col_board_field_view_to_col_board_view_index(int& col);
};