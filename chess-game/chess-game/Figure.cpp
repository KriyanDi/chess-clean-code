#include "Figure.h"

Figure::Figure(Type type, Color color, Position position, Player owner)
{
	set_type(type);
	set_color(color);
	set_position(position);
	set_owner(owner);
	set_has_been_moved();
}

Figure::Figure(const Figure& other)
{
	copy_from(other);
}

Figure::~Figure()
{
}

void Figure::set_type(Type& type)
{
	this->type = type;
}

Type Figure::get_type() const
{
	Type type(this->type);
	return type;
}

void Figure::set_color(Color& color)
{
	this->color = color;
}

Color Figure::get_color() const
{
	Color color(this->color);
	return color;
}

void Figure::set_position(Position& position)
{
	this->position = position;
}

Position Figure::get_position() const
{
	Position position(this->position);
	return position;
}

void Figure::set_owner(Player& owner)
{
	this->owner = owner;
}

Player Figure::get_owner() const
{
	Player owner(this->owner);
	return owner;
}

void Figure::set_has_been_moved()
{
	this->has_been_moved = false;
}

bool Figure::has_figure_been_moved()
{
	if (this->has_been_moved)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::vector<Position> Figure::get_all_possible_moves(Game* game, Position& position)
{
	return std::vector<Position>();
}

char Figure::get_symbol()
{
	if (this == nullptr)
	{
		return '-';
	}
	else if (this->color == Color::BLACK)
	{
		switch (this->type)
		{
		case Type::PAWN:
			return 'P';

		case Type::ROOK:
			return 'R';

		case Type::KNIGHT:
			return 'H';

		case Type::BISHOP:
			return 'B';

		case Type::QUEEN:
			return 'Q';

		case Type::KING:
			return 'K';

		default:
			break;
		}
	}
	else if (this->color == Color::WHITE)
	{
		switch (this->type)
		{
		case Type::PAWN:
			return 'p';

		case Type::ROOK:
			return 'r';

		case Type::KNIGHT:
			return 'h';

		case Type::BISHOP:
			return 'b';

		case Type::QUEEN:
			return 'q';

		case Type::KING:
			return 'k';

		default:
			break;
		}
	}
	else
	{
		return '*';
	}
}

void Figure::copy_from(const Figure& other)
{
	this->owner = other.owner;
	this->type = other.type;
	this->color = other.color;
	this->position = other.position;
}
