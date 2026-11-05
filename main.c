#include "LogikaGry.h"
#include "ObslugaWejsc.h"
#include "SekcjaSystemowa.h"
#include "Inicjalizacja.h"
#include "RysujPlansze.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	przygotuj_konsole();
	Inicjalizacja();
	while (!koniec_gry) {
		RysujPlansze();
		ObslugaWejscia();
		LogikaGry();
		usleep(100000); // Opóźnienie 100ms
	}
	printf("Koniec gry! Twoj wynik: %d\n", wynik);
	return 0;
}