#include "ShootCharacter.h"

ShootCharacter::ShootCharacter(Point position, char sym, int hp, int damage, int maxHp) :
	Character(position, sym, hp, damage, maxHp) {}

ShootCharacter::ShootCharacter(Point position, char sym, int hp, int damage, int maxHp, int direction) :
	Character(position, sym, hp, damage, maxHp), direction(direction) {}

int ShootCharacter::GetDirection()
{
	return direction;
}

void ShootCharacter::SetDirection(int direction)
{
	this->direction = direction;
}
