#include "GameObject.h"

GameObject::GameObject(Point position, char sym) :
	position(position),
	sym(sym) {}

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
