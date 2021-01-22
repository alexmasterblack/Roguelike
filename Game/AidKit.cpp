#include "AidKit.h"

AidKit::AidKit(Point position, char sym, int hp) :
	GameObject(position, sym, hp) {}

Point AidKit::Move(std::map<Point, std::shared_ptr<GameObject>>&)
{
	return GetPos();
}

void AidKit::Collide(GameObject* object)
{
	object->Collide(this);
}

void AidKit::Collide(Wall*) {}

void AidKit::Collide(Knight* object)
{
	object->Collide(this);
}

void AidKit::Collide(Zombie*) {}

void AidKit::Collide(Dragon*) {}

void AidKit::Collide(Princess*) {}

void AidKit::Collide(AidKit*) {}

void AidKit::Collide(Projectile* object)
{
	SetHp(0);
}
