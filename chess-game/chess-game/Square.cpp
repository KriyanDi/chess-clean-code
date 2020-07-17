#include <iostream>

#include "Square.h"

//Figures
#include "Pawn.h"
#include "Rook.h"
#include "Horse.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

/// This method is Square default constructor
///
/// This method by default sets the figure pointer
/// to null pointer so the square is empty in its construction
Square::Square()
{
	this->figure = nullptr;
}

/// This method is Square destructor
///
/// This method clean allocated memory for the figure that was in
/// the square if there was one
Square::~Square()
{
	clear();
}

/// This method sets figure in the square
/// @param figure figure to be putted in the square
void Square::set_figure(Figure figure)
{
	Type type = figure.get_type();
	Color color = figure.get_color();
	Position position = figure.get_position();
	Player owner = figure.get_owner();

	switch (figure.get_type())
	{
	case Type::PAWN:
		this->figure = new Pawn(type, color, position, owner);
		break;
	case Type::ROOK:
		this->figure = new Rook(type, color, position, owner);
		break;
	case Type::KNIGHT:
		this->figure = new Horse(type, color, position, owner);
		break;
	case Type::BISHOP:
		this->figure = new Bishop(type, color, position, owner);
		break;
	case Type::QUEEN:
		this->figure = new Queen(type, color, position, owner);
		break;
	case Type::KING:
		this->figure = new King(type, color, position, owner);
		break;
	default:
		break;
	}

	if (!this->figure)
	{
		std::cout << "Problem allocating memory for figure!\n";
	}
}

/// This method gives us the figure thats in the square
/// @return pointer to the figure in the square
Figure* Square::get_figure()
{
	Figure* figure = this->figure;
	return figure;
}

/// This method tells us if there is figure in the square
/// @return **true** if the square is empty, **false** otherwise
bool Square::is_empty() const
{
	if (!this->figure)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/// This method removes figure from the square
/// @return copy of the removed figure, or if there is no figure
/// returns invalid figure
Figure Square::remove_figure()
{
	if (!this->is_empty())
	{
		Figure temp_figure(*this->figure);
		figure = nullptr;
		return temp_figure;
	}
	else
	{
		return Figure(Type::NO_TYPE, Color::NO_COLOR, Position(-1, -1), Player::NO_PLAYER);
	}
}

void Square::clear()
{
	delete this->figure;
	figure = nullptr;
}

