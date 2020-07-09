#pragma once
#include "Position.h"

enum Type
{
	PAWN = 1,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING
};

enum Color
{
	WHITE = 1, 
	BLACK, 
	NO_COLOR
};

class Figure
{
public:
	Figure(Type type, Color color, Position position);
	Figure(const Figure& other);
	Figure& operator=(const Figure& other) = delete;
	~Figure();

public:
	void set_type(Type type);
	Type get_type() const;

	void set_color(Color color);
	Color get_color() const;

	void set_position(Position position);
	Position get_position() const;

protected:
	Type type;
	Color color;
	Position position;
	
};