#include "Dragon.h"

Dragon::Dragon(Point position, char sym, int hp, int damage, int maxHp) :
	ShootCharacter(position, sym, hp, damage, maxHp) {}

Point Dragon::Move(std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	return GetPos();
}

void Dragon::Collide(GameObject* object, std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	object->Collide(this, gameObjects);
}

void Dragon::Collide(Wall*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Dragon::Collide(Knight*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Dragon::Collide(Zombie*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Dragon::Collide(Dragon*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Dragon::Collide(Princess*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Dragon::Collide(AidKit*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Dragon::Collide(Projectile*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}
