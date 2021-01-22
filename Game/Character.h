#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	Character(Point, char, int, int, int);
	
	~Character() = default;

	int GetDamage();

	int GetMaxHp();

	void SetDamage(int);

	void SetMaxHp(int);

private:
	int damage;
	int maxHp;
};