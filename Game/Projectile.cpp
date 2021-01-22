#include "Projectile.h"

Projectile::Projectile(Point position, char sym, int hp, int damage, int maxHp, int direction) :
    ShootCharacter(position, sym, hp, damage, maxHp, direction) {
    switch (GetDirection()) {
    case 0: {
        SetSym('^');
        break;
    }
    case 1: {
        SetSym('v');
        break;
    }
    case 2: {
        SetSym('<');
        break;
    }
    case 3: {
        SetSym('>');
        break;
    }
    default:
        break;
    }
}

Point Projectile::Move(std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
    int x = 0, y = 0;
    switch (GetDirection()) {
    case 0: {
        y--;
        break;
    }
    case 1: {
        y++;
        break;
    }
    case 2: {
        x--;
        break;
    }
    case 3: {
        x++;
        break;
    }
    default:
        break;
    }

    Point position = GetPos();
    Point positionNew(position.x + x, position.y + y);

    auto object = gameObjects.find(positionNew);
    if (object == gameObjects.end()) {
        gameObjects[positionNew] = gameObjects[position];
        SetPos(positionNew);
    }
    else {
        Collide(object->second.get());
    }
    return GetPos();
}

void Projectile::Shoot(std::map<Point, std::shared_ptr<GameObject>>&) {}

void Projectile::Collide(GameObject* object)
{
	object->Collide(this);
}

void Projectile::Collide(Wall* object) {
    SetHp(0);
}

void Projectile::Collide(Knight* object)
{
    object->Collide(this);
}

void Projectile::Collide(Zombie* object) {
    object->Collide(this);
}

void Projectile::Collide(Dragon* object) {
    object->Collide(this);
}

void Projectile::Collide(Princess* object) {
    SetHp(0);
}

void Projectile::Collide(AidKit* object)
{
    object->Collide(this);
}

void Projectile::Collide(Projectile* object) {
    object->SetHp(0);
    SetHp(0);
}
