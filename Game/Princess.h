#pragma once
#include "GameObject.h"

class Princess : public GameObject
{
public:
	Princess(Point, char);

	virtual void Collide(GameObject&) override;

	virtual void Collide(Wall&) override;

	virtual void Collide(Knight&) override;

	virtual void Collide(Zombie&) override;

	virtual void Collide(Dragon&) override;

	virtual void Collide(Princess&) override;

	virtual void Collide(AidKit&) override;

	virtual void Collide(Projectile&) override;
};

