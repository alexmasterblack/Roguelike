#include "GameProcess.h"

GameProcess::GameProcess()
{
	gameMap.ReadMap();
}

void GameProcess::StartGame()
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
    nodelay(stdscr, true);

    mvprintw(3, 18, "Roguelike");
    std::string choices[2] = { "Start", "Exit" };
    int choice;
    int highlight = 0;
    while (true) {
        for (int i = 0; i < 2; i++) {
            if (i == highlight) {
                mvprintw(5 + i * 2, 18, ">");
                wattron(stdscr, A_REVERSE);
            }
            else {
                mvprintw(5 + i * 2, 18, " ");
            }
            mvprintw(5 + i * 2, 20, choices[i].c_str());
            wattroff(stdscr, A_REVERSE);
        }
        choice = getch();
        switch (choice) {
        case KEY_UP:
            highlight--;
            if (highlight == -1) {
                highlight = 0;
            };
            break;
        case KEY_DOWN:
            highlight++;
            if (highlight == 2) {
                highlight = 1;
            };
            break;
        case 10:
            if (highlight == 1) {
                exit(1);
            };
        default:
            break;
        }
        if (choice == 10 && highlight == 0) {
            clear();
            refresh();
            break;
        }
    }
    while (true) {
        gameMap.LoadMap();
        //Game();
        ///endwin();
        //break;
    }
}

void GameProcess::Game()
{
    std::chrono::milliseconds interval(150);
    nodelay(stdscr, true);
    while (true) {
        for (auto& object : gameMap.gameObjects) {
            Point pos = object.second->Move(gameMap.gameObjects);
        }
        gameMap.LoadMap();
        std::this_thread::sleep_for(interval);
    }
}
