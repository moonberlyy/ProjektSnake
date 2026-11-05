#pragma once
#include <stdbool.h>

#define SZEROKOSC 20
#define WYSOKOSC 20
#define MAX_DLUGOSC (SZEROKOSC * WYSOKOSC) 
typedef struct {
    int x;
    int y;
} Punkt;

// Stan gry
extern Punkt waz[MAX_DLUGOSC];
extern int dlugosc_wenza;
extern Punkt owoc;
extern char kierunek; // 'W', 'S', 'A', 'D'
extern bool koniec_gry;
extern int wynik;

void Inicjalizacja();