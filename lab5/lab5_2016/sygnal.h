#pragma once
#include <iostream> 
using namespace std;
#include "maska.h"


class Sygnal
{
	double* probki;
	int ile_probek;
	
public:
	// Etap 1
	Sygnal(int = 0, double* = nullptr);
	Sygnal(const Sygnal& obiekt); // kopiujacy
	~Sygnal() { if(probki) delete[] probki; }
	//Etap 3
	void sortuj();
	Sygnal filtracja_medianowa(const Maska&);
	Sygnal& operator=(const Sygnal& obiekt);
	friend ostream& operator<<(ostream&, const Sygnal&);
};

