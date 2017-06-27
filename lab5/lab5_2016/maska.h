#pragma once
#include <iostream> 
using namespace std;

class Maska
{
	double* wspolczynniki;
	int rozmiar;
public:
	friend class Sygnal;
	// dodaj
	Maska(int = 0, double* = nullptr);
	~Maska() { delete[] wspolczynniki; }
	double operator()();
	friend ostream& operator<<(ostream&, const Maska&);

};


