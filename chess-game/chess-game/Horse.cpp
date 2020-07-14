#include "Horse.h"

Horse::Horse(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type,color,position, owner)
{
}

Horse::~Horse()
{
}
