#include "Princess.h"

Princess::Princess(Point position, char sym) :
	GameObject(position, sym) {}

void Princess::Collide(GameObject&)
{
}

void Princess::Collide(Wall&)
{
}

void Princess::Collide(Knight&)
{
}

void Princess::Collide(Zombie&)
{
}

void Princess::Collide(Dragon&)
{
}

void Princess::Collide(Princess&)
{
}

void Princess::Collide(AidKit&)
{
}

void Princess::Collide(Projectile&)
{
}
