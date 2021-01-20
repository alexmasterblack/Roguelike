#include "Zombie.h"

Zombie::Zombie(Point position, char sym, int hp, int damage, int maxHp) :
	Character(position, sym, hp, damage, maxHp) {}

Point Zombie::Move(std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	return GetPos();
}

void Zombie::Collide(GameObject* object)
{
	object->Collide(this);
}

void Zombie::Collide(Wall*)
{
}

void Zombie::Collide(Knight*)
{
}

void Zombie::Collide(Zombie*)
{
}

void Zombie::Collide(Dragon*)
{
}

void Zombie::Collide(Princess*)
{
}

void Zombie::Collide(AidKit*)
{
}

void Zombie::Collide(Projectile*)
{
}
