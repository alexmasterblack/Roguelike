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
        Collide(object->second.get(), gameObjects);
    }
    return GetPos();
}

void Zombie::Collide(GameObject* object, std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	object->Collide(this, gameObjects);
}

void Zombie::Collide(Wall*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Zombie::Collide(Knight* object, std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
	object->SetHp(std::max(0, object->GetHp() - GetDamage()));
    //gameObjects.erase(this->GetPos());
}

void Zombie::Collide(Zombie*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Zombie::Collide(Dragon*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Zombie::Collide(Princess*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Zombie::Collide(AidKit*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Zombie::Collide(Projectile*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}
