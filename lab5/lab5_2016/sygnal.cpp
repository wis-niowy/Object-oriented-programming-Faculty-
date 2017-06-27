#include <iostream> 
#include <iomanip> 
using namespace std;
#include "maska.h"
#include "sygnal.h"

// zaimplementuj


ostream& operator<<(ostream& out, const Sygnal& s) 
{ 
	out << "[";
	if (s.probki)
		for (int i = 0; i < s.ile_probek; i++)
			out << "  " << setprecision(2) << s.probki[i] << " ";
	out << " ]";
	return out; 
}
/////////////////////////////// 1 ETAP /////////////////////////////////////
Sygnal::Sygnal(int ile, double* _probki): ile_probek(ile)
{
	if (ile == 0) return;
	probki = new double[ile];
	if(!_probki)
	for (int i = 0; i < ile; i++)
	{
		probki[i] = 0;
	}
	else
	for (int i = 0; i < ile; i++)
	{
		probki[i] = _probki[i];
	}
}
////////////////////////// 3 ETAP //////////////////////////////////
void Sygnal::sortuj()
{
	for (int i = 0; i < ile_probek - 1; i++)
		for (int j = 0; j < ile_probek - 1 - i; j++)
		{
			if (probki[j] > probki[j + 1])
			{
				double temp = probki[j];
				probki[j] = probki[j + 1];
				probki[j + 1] = temp;
			}
		}
}
Sygnal Sygnal::filtracja_medianowa(const Maska& mask)
{
	int indeks_mediany = mask.rozmiar / 2;
	int ile_razy = ile_probek - (mask.rozmiar - 1);
	Sygnal do_wyciagania_mediany;
	Sygnal do_zwrocenia;
	do_zwrocenia.probki = new double[ile_razy];
	for (int i = 0; i < ile_razy; i++)
	{
		do_wyciagania_mediany.probki = new double[mask.rozmiar];

		for (int j = 0; j < mask.rozmiar; j++)
		{
			do_wyciagania_mediany.probki[j] = probki[i + j];
			do_wyciagania_mediany.ile_probek = mask.rozmiar;
		}
		do_wyciagania_mediany.sortuj();
		do_zwrocenia.probki[i] = do_wyciagania_mediany.probki[indeks_mediany];
		if(i < ile_razy - 1)
		delete[] do_wyciagania_mediany.probki;
	}
	do_zwrocenia.ile_probek = ile_razy;
	return do_zwrocenia;
}
Sygnal::Sygnal(const Sygnal& obiekt)  // kontruktor kopiujacy
{
	ile_probek = obiekt.ile_probek;
	probki = new double[ile_probek];
	for (int i = 0; i < ile_probek; i++)
	{
		probki[i] = obiekt.probki[i];
	}
}
Sygnal& Sygnal::operator=(const Sygnal& obiekt)
{
	if (probki) delete[] probki;
	ile_probek = obiekt.ile_probek;
	probki = new double[ile_probek];
	for (int i = 0; i < ile_probek; i++)
	{
		probki[i] = obiekt.probki[i];
	}
	return *this;
}