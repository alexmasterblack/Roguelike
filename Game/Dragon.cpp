#include "Dragon.h"

Dragon::Dragon(Point position, char sym, int hp, int damage, int maxHp) :
	ShootCharacter(position, sym, hp, damage, maxHp) {}

void Dragon::Collide(GameObject&)
{
}

void Dragon::Collide(Wall&)
{
}

void Dragon::Collide(Knight&)
{
}

void Dragon::Collide(Zombie&)
{
}

void Dragon::Collide(Dragon&)
{
}

void Dragon::Collide(Princess&)
{
}

void Dragon::Collide(AidKit&)
{
}

void Dragon::Collide(Projectile&)
{
}
