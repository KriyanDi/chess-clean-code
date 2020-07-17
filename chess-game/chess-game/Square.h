#pragma once

#include "Figure.h"

/// This Chess board square
///
/// This class is about square on the board field. 
/// It can give information what piece is in the square or 
/// if the square is empty. It also can set different pieces
/// into the square or remove them.
class Square
{
public:
	Square();
	Square(const Square& other) = delete;
	Square& operator=(const Square& other) = delete;
	~Square();

public:
	void set_figure(Figure figure);
	Figure* get_figure();

	bool is_empty() const;
	Figure remove_figure();

private:
	Figure* figure;

private:
	void clear();
};