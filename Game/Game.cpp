#include <windows.h>
#include <string>
#include "curses.h"
#include "GameProcess.h"
#define _WIN32_WINNT 0x0500

int main()
{
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
    GameProcess game;
    game.StartGame();
    return 0;
}