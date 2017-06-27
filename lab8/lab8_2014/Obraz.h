#pragma once
#include <iostream>
#include "Tablica.h"
using namespace std;

class Obraz : public Tablica
{
protected:
		int wiersze; // liczba wierszy
		int kolumny; // liczba kolumn
		int kolory; // liczba kolorow

public:
		Obraz(int _wiersze = 0, int _kolumny = 0, int _kolory = 0, int *_piksele = nullptr);
		
		Obraz(Obraz& );

		
		int operator()(int i, int j) const { return tab[wiersze * i + j]; }
		friend Obraz operator+(const Obraz &o1, const Obraz &o2);
		//Obraz& operator=(const Obraz& );
		friend ostream& operator<<(ostream &out, const Obraz &t);
		int getkolor() const { return kolory; };

		Obraz& operator--();
		
};