#pragma once
#include "ShootCharacter.h"

class Projectile : public ShootCharacter
{
public:
	Projectile(Point, char, int, int, int);

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

