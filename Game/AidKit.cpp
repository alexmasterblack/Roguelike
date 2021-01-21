#include "AidKit.h"

AidKit::AidKit(Point position, char sym, int hpUp) :
	GameObject(position, sym), hpUp(hpUp) {}

int AidKit::GetHpUp()
{
	return hpUp;
}

Point AidKit::Move(std::map<Point, std::shared_ptr<GameObject>>&)
{
	return GetPos();
}

void AidKit::Collide(GameObject* object, std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	object->Collide(this, gameObjects);
}

void AidKit::Collide(Wall*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void AidKit::Collide(Knight* object, std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	object->Collide(this, gameObjects);
}

void AidKit::Collide(Zombie*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void AidKit::Collide(Dragon*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void AidKit::Collide(Princess*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void AidKit::Collide(AidKit*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void AidKit::Collide(Projectile*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}
