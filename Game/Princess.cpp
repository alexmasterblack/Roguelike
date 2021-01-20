#include "Princess.h"

Princess::Princess(Point position, char sym) :
	GameObject(position, sym) {}

Point Princess::Move(std::map<Point, std::shared_ptr<GameObject>>&)
{
	return GetPos();
}

void Princess::Collide(GameObject* object)
{
	object->Collide(this);
}

void Princess::Collide(Wall*)
{
}

void Princess::Collide(Knight*)
{
}

void Princess::Collide(Zombie*)
{
}

void Princess::Collide(Dragon*)
{
}

void Princess::Collide(Princess*)
{
}

void Princess::Collide(AidKit*)
{
}

void Princess::Collide(Projectile*)
{
}
