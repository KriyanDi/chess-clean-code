#pragma once

#include "Figure.h"

class Bishop : virtual public Figure
{
	Bishop(Type type, Color color, Position position);
	Bishop(const Bishop& other) = delete;
	Bishop& operator=(const Bishop& other) = delete;
	virtual ~Bishop();
};
