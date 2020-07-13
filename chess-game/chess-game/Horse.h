#pragma once

#include "Figure.h"

class Horse : virtual public Figure
{
	Horse(Type type, Color color, Position position);
	Horse(const Horse& other) = delete;
	Horse& operator=(const Horse& other) = delete;
	virtual ~Horse();
};
