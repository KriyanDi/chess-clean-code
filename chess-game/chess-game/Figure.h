#pragma once

#include <vector>

#include "Position.h"

class Game;

enum Player
{
	PLAYER_ONE = 1,
	PLAYER_TWO,
	NO_PLAYER
};

enum Type
{
	PAWN = 1,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING,
	NO_TYPE
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
	void set_type(Type& type);
	Type get_type() const;

	void set_color(Color& color);
	Color get_color() const;

	void set_position(Position& position);
	Position get_position() const;

	void set_owner(Player& owner);
	Player get_owner() const;

	void set_has_been_moved();
	bool has_figure_been_moved();
	void has_moved();

	virtual std::vector<Position> get_all_possible_moves(Game* game);
	char get_symbol();

protected:
	Player owner;
	Type type;
	Color color;
	Position position;
	bool has_been_moved;

private:
	void copy_from(const Figure& other);
};