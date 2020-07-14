#pragma once

#include <vector>

#include "Position.h"

class Game;

enum Player
{
	PLAYER_ONE = 1,
	PLAYER_TWO
};

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
	Figure(Type type, Color color, Position position, Player owner);
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

	void set_owner(Player owner);
	Player get_owner() const;

	std::vector<Position> get_all_possible_moves(const Game* game, Position position);
	char get_symbol();

protected:
	Player owner;
	Type type;
	Color color;
	Position position;

private:
	void copy_from(const Figure& other);
};