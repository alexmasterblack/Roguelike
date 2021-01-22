#include "Wall.h"

Wall::Wall(Point position, char sym, int hp) :
	GameObject(position, sym, hp) {}

Point Wall::Move(std::map<Point, std::shared_ptr<GameObject>>&)
{
	return GetPos();
}

void Wall::Collide(GameObject* object)
{
	object->Collide(this);
}

void Wall::Collide(Wall*) {}

void Wall::Collide(Knight*) {}

void Wall::Collide(Zombie*) {}

void Wall::Collide(Dragon*) {}

void Wall::Collide(Princess*) {}

void Wall::Collide(AidKit*) {}

void Wall::Collide(Projectile* object) {
	object->Collide(this);
}