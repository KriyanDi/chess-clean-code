#include "King.h"

King::King(Type& type, Color& color, Position& position, Player& owner)
    : Figure(type, color, position, owner)
{
}

King::~King()
{
}
