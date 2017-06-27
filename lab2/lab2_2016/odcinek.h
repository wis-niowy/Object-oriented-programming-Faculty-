#pragma once
#include <iostream> 
using namespace std;
#include "punkt.h"

class Odcinek
{
	Punkt p1;
	Punkt p2;
public:
	//	// tutaj deklaracje metod i funkcji zaprzyjaznionych
	Odcinek() { p1 = { 0, 0 }; p2 = { 0, 0 }; };
	Odcinek(Punkt&, Punkt&);
	Punkt getp1() const { return p1; }; // JAK TO ZADEKLAROWAC Z CONST ????
	Punkt getp2() const { return p2; };
	friend double odleglosc(const Odcinek&, const Punkt&);
	friend ostream& operator<<(ostream&, Odcinek&);
};

//double odleglosc(const Odcinek&, const Punkt&);
//ostream& operator<<(ostream&, Odcinek&);