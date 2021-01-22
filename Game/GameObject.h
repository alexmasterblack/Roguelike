#pragma once
#include <map>
#include <memory>
#include "curses.h"
#include "Point.h"

class Wall;
class Knight;
class Zombie;
class Dragon;
class Princess;
class AidKit;
class Projectile;

class GameObject
{
public:
	GameObject(Point, char, int);

	~GameObject() = default;

	Point GetPos();

	char GetSym();

	void SetPos(Point);
	
	void SetSym(char);

	int GetHp();

	void SetHp(int);

	virtual Point Move(std::map<Point, std::shared_ptr<GameObject>>&) = 0;

	virtual void Collide(GameObject*) = 0;

	virtual void Collide(Wall*) = 0;

	virtual void Collide(Knight*) = 0;

	virtual void Collide(Zombie*) = 0;

	virtual void Collide(Dragon*) = 0;

	virtual void Collide(Princess*) = 0;

	virtual void Collide(AidKit*) = 0;

	virtual void Collide(Projectile*) = 0;

private:
	Point position;
	char sym;
	int hp;
};

