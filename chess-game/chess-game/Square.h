#pragma once

#include "Figure.h"

class Square
{
public:
	Square();
	Square(const Square& other) = delete;
	Square& operator=(const Square& other) = delete;
	~Square();

public:
	void set_figure(Figure figure);
	Figure get_figure();

	bool is_empty() const;
	Figure remove_figure();

private:
	Figure* figure;

private:
	void clear();
};