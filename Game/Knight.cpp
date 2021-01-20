#include "Knight.h"

Knight::Knight(Point position, char sym, int hp, int damage, int maxHp) :
	ShootCharacter(position, sym, hp, damage, maxHp) {}

Point Knight::Move(std::map<Point, std::shared_ptr<GameObject>>& gameObjects)
{
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    Point previousPos = GetPos();
    int x = 0, y = 0;
    while (true) {
        int command = getch();
        if (command == KEY_DOWN) {
            y++;
            break;
        }
        if (command == KEY_UP) {
            y--;
            break;
        }
        if (command == KEY_LEFT) {
            x--;
            break;
        }
        if (command == KEY_RIGHT) {
            x++;
            break;
        }
    }
    Point newPos(previousPos.x + x, previousPos.y + y);
    auto object = gameObjects[previousPos];
    gameObjects.erase(previousPos);
    SetPos(newPos);
    gameObjects[newPos] = object;
    return GetPos();
}

void Knight::Collide(GameObject* object)
{
    object->Collide(this);
}

void Knight::Collide(Wall*)
{
}

void Knight::Collide(Knight*)
{
}

void Knight::Collide(Zombie*)
{
}

void Knight::Collide(Dragon*)
{
}

void Knight::Collide(Princess*)
{
}

void Knight::Collide(AidKit*)
{
}

void Knight::Collide(Projectile*)
{
}
