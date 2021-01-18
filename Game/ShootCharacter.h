#pragma once
#include "Character.h"

class ShootCharacter : public Character
{
public:
	ShootCharacter(Point, char, int, int, int);
	
	void Shoot();
};

