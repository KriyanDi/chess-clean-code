#pragma once

#include "Figure.h"

class King : virtual public Figure
{
	King(Type type, Color color, Position position, Player owner);
	King(const King& other) = delete;
	King& operator=(const King& other) = delete;
	virtual ~King();
};