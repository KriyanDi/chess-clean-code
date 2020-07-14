#include "Bishop.h"

Bishop::Bishop(Type& type, Color& color, Position& position, Player& owner)
	: Figure(type, color, position, owner)
{
}

Bishop::~Bishop()
{
}
