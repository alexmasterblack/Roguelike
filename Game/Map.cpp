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
			Point position(row, col);
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
				std::string sym = setting["Princess"]["sym"];
				gameObjects[position] = std::make_shared<Princess>(position, sym[0],
					setting["Princess"]["hp"]);
				break;
			}
			case '#': {
				std::string sym = setting["Wall"]["sym"];
				gameObjects[position] = std::make_shared<Wall>(position, sym[0],
					setting["Wall"]["hp"]);
				break;
			}
			case '+': {
				std::string sym = setting["AidKit"]["sym"];
				gameObjects[position] = std::make_shared<AidKit>(position, sym[0],
					setting["AidKit"]["hp"]);
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
	// dynamic_pointer_cast to go down/across class hierarchy
	std::shared_ptr<Knight> knignt;
	for (const auto& object : gameObjects) {
		if (std::dynamic_pointer_cast<Knight>(object.second)) {
			knignt = std::dynamic_pointer_cast<Knight>(object.second);
			break;
		}
	}

	for (int row = 0; row < 18; row++) {
		for (int col = 0; col < 48; col++) {
			Point position = knignt->GetPos();
			if (pow((row - position.x), 2) + pow((col - position.y), 2) < 36) {
				Point place(row, col);
				auto object = gameObjects.find(place);
				if (object != gameObjects.end()) {
					mvaddch(row, col, object->second->GetSym());
				}
				else {
					mvaddch(row, col, '.');
				}
			}
			else {
				mvaddch(row, col, ' ');
			}
		}
	}

	mvprintw(1, 50, ("Health: " + std::to_string(knignt->GetHp())).c_str());
	refresh();
}
