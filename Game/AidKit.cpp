#include "AidKit.h"

AidKit::AidKit(Point position, char sym) :
	GameObject(position, sym) {}

Point AidKit::Move(std::map<Point, std::shared_ptr<GameObject>>&)
{
	return GetPos();
}

void AidKit::Collide(GameObject* object)
{
	object->Collide(this);
}

void AidKit::Collide(Wall*)
{
}

void AidKit::Collide(Knight*)
{
}

void AidKit::Collide(Zombie*)
{
}

void AidKit::Collide(Dragon*)
{
}

void AidKit::Collide(Princess*)
{
}

void AidKit::Collide(AidKit*)
{
}

void AidKit::Collide(Projectile*)
{
}
