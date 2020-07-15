#include <iostream>

#include "Square.h"

//Figures
#include "Pawn.h"
#include "Rook.h"
#include "Horse.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

Square::Square()
{
	this->figure = nullptr;
}

Square::~Square()
{
	clear();
}

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

Figure* Square::get_figure()
{
	Figure* figure = this->figure;
	return figure;
}

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

