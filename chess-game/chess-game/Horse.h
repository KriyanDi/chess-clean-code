#pragma once

#include "Figure.h"

class Horse : virtual public Figure
{
public:
	Horse(Type& type, Color& color, Position& position, Player& owner);
	Horse(const Horse& other) = delete;
	Horse& operator=(const Horse& other) = delete;
	virtual ~Horse();
};
