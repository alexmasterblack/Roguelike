#include "AidKit.h"

AidKit::AidKit(Point position, char sym) :
	GameObject(position, sym) {}

void AidKit::Collide(GameObject&)
{
}

void AidKit::Collide(Wall&)
{
}

void AidKit::Collide(Knight&)
{
}

void AidKit::Collide(Zombie&)
{
}

void AidKit::Collide(Dragon&)
{
}

void AidKit::Collide(Princess&)
{
}

void AidKit::Collide(AidKit&)
{
}

void AidKit::Collide(Projectile&)
{
}
