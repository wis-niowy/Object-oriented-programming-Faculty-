#pragma once
#include <iostream>
using namespace std;
#include "dane.h"
#include "wektor.h"


class obraz : private wektor 
{
	int* kolory;			// kolor znaku; indeks reprezentuje kod znaku
	int n;					// rozmiar palety kolor�w

	void init_kolory(int _n, int* _kolory=nullptr);	//ZAIMPLEMENTOWANA!
							
public:
	obraz();
	obraz(int m, int n, dane* d);	// wymiar obrazka/ rozmiar tablicy d/ tablica zakodowanych danych
		
	obraz(const obraz& P);
	obraz& operator=(const obraz& P);
	~obraz();

	void dodaj_kolor(char *znak, int kolor);			//dla podanego znaku - ustaw w palecie nowy kolor

	void skaluj(int k);					//je�li k<0, powi�kszamy 2-krotnie
										//je�li k>0, zmniejszamy 2-krotnie


	friend ostream& operator<<(ostream& out, const obraz& P);	//ZAIMPLEMENTOWANY!

	wektor::wymiar;		//gwarantuje publiczny dost�p do metody size z klasy tablica (w f.main)
	
	//dodane przeze mnie ....
	wektor::wektor;
};

