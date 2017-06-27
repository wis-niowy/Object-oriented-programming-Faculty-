#pragma once
#include <iomanip>
#include <iostream> 
#include <string> 
#include "wyjatki.h"
using namespace std;

class samolot
{
protected:
	double ilosc_paliwa;
	int ilosc_zalogi;
	string miejsce_odlotu;
	int czas_przylotu[2];

public:
	samolot(double, int, string, int*) throw(wyjatek_transportu);

	double sprawdz_ilosc_paliwa() throw(wyjatek_braku_paliwa);
	void zuzycie_paliwa(double); //zmniejsza iloœæ paliwa o podan¹ wartoœæ

	virtual void info() {};
	virtual ~samolot() {};
};

class samolot_pasazerski :public samolot
{
	int max_liczba_miejsc;
	int ilosc_pasazerow;
public:
	samolot_pasazerski(double, int, string, int*, int, int) throw(wyjatek_oplacalnosci);
	void info();
};

class samolot_transportowy :public samolot
{
	double max_ladownosc;
	double towar;
public:
	samolot_transportowy(double, int, string, int*, double, double) throw(wyjatek_oplacalnosci);
	void oproznij_ladownie(); //wyrzucamy ca³y towar
	void info();
};