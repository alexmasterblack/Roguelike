#include "Dragon.h"

Dragon::Dragon(Point position, char sym, int hp, int damage, int maxHp) :
	ShootCharacter(position, sym, hp, damage, maxHp) {}

Point Dragon::Move(std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	return GetPos();
}

void Dragon::Collide(GameObject* object)
{
	object->Collide(this);
}

void Dragon::Collide(Wall*)
{
}

void Dragon::Collide(Knight*)
{
}

void Dragon::Collide(Zombie*)
{
}

void Dragon::Collide(Dragon*)
{
}

void Dragon::Collide(Princess*)
{
}

void Dragon::Collide(AidKit*)
{
}

void Dragon::Collide(Projectile*)
{
}
