#include "Projectile.h"

Projectile::Projectile(Point position, char sym, int hp, int damage, int maxHp) :
	ShootCharacter(position, sym, hp, damage, maxHp) {}

void Projectile::Collide(GameObject&)
{
}

void Projectile::Collide(Wall&)
{
}

void Projectile::Collide(Knight&)
{
}

void Projectile::Collide(Zombie&)
{
}

void Projectile::Collide(Dragon&)
{
}

void Projectile::Collide(Princess&)
{
}

void Projectile::Collide(AidKit&)
{
}

void Projectile::Collide(Projectile&)
{
}
