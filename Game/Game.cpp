#include "curses.h"
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <string>

void PlayGame() {
    initscr();
    noecho(); //выключение отображения вводимых символов
    cbreak();
    curs_set(0);

    //окно меню
    const int width = 60;
    const int height = 20;
    int offsetx = (COLS - width) / 2;
    int offsety = (LINES - height) / 2;
    WINDOW* winMenu = newwin(height, width, offsety, offsetx);
    box(winMenu, '#', '#');
    //отправка информации на экран
    refresh();
    wrefresh(winMenu);

    //само меню
    mvwprintw(winMenu, 5, width / 2 - 5, "Roguelike");
    keypad(winMenu, true);
    std::string choices[2] = { "Start", "Exit" };
    int choice;
    int highlight = 0;
    while (1) {
        for (int i = 0; i < 2; i++) {
            if (i == highlight) {
                mvwprintw(winMenu, height / 2 - 1 + i * 2, width / 2 - 5, ">");
                wattron(winMenu, A_REVERSE);
            }
            else {
                mvwprintw(winMenu, height / 2 - 1 + i * 2, width / 2 - 5, " ");
            }
            mvwprintw(winMenu, height / 2 - 1 + i * 2, width / 2 - 3, choices[i].c_str());
            wattroff(winMenu, A_REVERSE);
        }
        //обработка нажатия клавиш
        choice = wgetch(winMenu);
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
            if (highlight == 0) {
                clear();
                refresh();
            };
            if (highlight == 1) {
                exit(1);
            };
        default:
            break;
        }
        if (choice == 10 && highlight == 0) {
            while (1) {
                WINDOW* winGame = newwin(height, width, offsety, offsetx);
                box(winGame, '#', '#');
                refresh();
                wrefresh(winGame);
            }
        }
    }


    getch();
    endwin();
}

int main()
{
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    PlayGame();
    return 0;
}