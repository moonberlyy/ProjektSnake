#include "SekcjaSystemowa.h"
#include "Inicjalizacja.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// Stan gry
Punkt waz[MAX_DLUGOSC];
int dlugosc_wenza;
Punkt owoc;
char kierunek; // 'W', 'S', 'A', 'D'
bool koniec_gry;
int wynik;

void Inicjalizacja() {
    koniec_gry = false;
    kierunek = 'D'; // Na start wąż idzie w prawo
    dlugosc_wenza = 3;
    wynik = 0;

    // Początkowa pozycja węża (środek planszy)
    for (int i = 0; i < dlugosc_wenza; i++) {
        waz[i].x = SZEROKOSC / 2 - i;
        waz[i].y = WYSOKOSC / 2;
    }

    // Losowe umieszczenie pierwszego owocu
    owoc.x = rand() % (SZEROKOSC - 2) + 1;
    owoc.y = rand() % (WYSOKOSC - 2) + 1;
}
