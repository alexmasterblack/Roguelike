#include "Character.h"

Character::Character(Point position, char sym, int hp, int damage, int maxHp) :
	GameObject(position, sym),
	hp(hp),
	damage(damage),
	maxHp(maxHp) {}

void Character::Move()
{
}

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

void Character::SetHp(int hp)
{
	this->hp = hp;
}

void Character::SetDamage(int damage)
{
	this->damage = damage;
}

void Character::SetMaxHp(int maxHp)
{
	this->maxHp = maxHp;
}