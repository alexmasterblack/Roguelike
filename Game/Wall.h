#pragma once
#include "GameObject.h"
#include "Knight.h"
#include "Zombie.h"
#include "Dragon.h"
#include "Projectile.h"
#include "Princess.h"
#include "AidKit.h"
#include "Wall.h"

class Wall : public GameObject
{
public:
	Wall(Point, char);

	Point Move(std::map<Point, std::shared_ptr<GameObject>>&) override;

	void Collide(GameObject*, std::map<Point, std::shared_ptr<GameObject>>&) override;

	void Collide(Wall*, std::map<Point, std::shared_ptr<GameObject>>&) override;

	void Collide(Knight*, std::map<Point, std::shared_ptr<GameObject>>&) override;

	void Collide(Zombie*, std::map<Point, std::shared_ptr<GameObject>>&) override;

	void Collide(Dragon*, std::map<Point, std::shared_ptr<GameObject>>&) override;

	void Collide(Princess*, std::map<Point, std::shared_ptr<GameObject>>&) override;

	void Collide(AidKit*, std::map<Point, std::shared_ptr<GameObject>>&) override;

	void Collide(Projectile*, std::map<Point, std::shared_ptr<GameObject>>&) override;
};

