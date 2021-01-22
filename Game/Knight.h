#pragma once
#include "ShootCharacter.h"
#include "Knight.h"
#include "Zombie.h"
#include "Dragon.h"
#include "Projectile.h"
#include "Princess.h"
#include "AidKit.h"
#include "Wall.h"

class Knight : public ShootCharacter
{
public:
	Knight(Point, char, int, int, int);

	~Knight() = default;

	bool GetEndGame();

	void SetEndGame(bool);

	Point Move(std::map<Point, std::shared_ptr<GameObject>>&) override;
	
	void Shoot(std::map<Point, std::shared_ptr<GameObject>>&) override;

	void Collide(GameObject*) override;

	void Collide(Wall*) override;

	void Collide(Knight*) override;

	void Collide(Zombie*) override;

	void Collide(Dragon*) override;

	void Collide(Princess*) override;

	void Collide(AidKit*) override;

	void Collide(Projectile*) override;

private:
	bool endGame = false;
};

