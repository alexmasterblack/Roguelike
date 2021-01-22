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
            break;
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
        Game();
        endwin();
        break;
    }
}

void GameProcess::Game()
{
    nodelay(stdscr, true);
    while (true) {
        for (auto object = gameMap.gameObjects.begin(); object != gameMap.gameObjects.end(); ) {
            if (object->second->GetHp() == 0) {
                object = gameMap.gameObjects.erase(object);
            }
            else {
                object++;
            }
        }
        for (auto object = gameMap.gameObjects.begin(); object != gameMap.gameObjects.end(); ) {
            Point position = object->second->Move(gameMap.gameObjects);
            auto oldObject = object;
            auto knight = std::dynamic_pointer_cast<Knight>(oldObject->second);
            if (knight) {
                if (knight->GetHp() == 0) {
                    ResultGame(false);
                    clear();
                    refresh();
                    return;
                }
                if (knight->GetEndGame()) {
                    ResultGame(true);
                    clear();
                    refresh();
                    return;
                }
            }
            if (position != oldObject->first) {
                object++;
                gameMap.gameObjects.erase(oldObject->first);
            }
            else {
                object++;
            }
        }
        gameMap.LoadMap();
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }
}

void GameProcess::ResultGame(bool result)
{
    clear();
    refresh();
    if (!result) {
        mvprintw(3, 18, "You are dead");
    }
    else {
        mvprintw(3, 18, "You are win");
    }
    while (true) {
        int command = getch();
        if (command == 'Q' || command == 'q') {
            break;
        }
    }
}
