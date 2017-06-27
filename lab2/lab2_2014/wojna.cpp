#include <iostream>
using namespace std;
#include <time.h>
#include "wojna.h"

// TUTAJ zaimplementuj brakuj¹ce sk³adowe i funkcje dla klasy wojna

void wojna::nowa_talia()
{
	for (int i = 0; i < N / ILE_W_KOLORZE; i++)
		for (int j = 0; j < ILE_W_KOLORZE; j++)
		{
			karta k(static_cast<KOLOR>(i + 3), static_cast<FIGURA>(j));
			t[i * ILE_W_KOLORZE + j] = k;
		}
	ile = N;
	koniec = N - 1;
}
void wojna::wypisz(const char* opis) const
{
	cout << opis << endl;
	for (int i = 0; i < ile; i++)
	{
		t[i].wypisz();
		if (i % 13 == 12) cout << endl;
	}
}
void wojna::potasuj()
{
	for (int i = 0; i < N; i++)
	{
		int a = rand() % N - 1;
		karta temp;
		temp = t[a];
		t[a] = t[i];
		t[i] = temp;
	}
}
void wojna::dodaj_na_gore(const karta& k)
{
	t[ile] = k;
	ile++;
	koniec++;
}
karta wojna::zdejmij_z_dolu()
{
	karta zwroc;
	zwroc = t[koniec];
	koniec--;
	ile--;
	return zwroc;
}
int wojna::punkty() const
{
	int suma = 0;
	for (int i = 0; i < N; i++)
	{
		suma = suma + t[i].punkty();
	}
	return suma;
}

