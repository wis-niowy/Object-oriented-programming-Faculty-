#pragma once
#include <iostream>
#include <cmath>
using namespace std;

#define N 20  

enum typ_zwierza { MYSZ, KOT, PIES };
struct zwierz {
	typ_zwierza typ;
	char imie[N];
	int wiek;
};

void wypisz(zwierz[], int);
void sortuj(zwierz[], int, int (*kryt)(zwierz[], int));
int wiek(zwierz tab[], int i);
int imie_wiek(zwierz tab[], int i);
int typ_imie_wiek(zwierz tab[], int i);
