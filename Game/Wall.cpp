#include "Wall.h"

Wall::Wall(Point position, char sym) :
	GameObject(position, sym) {}

void Wall::Collide(GameObject&)
{
}

void Wall::Collide(Wall&)
{
}

void Wall::Collide(Knight&)
{
}

void Wall::Collide(Zombie&)
{
}

void Wall::Collide(Dragon&)
{
}

void Wall::Collide(Princess&)
{
}

void Wall::Collide(AidKit&)
{
}

void Wall::Collide(Projectile&)
{
}
