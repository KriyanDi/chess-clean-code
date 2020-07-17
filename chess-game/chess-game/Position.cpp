#include "Position.h"

/// This method is Position default constructor.
/// Sets default row and col - 0 0
Position::Position()
{
	set_position(0, 0);
}

/// This method is Position constructor that sets by given row and col
/// @param row row on the board field
/// @param col col on the board field
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

/// This method checks if Position is equal to our current position
/// @param rhs other position that is compared to the current
/// @return **true** if positions are equal, **false** otherwise
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

/// This function checks if current possition is valid 
/// according to the limits of the board field
bool Position::is_valid_position()
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

//bool Position::is_valid_position(int& row, int& col)
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
//bool Position::is_valid_position(const Position& position)
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
