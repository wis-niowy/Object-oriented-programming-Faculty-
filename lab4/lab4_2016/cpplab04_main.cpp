#include "Klinika.h"

using namespace std;

int main()
{
	// ETAP 1 - nalezy ustawic #define TEST_01 na true w pliku Klinika.h
#if TEST_01 == 1
	const int t01Size = 500;
	Lekarz l01[t01Size];
	Pacjent p01[t01Size];
	for (int i = 0; i < t01Size; ++i) {
		p01[i] = Pacjent::nowyPacjent();
		for (int j = 0; j < i; ++j) {
			if (l01[i].getId() == l01[j].getId()) {
				cout << "Id lekarzy powinno byc unikalne!" << endl;
				exit(1);
			}
			if (p01[i].getId() == p01[j].getId()) {
				cout << "Id pacjentow powinno byc unikalne!" << endl;
				exit(1);
			}
		}
	}
	cout << "ETAP 1 - OK" << endl;
#endif

#if TEST_02 == 1
	Poczekalnia s02;
	bool przyjeto = DZIENNY_LIMIT_PACJENTOW > 0;
	for (int i = 0; i < DZIENNY_LIMIT_PACJENTOW; ++i) {
		przyjeto &= s02.zarejestruj(p01[i]);
	}
	if (!przyjeto) {
		cout << DZIENNY_LIMIT_PACJENTOW << " pacjentow powinno zostac dzis przyjetych w klinice!" << endl;
		exit(21);
	}
	if (s02.zarejestruj(p01[DZIENNY_LIMIT_PACJENTOW])) {
		cout << "Pacjenci przekraczajacy dzienna wydajnosc kliniki powinni zostac obsluzeni w innym terminie!" << endl;
		exit(2);
	}
	cout << "ETAP 2 - OK" << endl;
#endif

#if TEST_03 == 1
	Klinika k1;
	if (k1.przyjmijPacjenta(Pacjent())) {
		cout << "Przyjeto nieobecnego pacjenta!" << endl;
		exit(31);
	}
	int i = 0;
	for (; i < DZIENNY_LIMIT_PACJENTOW; ++i) {
		if (!k1.przyjmijPacjenta(Pacjent::nowyPacjent())) {
			break;
		}
	}
	if (i != DZIENNY_LIMIT_PACJENTOW) {
		cout << "Przyjeto zbyt malo pacjentow!" << endl;
		exit(32);
	}
	if (k1.przyjmijPacjenta(Pacjent::nowyPacjent())) {
		cout << "Przyjeto zbyt duzo pacjentow" << endl;
		exit(33);
	}
	k1.rozpocznijPrace();
	k1.print();
	int wynik = k1.zakonczPrace();
	int min = MAX_PACJENTOW_U_LEKARZA * Klinika::ILOSC_LEKARZY;
	if (min > DZIENNY_LIMIT_PACJENTOW) {
		min = DZIENNY_LIMIT_PACJENTOW;
	}
	if (wynik != min) {
		cout << "Niepoprawna ilosc obsluzonych pacjentow! (" << wynik << ")" << endl;
		exit(34);
	}
	if (!k1.zakonczPrace()) {
		cout << "Na koniec dnia, wszyscy pacjenci powinni zostac obsluzeni!" << endl;
		exit(35);
	}
	Klinika k2;
	while (k2.przyjmijPacjenta(Pacjent::nowyPacjent()));
	k2.rozpocznijPrace();
	int mod = DZIENNY_LIMIT_PACJENTOW % Klinika::ILOSC_LEKARZY;
	int c = (int)(DZIENNY_LIMIT_PACJENTOW / Klinika::ILOSC_LEKARZY);
	for (int i = 0; i < Klinika::ILOSC_LEKARZY; ++i) {
		int target = c + (mod > i ? 1 : 0);
		if (k2.lekarze[i].zdajRaport() != target) {
			cout << "Liczba pacjentow obsluzonych przez lekarza nie zgadza sie! (" << target << ")" << endl;
			exit(36);
		}
	}
	cout << "ETAP 3 - OK" << endl;
#endif

#if TEST_04 == 1
	Lekarz l04;
	bool error = false;
	if (!(l04 += Pacjent::nowyPacjent())) {
		cout << "operator += w klasie Lekarz niepoprawny!" << endl;
		error = true;
	}
	Poczekalnia p04;
	if (!(p04 += Pacjent::nowyPacjent())) {
		cout << "operator += w klasie Poczekalnia niepoprawny!" << endl;
		error = true;
	}
	Klinika k04;
	if (!(k04 += Pacjent::nowyPacjent())) {
		cout << "operator += w klasie Klinika niepoprawny!" << endl;
		error = true;
	}
	if (error) {
		exit(4);
	}
	cout << "ETAP 4 - OK" << endl;
#endif
	system("PAUSE");
}
