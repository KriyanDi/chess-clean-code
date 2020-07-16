#pragma once

#include "AllDirectionsOneStepMovement.h"

class King 
	: virtual public Figure
	, public AllDirectionsOneStepMovement
{
public:
	King(Type& type, Color& color, Position& position, Player& owner);
	King(const King& other) = delete;
	King& operator=(const King& other) = delete;
	virtual ~King();

public:
	std::vector<Position> get_all_possible_moves(Game* game) override;
};