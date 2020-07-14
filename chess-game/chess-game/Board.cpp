#include <iostream>
#include "Board.h"

Board::Board()
{
	this->board_field = new Square * [BOARD_HIGH];
	if (!board_field)
	{
		std::cout << "Problem allocating memory for board field high!\n";
	}

	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		this->board_field[i] = new Square[BOARD_WIDTH];
		if (!board_field[i])
		{
			std::cout << "Problem allocating memory for board field width row " << i << " !\n";
		}
	}

	set_board_field();
	set_board_field_view();
}

Board::~Board()
{
	clear();
}

void Board::set_board_field()
{
	place_all_figures();
}

void Board::set_figure(Position& position, Figure* figure)
{
	this->board_field[position.get_row()][position.get_col()].set_figure(*figure);
	figure->set_position(position);
}

Figure* Board::get_figure(Position& position)
{
	Figure* figure = board_field[position.get_row()][position.get_col()].get_figure();
	return figure;
}

void Board::remove_figure(Position& position)
{
	this->board_field[position.get_row()][position.get_col()].remove_figure();
}

bool Board::is_empty(Position& position) const
{
	if (this->board_field[position.get_row()][position.get_col()].is_empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Board::set_board_field_view()
{
	set_board_field_view_outlines();
	set_board_field_view_center();
}

void Board::set_board_field_view_center()
{
	for (int row = 2; row <= 9; row++)
	{
		for (int col = 4; col <= 19; col = col + 2)
		{
			int converted_row = convert_row_board_field_view_to_row_board_view_index(row);
			int converted_col = convert_col_board_field_view_to_col_board_view_index(col);

			char figure_symbol = this->board_field[converted_row][converted_col].get_figure()->get_symbol();

			this->board_field_view[row][col] = figure_symbol;
		}
	}
}

void Board::update_board_field_view_center()
{
	set_board_field_view_center();
}

void Board::print_board_field_view()
{
	update_board_field_view_center();
	for (int row = 0; row < BOARD_FIELD_VIEW_HIGH; row++)
	{
		for (int col = 0; col < BOARD_FIELD_VIEW_WIDTH; col++)
		{
			std::cout << this->board_field_view[row][col];
		}
		std::cout << std::endl;
	}
}

void Board::set_board_field_view_outlines()
{
	set_all_chars_with_spaces_board_field_view();
	set_top_numbers_board_field_view();
	set_bottom_numbers_board_field_view();
	set_left_side_numbers_board_field_view();
	set_right_side_numbers_board_field_view();
}

void Board::set_all_chars_with_spaces_board_field_view()
{
	for (int row = 0; row < BOARD_FIELD_VIEW_HIGH; row++)
	{
		for (int col = 0; col < BOARD_FIELD_VIEW_WIDTH; col++)
		{
			this->board_field_view[row][col] = ' ';
		}
	}
}

void Board::set_top_numbers_board_field_view()
{
	int row = 0;
	int index = 0;
	for (int col = 4; col <= 19; col = col + 2)
	{
		this->board_field_view[row][col] = char(48 + index);
		index++;
	}
}

void Board::set_bottom_numbers_board_field_view()
{
	int row = 11;
	int index = 0;
	for (int col = 4; col <= 19; col = col + 2)
	{
		this->board_field_view[row][col] = char(48 + index);
		index++;
	}
}

void Board::set_left_side_numbers_board_field_view()
{
	int col = 0;
	int index = 0;
	for (int row = 2; row <= 9; row++)
	{
		this->board_field_view[row][col] = char(48 + index);
		index++;
	}
}

void Board::set_right_side_numbers_board_field_view()
{
	int col = 21;
	int index = 0;
	for (int row = 2; row <= 9; row++)
	{
		this->board_field_view[row][col] = char(48 + index);
		index++;
	}
}

int Board::convert_row_board_field_view_to_row_board_view_index(int& row)
{
	int converted_row = row - 2;
	return converted_row;
}

int Board::convert_col_board_field_view_to_col_board_view_index(int& col)
{
	int converted_col = (col / 2) - 2;
	return converted_col;
}

void Board::clear()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		delete[] this->board_field[i];
	}

	delete[] this->board_field;
}

void Board::place_all_figures()
{
	place_pawns();
	place_rooks();
	place_knights();
	place_bishops();
	place_queens();
	place_kings();
}

void Board::place_pawns()
{
	place_black_pawns();
	place_white_pawns();
}

void Board::place_black_pawns()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		board_field[1][i].set_figure(Figure(Type::PAWN, Color::BLACK, Position(1, i), Player::PLAYER_TWO));
	}
}

void Board::place_white_pawns()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		board_field[6][i].set_figure(Figure(Type::PAWN, Color::WHITE, Position(6, i), Player::PLAYER_ONE));
	}
}

void Board::place_rooks()
{
	place_black_rooks();
	place_white_rooks();
}

void Board::place_black_rooks()
{
	board_field[0][0].set_figure(Figure(Type::ROOK, Color::BLACK, Position(0, 0), Player::PLAYER_TWO));
	board_field[0][7].set_figure(Figure(Type::ROOK, Color::BLACK, Position(0, 7), Player::PLAYER_TWO));
}

void Board::place_white_rooks()
{
	board_field[7][0].set_figure(Figure(Type::ROOK, Color::WHITE, Position(7, 0), Player::PLAYER_ONE));
	board_field[7][7].set_figure(Figure(Type::ROOK, Color::WHITE, Position(7, 7), Player::PLAYER_ONE));
}

void Board::place_knights()
{
	place_black_knights();
	place_white_knights();
}

void Board::place_black_knights()
{
	board_field[0][1].set_figure(Figure(Type::KNIGHT, Color::BLACK, Position(0, 1), Player::PLAYER_TWO));
	board_field[0][6].set_figure(Figure(Type::KNIGHT, Color::BLACK, Position(0, 6), Player::PLAYER_TWO));
}

void Board::place_white_knights()
{
	board_field[7][1].set_figure(Figure(Type::KNIGHT, Color::WHITE, Position(7, 1), Player::PLAYER_ONE));
	board_field[7][6].set_figure(Figure(Type::KNIGHT, Color::WHITE, Position(7, 6), Player::PLAYER_ONE));
}

void Board::place_bishops()
{
	place_black_bishops();
	place_white_bishops();
}

void Board::place_black_bishops()
{
	board_field[0][2].set_figure(Figure(Type::BISHOP, Color::BLACK, Position(0, 2), Player::PLAYER_TWO));
	board_field[0][5].set_figure(Figure(Type::BISHOP, Color::BLACK, Position(0, 5), Player::PLAYER_TWO));
}

void Board::place_white_bishops()
{
	board_field[7][2].set_figure(Figure(Type::BISHOP, Color::WHITE, Position(7, 2), Player::PLAYER_ONE));
	board_field[7][5].set_figure(Figure(Type::BISHOP, Color::WHITE, Position(7, 5), Player::PLAYER_ONE));
}

void Board::place_queens()
{
	place_black_queen();
	place_white_queen();
}

void Board::place_black_queen()
{
	board_field[0][3].set_figure(Figure(Type::QUEEN, Color::BLACK, Position(0, 3), Player::PLAYER_TWO));
}

void Board::place_white_queen()
{
	board_field[7][3].set_figure(Figure(Type::QUEEN, Color::WHITE, Position(7, 3), Player::PLAYER_ONE));
}

void Board::place_kings()
{
	place_black_king();
	place_white_king();
}

void Board::place_black_king()
{
	board_field[0][4].set_figure(Figure(Type::KING, Color::BLACK, Position(0, 4), Player::PLAYER_TWO));
}

void Board::place_white_king()
{
	board_field[7][4].set_figure(Figure(Type::KING, Color::WHITE, Position(7, 4), Player::PLAYER_ONE));
}

