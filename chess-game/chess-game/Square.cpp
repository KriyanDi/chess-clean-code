#include <iostream>

#include "Square.h"

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
	this->figure = new Figure(figure);
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
	if (this->figure)
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
		delete this->figure;
		figure = nullptr;
		return temp_figure;
	}
}

void Square::clear()
{
	delete this->figure;
	figure = nullptr;
}

