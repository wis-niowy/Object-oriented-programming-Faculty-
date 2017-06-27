#pragma once
#include <iostream>
#include "Obraz.h"
#include "Tablica.h"
using namespace std;


class Histogram : public Tablica {



public:
	Histogram(int = 0);
	/*Histogram(Histogram& );*/
	void oblicz(const Obraz& o);

	friend ostream& operator<<(ostream&, const Histogram& );
};