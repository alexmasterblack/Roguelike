#pragma once
#include "Character.h"

class ShootCharacter : public Character
{
public:
	ShootCharacter(Point, char, int, int, int);

	ShootCharacter(Point, char, int, int, int, int);

	int GetDirection();

	void SetDirection(int);
	
	virtual void Shoot(std::map<Point, std::shared_ptr<GameObject>>&) = 0;

private:
	int direction;
};

