#pragma once

#include <iostream>

using namespace std;

#define TEST_01 1
#define TEST_02 1
#define TEST_03 1
#define TEST_04 1
const int MAX_PACZEK_U_KURIERA = 7;
const int MAX_PACZEK_W_SORTOWNI = 50;
static int idkuriera = 1;
static int idpaczki = 1;

class Paczka {
	int id;
	enum StatusPaczki {
		NIEPRAWIDLOWA,
		NOWA,
		W_DORECZENIU,
		DORECZONA
	} status;
public:
	Paczka() : id(-1), status(NIEPRAWIDLOWA) {}
	StatusPaczki print();
#if TEST_01 == 1
	static Paczka przygotujPaczke();
	int getId() const { return id; }
#endif
#if TEST_02 == 1
	bool prawidlowa() const;
#endif
	friend class Kurier;
};

class Sortownia {
	int iloscPaczek; // powinno zostac private
#if TEST_02 == 1
	Paczka paczki[MAX_PACZEK_W_SORTOWNI];
public:
	Sortownia() : iloscPaczek(0) {}
	bool przyjmijPaczke(const Paczka &);
#endif
	friend class FirmaKurierska;
	bool operator+=(const Paczka&);
};

class Kurier {
#if TEST_01 == 1
	Paczka * paczki[MAX_PACZEK_U_KURIERA];
#endif
	int iloscPaczek;
	int id;
public:
	void print();
#if TEST_01 == 1
	Kurier();
	int getId() const { return id; }
#endif
#if TEST_03 == 1
	bool doreczPaczke(Paczka &);
	int rozliczPaczki();
#endif
	bool operator+=(Paczka&);
};

class FirmaKurierska {
	Sortownia sortownia;
#if TEST_02 == 1
	// TODO: zaimplementowac brakujace skladowe
public:
	static const int ILOSC_KURIEROW = 8;
	Kurier kurierzy[ILOSC_KURIEROW];
public:
	void print();
	bool odbierzPaczke(Paczka);
#endif
#if TEST_03 == 1
	int rozpocznijDzien();
	int zamknijDzien();
#endif
	bool operator+=(const Paczka&);
};
