#include "Character.h"

int Character::GetHp() {
	return hp;
}

int Character::GetDamage() {
	return damage;
}

int Character::GetMaxHp()
{
	return maxHp;
}

char Character::GetSym()
{
	return sym;
}

void Character::SetHp(int hpNew)
{
	hp = hpNew;
}

void Character::SetDamage(int damageNew)
{
	damage = damageNew;
}

void Character::SetMaxHp(int maxHpNew)
{
	maxHp = maxHpNew;
}