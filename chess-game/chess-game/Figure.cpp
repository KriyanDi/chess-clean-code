#include "Figure.h"

Figure::Figure(Type type, Color color, Position position, Player owner)
{
	set_type(type);
	set_color(color);
	set_position(position);
	set_owner(owner);
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

void Figure::set_owner(Player owner)
{
	this->owner = owner;
}

Player Figure::get_owner() const
{
	Player owner(this->owner);
	return owner;
}
