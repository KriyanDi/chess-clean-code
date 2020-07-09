#include "Figure.h"

Figure::Figure(Type type, Color color, Position position)
{
	set_type(type);
	set_color(color);
	set_position(position);
}

Figure::Figure(const Figure& other)
{
	this->position = other.position;
}

Figure::~Figure()
{
}

void Figure::set_type(Type type)
{
	this->type = type;
}

Type Figure::get_type() const
{
	Type type(this->type);
	return type;
}

void Figure::set_color(Color color)
{
	this->color = color;
}

Color Figure::get_color() const
{
	Color color(this->color);
	return color;
}

void Figure::set_position(Position position)
{
	this->position = position;
}

Position Figure::get_position() const
{
	Position position(this->position);
	return position;
}
