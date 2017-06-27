#include <iostream>
#include <Windows.h>
#include "Obraz.h"
using namespace std;

//////////////////////// 2 ETAP //////////////////////

Obraz::Obraz(int _wiersze, int _kolumny, int _kolory, int *_piksele):wiersze(_wiersze), kolumny(_kolumny), kolory(_kolory)//, Tablica(wiersze * kolumny, _piksele)
{
	(Tablica&)*this = Tablica(wiersze * kolumny, _piksele);
}

Obraz::Obraz(Obraz& o)
{
	(Tablica&)*this = o;
	wiersze = o.wiersze;
	kolumny = o.kolumny;
	kolory = o.kolory;
}


Obraz operator+(const Obraz &o1, const Obraz &o2)
{
	Obraz do_zwrotu;
	(Tablica&)do_zwrotu = (Tablica&)o1 + (Tablica&)o2;
	if (o1.rozmiar > o2.rozmiar)
	{
		do_zwrotu.wiersze = o1.wiersze;
		do_zwrotu.kolumny = o1.kolumny;
		do_zwrotu.kolory = o1.kolory;
	}
	else
	{
		do_zwrotu.wiersze = o2.wiersze;
		do_zwrotu.kolumny = o2.kolumny;
		do_zwrotu.kolory = o2.kolory;
	}
	do_zwrotu.ogranicz_min_max(1, 8);
	return do_zwrotu;
}

Obraz& Obraz::operator--()
{
	--(Tablica&)*this;
	(*this).ogranicz_min_max(1, 8);

	return *this;
}

//////////////////////////////////////////////////////

ostream& operator<<(ostream &out, const Obraz &o)
{
	if (o.rozmiar < 1) return out << "Pusty obraz";

	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < o.wiersze; i++)
	{
		for (int j = 0; j < o.kolumny; j++)
		{
			SetConsoleTextAttribute(hconsole,(o(i,j)<<4));
			out << o(i,j);
		}
		out << endl;
	}
	SetConsoleTextAttribute(hconsole,15);
	return out;
}
