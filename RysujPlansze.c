#include "RysujPlansze.h"
#include "Inicjalizacja.h"
#include "SekcjaSystemowa.h"
void RysujPlansze() {
    // Przesuwa kursor na początek konsoli (zamiast ciągłego migania cls/clear)
    wyczysc_ekran();

    for (int y = 0; y < WYSOKOSC; y++) {
        for (int x = 0; x < SZEROKOSC; x++) {
            // Rysowanie ścian
            if (y == 0 || y == WYSOKOSC - 1 || x == 0 || x == SZEROKOSC - 1) {
                printf("#");
            }
            // Rysowanie owocu
            else if (x == owoc.x && y == owoc.y) {
                printf("O");
            }
            else {
                bool wydrukowano_czlon = false;
                // Rysowanie głowy i ogona węża
                for (int i = 0; i < dlugosc_wenza; i++) {
                    if (waz[i].x == x && waz[i].y == y) {
                        if (i == 0) {
                            printf("X"); // Głowa
                        }
                        else {
                            printf("x"); // Ogon
                        }
                        wydrukowano_czlon = true;
                        break;
                    }
                }
                // Jeśli puste pole
                if (!wydrukowano_czlon) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    printf("Wynik: %d\n", wynik);
}