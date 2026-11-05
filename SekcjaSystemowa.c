#include "SekcjaSystemowa.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Sekcja dla systemów Windows
#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#include <windows.h>
void usleep(int microseconds) { Sleep(microseconds / 1000); }
void przygotuj_konsole() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void wyczysc_ekran() {
    COORD coord = { 0,0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int pobierz_znak() { return _kbhit() ? _getch() : 0; }
// Sekcja dla systemów Linux / macOS
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
void wyczysc_ekran() { system("clear"); }
int pobierz_znak() {
    struct termios oldt, newt;
    int ch, oldf;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    return (ch != EOF) ? ch : 0;
}
#endif