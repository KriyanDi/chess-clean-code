#include "Pawn.h"

Pawn::Pawn(Type type, Color color, Position position, Player owner)
	:Figure(type, color, position, owner)
{}

Pawn::~Pawn()
{
}
