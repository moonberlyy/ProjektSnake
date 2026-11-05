#include "LogikaGry.h"
#include "SekcjaSystemowa.h"
#include "Inicjalizacja.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void LogikaGry() {
    // 1. Zapisujemy starą pozycję głowy
    Punkt poprzednia_pozycja = waz[0];
    Punkt tymczasowa_pozycja;

    // 2. Przesuwamy głowę w wybranym kierunku
    if (kierunek == 'W' || kierunek == 'w') waz[0].y--;
    if (kierunek == 'S' || kierunek == 's') waz[0].y++;
    if (kierunek == 'A' || kierunek == 'a') waz[0].x--;
    if (kierunek == 'D' || kierunek == 'd') waz[0].x++;

    // 3. Przesuwamy resztę ciała węża
    for (int i = 1; i < dlugosc_wenza; i++) {
        tymczasowa_pozycja = waz[i];
        waz[i] = poprzednia_pozycja;
        poprzednia_pozycja = tymczasowa_pozycja;
    }

    // 4. Kolizja ze ścianami
    if (waz[0].x == 0 || waz[0].x == SZEROKOSC - 1 || waz[0].y == 0 || waz[0].y == WYSOKOSC - 1) {
        koniec_gry = true;
    }

    // 5. Kolizja z samym sobą
    for (int i = 1; i < dlugosc_wenza; i++) {
        if (waz[0].x == waz[i].x && waz[0].y == waz[i].y) {
            koniec_gry = true;
        }
    }

    // 6. Zjedzenie owocu
    if (waz[0].x == owoc.x && waz[0].y == owoc.y) {
        wynik += 10;
        if (dlugosc_wenza < MAX_DLUGOSC) {
            dlugosc_wenza++;
        }
        // Losowanie nowej pozycji owocu
        owoc.x = rand() % (SZEROKOSC - 2) + 1;
        owoc.y = rand() % (WYSOKOSC - 2) + 1;
    }
}
