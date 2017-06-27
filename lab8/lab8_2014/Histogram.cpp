#include "Histogram.h"
#include "Tablica.h"


// uzupelnij

Histogram::Histogram(int ile)
{
	if(ile > 0)
	(Tablica&)*this = Tablica(ile);
	else
	(Tablica&)*this = Tablica(0, nullptr);
}

//Histogram::Histogram(Histogram& h)
//{
//	(Tablica&)*this = h;
//}

void Histogram::oblicz(const Obraz& o)
{
	if()
	for (int i = 0; i < o.getkolor(); i++)
	{
		tab[i] += 8;
	}
}

ostream& operator<<(ostream& out, const Histogram& h)
{
	if (h.rozmiar < 1) out << "Histogram pusty";
	for (int i = 0; i < h.rozmiar; i++)
	{
		out << i + 1 << " : " << h.tab[i] << endl;
	}
	return out;
}