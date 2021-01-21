#include "Knight.h"

Knight::Knight(Point position, char sym, int hp, int damage, int maxHp) :
	ShootCharacter(position, sym, hp, damage, maxHp) {}

Point Knight::Move(std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
    int x = 0, y = 0;
    int command = getch();
    switch (command)
    {
    case KEY_UP: {
        x--;
        break;
    }
    case KEY_DOWN: {
        x++;
        break;
    }
    case KEY_LEFT: {
        y--;
        break;
    }
    case KEY_RIGHT: {
        y++;
        break;
    }
    default:
        break;
    }

    while (getch() > 0) {}

    Point position = GetPos();
    Point positionNew(position.x + y, position.y + x);

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

void Knight::Collide(GameObject* object, std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
    object->Collide(this, gameObjects);
}

void Knight::Collide(Wall*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Knight::Collide(Knight*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Knight::Collide(Zombie* object, std::map<Point, std::shared_ptr<GameObject>>&)
{

}

void Knight::Collide(Dragon*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Knight::Collide(Princess*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}

void Knight::Collide(AidKit* object, std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
    SetHp(std::min(GetMaxHp(), GetHp() + object->GetHpUp()));
    gameObjects.erase(object->GetPos());
}

void Knight::Collide(Projectile*, std::map<Point, std::shared_ptr<GameObject>>&)
{
}
