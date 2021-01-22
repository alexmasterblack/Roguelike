#include "GameObject.h"

GameObject::GameObject(Point position, char sym, int hp) :
	position(position),
	sym(sym),
	hp(hp) {}

Point GameObject::GetPos()
{
	return position;
}

char GameObject::GetSym()
{
	return sym;
}

void GameObject::SetPos(Point position)
{
	this->position = position;
}

void GameObject::SetSym(char sym)
{
	this->sym = sym;
}

int GameObject::GetHp()
{
	return hp;
}

void GameObject::SetHp(int hp)
{
	this->hp = hp;
}
