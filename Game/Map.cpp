#include "Map.h"

Map::Map()
{
	std::ifstream file("Settings.json");
	file >> setting;
	file.close();
}

void Map::ReadMap()
{
	std::ifstream file("Map.txt");
	for (int row = 0; row < 18; row++) {
		for (int col = 0; col < 48; col++) {
			char symbol;
			file >> symbol;
			Point position(col, row);
			switch (symbol) {
			case 'K': {
				std::string sym = setting["Knight"]["sym"];
				gameObjects[position] = std::make_shared<Knight>(position,
					sym[0],
					setting["Knight"]["hp"],
					setting["Knight"]["damage"],
					setting["Knight"]["maxHp"]);
				break;
			}
			case 'Z': {
				std::string sym = setting["Zombie"]["sym"];
				gameObjects[position] = std::make_shared<Zombie>(position,
					sym[0],
					setting["Zombie"]["hp"],
					setting["Zombie"]["damage"],
					setting["Zombie"]["maxHp"]);
				break;
			}
			case 'D': {
				std::string sym = setting["Dragon"]["sym"];
				gameObjects[position] = std::make_shared<Dragon>(position,
					sym[0],
					setting["Dragon"]["hp"],
					setting["Dragon"]["damage"],
					setting["Dragon"]["maxHp"]);
				break;
			}
			case 'P': {
				std::string sym = setting["Projectile"]["sym"];
				gameObjects[position] = std::make_shared<Projectile>(position,
					sym[0],
					setting["Projectile"]["hp"],
					setting["Projectile"]["damage"],
					setting["Projectile"]["maxHp"]);
				break;
			}
			case '*': {
				std::string sym = setting["Princess"]["sym"];
				gameObjects[position] = std::make_shared<Princess>(position, sym[0]);
				break;
			}
			case '#': {
				std::string sym = setting["Wall"]["sym"];
				gameObjects[position] = std::make_shared<Wall>(position, sym[0]);
				break;
			}
			case '+': {
				std::string sym = setting["AidKit"]["sym"];
				gameObjects[position] = std::make_shared<AidKit>(position, sym[0]);
				break;
			}
			default: {
				break;
			}
			}
		}
	}
	file.close();
}

void Map::LoadMap()
{
	clear();
	for (int row = 0; row < 18; row++) {
		for (int col = 0; col < 48; col++) {
			auto pixel = gameObjects.find(Point(col, row));
			if (pixel != gameObjects.end()) {
				mvaddch(row, col, pixel->second->GetSym());
			}
		}
	}
	// dynamic_pointer_cast to go down/across class hierarchy
	int knightHp = 0;
	for (auto &object : gameObjects) {
		auto knight = std::dynamic_pointer_cast<Knight>(object.second);
		if (knight) {
			knightHp = knight->GetHp();
		}
	}
	mvprintw(1, 50, ("Hp: " + std::to_string(knightHp)).c_str());
	refresh();
}
