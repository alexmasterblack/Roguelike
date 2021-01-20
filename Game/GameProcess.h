#pragma once
#include <chrono>
#include <thread>
#include "Map.h"

class GameProcess
{
public:
	GameProcess();
	void StartGame();
	void Game();

private:
	Map gameMap;
};