#include "Princess.h"

Princess::Princess(Point position, char sym) :
	GameObject(position, sym) {}

Point Princess::Move(std::map<Point, std::shared_ptr<GameObject>>&)
{
	return GetPos();
}

void Princess::Collide(GameObject* object, std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	object->Collide(this, gameObjects);
}

void Princess::Collide(Wall*, std::map<Point, std::shared_ptr<GameObject>>&) {}

void Princess::Collide(Knight*, std::map<Point, std::shared_ptr<GameObject>>&)
{

}

void Princess::Collide(Zombie*, std::map<Point, std::shared_ptr<GameObject>>&) {}

void Princess::Collide(Dragon*, std::map<Point, std::shared_ptr<GameObject>>&) {}

void Princess::Collide(Princess*, std::map<Point, std::shared_ptr<GameObject>>&) {}

void Princess::Collide(AidKit*, std::map<Point, std::shared_ptr<GameObject>>&) {}

void Princess::Collide(Projectile*, std::map<Point, std::shared_ptr<GameObject>>&) {}