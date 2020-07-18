#include "Figure.h"

/// This method is Figure default constructor
/// @param type figure type
/// @param color figure color
/// @param position position on the board field
/// @param owner which player owns the figure
Figure::Figure(Type type, Color color, Position position, Player owner)
{
	set_type(type);
	set_color(color);
	set_position(position);
	set_owner(owner);
	set_has_been_moved();
}

/// This method is Figure copy constructor 
/// @param other figure from which we copy
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
	if (this != nullptr)
	{
		Color color(this->color);
		return color;
	}
	else
	{
		return Color::NO_COLOR;
	}
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

void Figure::has_moved()
{
	this->has_been_moved = true;
}

/// This method gives us all possible moves for our figure on the board field
/// @return vector of possible positions on the board field
std::vector<Position> Figure::get_all_possible_moves(Game* game)
{
	return std::vector<Position>();
}

/// This method give us first letter of the piece name if its white it gives us small letter, if black - big letter
/// @return char symbol of the piece
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

bool operator==(const Figure& lhs, const Figure& rhs)
{
	if (lhs.get_type() == rhs.get_type() &&
		lhs.get_color() == rhs.get_color() &&
		lhs.get_position() == rhs.get_position() &&
		lhs.get_owner() == rhs.get_owner())
	{
		return true;
	}
	else
	{
		return false;
	}
}