#include "Wall.h"

Wall::Wall(Point position, char sym) :
	GameObject(position, sym) {}

Point Wall::Move(std::map<Point, std::shared_ptr<GameObject>>&)
{
	return GetPos();
}

void Wall::Collide(GameObject* object, std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	object->Collide(this, gameObjects);
}

void Wall::Collide(Wall*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Wall::Collide(Knight*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Wall::Collide(Zombie*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Wall::Collide(Dragon*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Wall::Collide(Princess*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Wall::Collide(AidKit*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Wall::Collide(Projectile*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}
