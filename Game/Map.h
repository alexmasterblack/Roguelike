#pragma once
#include <map>
#include <fstream>
#include "nlohmann/json.hpp"
#include "Knight.h"
#include "Zombie.h"
#include "Dragon.h"
#include "Projectile.h"
#include "Princess.h"
#include "AidKit.h"
#include "Wall.h"

using json = nlohmann::json;

class Map
{
public:
	Map();
	void ReadMap();
	void LoadMap();

	std::map<Point, std::shared_ptr<GameObject>> gameObjects;
private:
	json setting;
};