#pragma once
#include <iostream> 
using namespace std; 

// tutaj deklaracja klasy Punkt
class Punkt {
	double x;
	double y;
public:
	Punkt() { x = 0; y = 0; };
	Punkt(double a, double b) { x = a; y = b; };
	Punkt(const Punkt& p2) { x = p2.x; y = p2.y; }; // TU BYŁ BŁĄD (brak const w nawiasie)
	double getx() const { return x; };
	double gety() const { return y; };
	void setx(double a) { x = a; };
	void sety(double b) { y = b; };
	void przesun(double a, double b);
	friend double odleglosc(const Punkt&, const Punkt&);
	friend istream& operator>>(istream& in, Punkt& p);
	friend ostream& operator<<(ostream& out, Punkt& p);
};
//double odleglosc(const Punkt&, const Punkt&);
//istream& operator>>(istream& in, Punkt& p);
//ostream& operator<<(ostream& out, Punkt& p);

