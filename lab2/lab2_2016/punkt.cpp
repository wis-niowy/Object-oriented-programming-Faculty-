#include <iostream> 
#include <math.h>
using namespace std; 
#include "punkt.h"

// tutaj implementacja klasy punkt
double odleglosc(const Punkt& p1, const Punkt& p2)
{
	double wynik;
	wynik = sqrt((p2.getx() - p1.getx()) * (p2.getx() - p1.getx()) + (p2.gety() - p1.gety()) * (p2.gety() - p1.gety()));
	return wynik;
}
void Punkt::przesun(double a, double b)
{
	x = x + a;
	y = y + b;
}
istream& operator>>(istream& in, Punkt& p)
{
	double a, b;
	cout << "Podaj wspolrzedne puntu (x, y): ";
	in >> a >> b;
	p.setx(a);  p.sety(b);
	return in;
}
ostream& operator<<(ostream& out, Punkt& p)
{
	out << "( " << p.getx() << "; " << p.gety() << " )";
	return out;
}

