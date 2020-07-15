#include "Position.h"

Position::Position()
{
	set_position(0, 0);
}

Position::Position(int row, int col)
{
	set_position(row, col);
}

Position::Position(const Position& other)
{
	set_position(other.get_row(), other.get_col());
}

Position& Position::operator=(const Position& other)
{
	if (&other != this)
	{
		set_position(other.get_row(), other.get_col());
	}

	return *this;
}

Position::~Position()
{
}

bool Position::operator==(const Position& rhs)
{
	if (this->row == rhs.get_row() &&
		this->col == rhs.get_col())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Position::set_row(int& position)
{
	this->row = position;
}

void Position::set_col(int& position)
{
	this->col = position;
}

int Position::get_row() const
{
	return this->row;
}

int Position::get_col() const
{
	return this->col;
}

bool Position::is_position_valid()
{
	if (0 <= this->row && this->row <= 7 &&
		0 <= this->col && this->col <= 7)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//bool Position::is_position_valid(int& row, int& col)
//{
//	if (0 <= row && row <= 7 &&
//		0 <= col && col <= 7)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Position::is_position_valid(const Position& position)
//{
//	if (0 <= position.get_row() && position.get_row() <= 7 &&
//		0 <= position.get_col() && position.get_col() <= 7)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}

void Position::set_position(int row, int col)
{
	set_row(row);
	set_col(col);
}
