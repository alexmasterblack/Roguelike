#include "Dragon.h"

Dragon::Dragon(Point position, char sym, int hp, int damage, int maxHp) :
	ShootCharacter(position, sym, hp, damage, maxHp) {}

Point Dragon::Move(std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
    int x = 0, y = 0;
    switch (rand() % 5) {
    case 0: {
        SetDirection(0);
        x--;
        break;
    }
    case 1: {
        SetDirection(1);
        x++;
        break;
    }
    case 2: {
        SetDirection(2);
        y--;
        break;
    }
    case 3: {
        SetDirection(3);
        y++;
        break;
    }
    case 4: {
        Shoot(gameObjects);
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

void Dragon::Shoot(std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
    int x = 0, y = 0;
    switch (GetDirection())
    {
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

    Point positionNew(GetPos().x + x, GetPos().y + y);
    auto object = gameObjects.find(positionNew);
    if (object == gameObjects.end()) {
        gameObjects[positionNew] = std::make_shared<Projectile>(positionNew, '*', 1, GetDamage(), 1, GetDirection());
    }
}

void Dragon::Collide(GameObject* object)
{
	object->Collide(this);
}

void Dragon::Collide(Wall*) {}

void Dragon::Collide(Knight* object)
{
    object->SetHp(std::max(0, object->GetHp() - GetDamage()));
}

void Dragon::Collide(Zombie*) {}

void Dragon::Collide(Dragon*) {}

void Dragon::Collide(Princess*) {}

void Dragon::Collide(AidKit*) {}

void Dragon::Collide(Projectile* object) {
    SetHp(std::max(0, GetHp() - this->GetDamage()));
    object->SetHp(0);
}
