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
}

Board::~Board()
{
	clear();
}

void Board::set_board_field()
{
	place_all_figures();
}

void Board::set_figure(Position position, Figure* figure)
{
	this->board_field[position.get_row()][position.get_col()].set_figure(*figure);
}

Figure* Board::get_figure(Position position)
{
	Figure* figure = board_field[position.get_row()][position.get_col()].get_figure();
	return figure;
}

void Board::remove_figure(Position position)
{
	this->board_field[position.get_row()][position.get_col()].remove_figure();
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
		board_field[1][i].set_figure(Figure(Type::PAWN, Color::BLACK, Position(1, i)));
	}
}

void Board::place_white_pawns()
{
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		board_field[6][i].set_figure(Figure(Type::PAWN, Color::WHITE, Position(6, i)));
	}
}

void Board::place_rooks()
{
	place_black_rooks();
	place_white_rooks();
}

void Board::place_black_rooks()
{
	board_field[0][0].set_figure(Figure(Type::ROOK, Color::BLACK, Position(0, 0)));
	board_field[0][7].set_figure(Figure(Type::ROOK, Color::BLACK, Position(0, 7)));
}

void Board::place_white_rooks()
{
	board_field[7][0].set_figure(Figure(Type::ROOK, Color::WHITE, Position(7, 0)));
	board_field[7][7].set_figure(Figure(Type::ROOK, Color::WHITE, Position(7, 7)));
}

void Board::place_knights()
{
	place_black_knights();
	place_white_knights();
}

void Board::place_black_knights()
{
	board_field[0][1].set_figure(Figure(Type::KNIGHT, Color::BLACK, Position(0, 1)));
	board_field[0][6].set_figure(Figure(Type::KNIGHT, Color::BLACK, Position(0, 6)));
}

void Board::place_white_knights()
{
	board_field[7][1].set_figure(Figure(Type::KNIGHT, Color::WHITE, Position(7, 1)));
	board_field[7][6].set_figure(Figure(Type::KNIGHT, Color::WHITE, Position(7, 6)));
}

void Board::place_bishops()
{
	place_black_bishops();
	place_white_bishops();
}

void Board::place_black_bishops()
{
	board_field[0][2].set_figure(Figure(Type::BISHOP, Color::BLACK, Position(0, 2)));
	board_field[0][5].set_figure(Figure(Type::BISHOP, Color::BLACK, Position(0, 5)));
}

void Board::place_white_bishops()
{
	board_field[7][2].set_figure(Figure(Type::BISHOP, Color::WHITE, Position(7, 2)));
	board_field[7][5].set_figure(Figure(Type::BISHOP, Color::WHITE, Position(7, 5)));
}

void Board::place_queens()
{
	place_black_queen();
	place_white_queen();
}

void Board::place_black_queen()
{
	board_field[0][3].set_figure(Figure(Type::QUEEN, Color::BLACK, Position(0, 3)));
}

void Board::place_white_queen()
{
	board_field[7][3].set_figure(Figure(Type::QUEEN, Color::WHITE, Position(7, 3)));
}

void Board::place_kings()
{
	place_black_king();
	place_white_king();
}

void Board::place_black_king()
{
	board_field[0][4].set_figure(Figure(Type::KING, Color::BLACK, Position(0, 4)));
}

void Board::place_white_king()
{
	board_field[7][4].set_figure(Figure(Type::KING, Color::WHITE, Position(7, 4)));
}

