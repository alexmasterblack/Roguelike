#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character(Point, char, int, int, int);

	void Move();

	int GetHp();

	int GetDamage();

	int GetMaxHp();

	void SetHp(int);

	void SetDamage(int);

	void SetMaxHp(int);

private:
	int hp;
	int damage;
	int maxHp;
};