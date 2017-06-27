#pragma once

#include <iostream>

using namespace std;

#define TEST_01 1
#define TEST_02 1
#define TEST_03 1
#define TEST_04 0
const int MAX_PACJENTOW_U_LEKARZA = 50;
const int DZIENNY_LIMIT_PACJENTOW = 500;
static int numerid = 1;

class Pacjent {
	int id;
	enum StatusPacjenta {
		BRAK,
		OCZEKUJACY,
		W_GABINECIE,
		OBSLUZONY
	} status;
public:
	Pacjent() : id(-1), status(BRAK) {}
	StatusPacjenta print();
#if TEST_01 == 1
	static Pacjent nowyPacjent();
	int getId() const { return id; }
#endif
#if TEST_02 == 1
	bool obecny() const;
#endif
	friend class Lekarz;
};

class Poczekalnia {
	int iloscPacjentow; // powinno pozostac private
#if TEST_02 == 1
	Pacjent kolejka[DZIENNY_LIMIT_PACJENTOW];
public:
	Poczekalnia() : iloscPacjentow(0) {}
	bool zarejestruj(const Pacjent &);
#endif
	friend class Klinika;
};

class Lekarz {
#if TEST_01 == 1
	Pacjent * pacjenci[MAX_PACJENTOW_U_LEKARZA];
#endif
	int iloscPacjentow;
	int id;
public:
	void print();
#if TEST_01 == 1
	Lekarz();
	int getId() const { return id; }
#endif
#if TEST_03 == true
	bool diagnozuj(Pacjent &);
	int zdajRaport();
#endif
};

class Klinika {
	Poczekalnia poczekalnia;
#if TEST_02 == 1
	// TODO: zaimplementowac brakujace skladowe
public:
	static const int ILOSC_LEKARZY = 12;
	Lekarz lekarze[ILOSC_LEKARZY];
public:
	void print();
	bool przyjmijPacjenta(Pacjent);
#endif
#if TEST_03 == 1
	int rozpocznijPrace();
	int zakonczPrace();
#endif
};
