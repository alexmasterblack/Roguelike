#pragma once
#include "GameObject.h"

class Character : public GameObject
{
public:
	int GetHp();

	int GetDamage();

	int GetMaxHp();

	char GetSym();

	void SetHp(int);

	void SetDamage(int);

	void SetMaxHp(int);
	//void SetSym();

private:
	int hp;
	int damage;
	int maxHp;
	char sym;
};