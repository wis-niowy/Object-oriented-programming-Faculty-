#include <iostream>
#include <cmath>
using namespace std;
#include "zwierz.h"


void wypisz(zwierz tab[], int n)
{
	for (int i = 0; i < n; i++)
	{
		switch (tab[i].typ)
		{
		case 0:
			cout << "zwierze: MYSZ   ";
			break;
		case 1:
			cout << "zwierze: KOT   ";
			break;
		case 2:
			cout << "zwierze: PIES   ";
			break;
		}
		cout << "imie: " << tab[i].imie << "   wiek : " << tab[i].wiek << endl;
	}
}
int wiek(zwierz tab[], int i)
{
	int wynik;
	if (tab[i].wiek > tab[i + 1].wiek) wynik = 1;
	else wynik = 0;
	return wynik;
}
int imie_wiek(zwierz tab[], int i)
{
	int wynik;
	if (strcmp(tab[i].imie, tab[i + 1].imie) > 0) wynik = 1;
	else if (strcmp(tab[i].imie, tab[i + 1].imie) == 0) wynik = wiek(tab, i);
	else wynik = 0;
	return wynik;
}
int typ_imie_wiek(zwierz tab[], int i)
{
	int wynik;
	if (tab[i].typ > tab[i + 1].typ) wynik = 1;
	else if (tab[i].typ == tab[i + 1].typ) wynik = imie_wiek(tab, i);
	else wynik = 0;
	return wynik;
}
void sortuj(zwierz tab[], int n, int (*kryt)(zwierz[], int))
{
	zwierz temp;
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - j - 1; i++)
		{
			if (kryt(tab, i) == 1)
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
		}
	}
}