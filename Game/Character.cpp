#include "Character.h"

Character::Character(Point position, char sym, int hp, int damage, int maxHp) :
	GameObject(position, sym, hp),
	damage(damage),
	maxHp(maxHp) {}

int Character::GetDamage() {
	return damage;
}

int Character::GetMaxHp()
{
	return maxHp;
}

void Character::SetDamage(int damage)
{
	this->damage = damage;
}

void Character::SetMaxHp(int maxHp)
{
	this->maxHp = maxHp;
}