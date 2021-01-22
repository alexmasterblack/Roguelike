#include "Zombie.h"

Zombie::Zombie(Point position, char sym, int hp, int damage, int maxHp) :
	Character(position, sym, hp, damage, maxHp) {}

Point Zombie::Move(std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
    int x = 0, y = 0;
    switch (rand() % 4) {
    case 0: {
        x--;
        break;
    }
    case 1: {
        x++;
        break;
    }
    case 2: {
        y--;
        break;
    }
    case 3: {
        y++;
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

void Zombie::Collide(GameObject* object)
{
	object->Collide(this);
}

void Zombie::Collide(Wall*) {}

void Zombie::Collide(Knight* object)
{
    object->SetHp(std::max(0, object->GetHp() - GetDamage()));
}

void Zombie::Collide(Zombie*) {}

void Zombie::Collide(Dragon*) {}

void Zombie::Collide(Princess*) {}

void Zombie::Collide(AidKit*) {}

void Zombie::Collide(Projectile* object) {
    SetHp(std::max(0, GetHp() - object->GetDamage()));
    object->SetHp(0);
}
