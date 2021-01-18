#include "Knight.h"

Knight::Knight(Point position, char sym, int hp, int damage, int maxHp) :
	ShootCharacter(position, sym, hp, damage, maxHp) {}

void Knight::Collide(GameObject&)
{
}

void Knight::Collide(Wall&)
{
}

void Knight::Collide(Knight&)
{
}

void Knight::Collide(Zombie&)
{
}

void Knight::Collide(Dragon&)
{
}

void Knight::Collide(Princess&)
{
}

void Knight::Collide(AidKit&)
{
}

void Knight::Collide(Projectile&)
{
}
