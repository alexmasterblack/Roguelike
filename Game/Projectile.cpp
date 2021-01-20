#include "Projectile.h"

Projectile::Projectile(Point position, char sym, int hp, int damage, int maxHp) :
	ShootCharacter(position, sym, hp, damage, maxHp) {}

Point Projectile::Move(std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	return GetPos();
}

void Projectile::Collide(GameObject* object)
{
	object->Collide(this);
}

void Projectile::Collide(Wall*)
{
}

void Projectile::Collide(Knight*)
{
}

void Projectile::Collide(Zombie*)
{
}

void Projectile::Collide(Dragon*)
{
}

void Projectile::Collide(Princess*)
{
}

void Projectile::Collide(AidKit*)
{
}

void Projectile::Collide(Projectile*)
{
}
