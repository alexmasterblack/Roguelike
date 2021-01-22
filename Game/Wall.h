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
	Wall(Point, char, int);

	~Wall() = default;

	Point Move(std::map<Point, std::shared_ptr<GameObject>>&) override;

	void Collide(GameObject*) override;

	void Collide(Wall*) override;

	void Collide(Knight*) override;

	void Collide(Zombie*) override;

	void Collide(Dragon*) override;

	void Collide(Princess*) override;

	void Collide(AidKit*) override;

	void Collide(Projectile*) override;
};

