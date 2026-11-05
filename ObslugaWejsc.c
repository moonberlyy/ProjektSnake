#include "ObslugaWejsc.h"
#include "SekcjaSystemowa.h"
#include "Inicjalizacja.h"
void ObslugaWejscia() {
    int klawisz = pobierz_znak();
    if (klawisz != 0) {
        // Blokada skrętu o 180 stopni (np. nie można iść w lewo, gdy idzie się w prawo)
        if ((klawisz == 'w' || klawisz == 'W') && kierunek != 'S') kierunek = 'W';
        if ((klawisz == 's' || klawisz == 'S') && kierunek != 'W') kierunek = 'S';
        if ((klawisz == 'a' || klawisz == 'A') && kierunek != 'D') kierunek = 'A';
        if ((klawisz == 'd' || klawisz == 'D') && kierunek != 'A') kierunek = 'D';
        if (klawisz == 'x' || klawisz == 'X') koniec_gry = true; // Wyjście z gry
    }
}