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

void Position::set_row(int position)
{
	this->row = position;
}

void Position::set_col(int position)
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

void Position::set_position(int row, int col)
{
	set_row(row);
	set_col(col);
}
