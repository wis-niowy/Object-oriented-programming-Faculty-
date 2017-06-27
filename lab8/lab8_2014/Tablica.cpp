#include "Tablica.h"

Tablica::Tablica(int _rozmiar, int *_tab) : rozmiar(_rozmiar), tab(nullptr)
{
	if (rozmiar)
		tab = new (nothrow) int[rozmiar];

	if (tab)
		for (int i = 0; i < rozmiar; i++)
			tab[i] = (_tab) ? _tab[i] : 0; 
	else
		rozmiar=0;
}

Tablica::Tablica(const Tablica &t) : tab(nullptr)
{
	rozmiar = t.rozmiar;
	if (rozmiar)
		tab = new (nothrow) int[t.rozmiar];

	if (tab)
		for (int i = 0; i < rozmiar; i++)
			tab[i] = t.tab[i];
	else
		rozmiar=0;
}

Tablica::~Tablica()
{
	delete [] tab;
}

Tablica& Tablica::operator=(const Tablica &t)
{
	if (this == &t) return *this;

	rozmiar = t.rozmiar;
	delete [] tab;

	tab = new (nothrow) int[t.rozmiar];

	if (tab)
		for (int i = 0; i < rozmiar; i++)	tab[i] = t.tab[i];
	else
		rozmiar=0;

	return *this;
}

///////////////////// 1 ETAP //////////////////////////
Tablica& Tablica::operator--()
{
	if (tab)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			tab[i]--;
		}
	}
	return *this;
}

void Tablica::ogranicz_min_max(int min, int max)
{
	if (tab)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			if (tab[i] > max) tab[i] = max;
			else if (tab[i] < min) tab[i] = min;
		}
	}
}

Tablica operator+(const Tablica &t1, const Tablica &t2)
{
	int ile;
	if (t1.rozmiar > t2.rozmiar)
	{
		ile = t1.rozmiar;
		int* zwroc = new int[t1.rozmiar];
		for (int i = 0; i < t2.rozmiar; i++)
		{
			zwroc[i] = t1.tab[i] + t2.tab[i];
		}
		for (int i = t2.rozmiar; i < t1.rozmiar; i++)
		{
			zwroc[i] = t1.tab[i];
		}
		Tablica do_zwrotu(ile, zwroc);
		return do_zwrotu;
	}
	else if (t2.rozmiar < t2.rozmiar)
	{
		ile = t2.rozmiar;
		int* zwroc = new int[t2.rozmiar];
		for (int i = 0; i < t1.rozmiar; i++)
		{
			zwroc[i] = t1.tab[i] + t2.tab[i];
		}
		for (int i = t1.rozmiar; i < t2.rozmiar; i++)
		{
			zwroc[i] = t2.tab[i];
		}
		Tablica do_zwrotu(ile, zwroc);
		return do_zwrotu;
	}
	else
	{
		ile = t1.rozmiar;
		int* zwroc = new int[t2.rozmiar];
		for (int i = 0; i < t2.rozmiar; i++)
		{
			zwroc[i] = t1.tab[i] + t2.tab[i];
		}
		Tablica do_zwrotu(ile, zwroc);
		return do_zwrotu;
	}
}

//////////////////////////////////////////////////////////

ostream& operator<<(ostream &out, Tablica &t)
{
	if (t.rozmiar < 1) return out << "Pusta tablica";

	for (int i = 0; i < t.rozmiar; i++)
		out << t.tab[i] << "  ";
 
	return out;
}