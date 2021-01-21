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
	GameObject(Point, char);

	Point GetPos();

	char GetSym();

	void SetPos(Point);
	
	void SetSym(char);

	virtual Point Move(std::map<Point, std::shared_ptr<GameObject>>&) = 0;

	virtual void Collide(GameObject*, std::map<Point, std::shared_ptr<GameObject>>&) = 0;

	virtual void Collide(Wall*, std::map<Point, std::shared_ptr<GameObject>>&) = 0;

	virtual void Collide(Knight*, std::map<Point, std::shared_ptr<GameObject>>&) = 0;

	virtual void Collide(Zombie*, std::map<Point, std::shared_ptr<GameObject>>&) = 0;

	virtual void Collide(Dragon*, std::map<Point, std::shared_ptr<GameObject>>&) = 0;

	virtual void Collide(Princess*, std::map<Point, std::shared_ptr<GameObject>>&) = 0;

	virtual void Collide(AidKit*, std::map<Point, std::shared_ptr<GameObject>>&) = 0;

	virtual void Collide(Projectile*, std::map<Point, std::shared_ptr<GameObject>>&) = 0;

private:
	Point position;
	char sym;
};

