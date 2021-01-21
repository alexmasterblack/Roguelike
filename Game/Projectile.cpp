#include "Projectile.h"

Projectile::Projectile(Point position, char sym, int hp, int damage, int maxHp) :
	ShootCharacter(position, sym, hp, damage, maxHp) {}

Point Projectile::Move(std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	return GetPos();
}

void Projectile::Collide(GameObject* object, std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	object->Collide(this, gameObjects);
}

void Projectile::Collide(Wall*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Projectile::Collide(Knight*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Projectile::Collide(Zombie*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Projectile::Collide(Dragon*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Projectile::Collide(Princess*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Projectile::Collide(AidKit*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Projectile::Collide(Projectile*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}
