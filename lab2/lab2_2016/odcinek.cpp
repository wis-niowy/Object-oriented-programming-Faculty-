#include <iostream> 
#include <math.h>
using namespace std; 
#include "punkt.h"
#include "odcinek.h"

// tutaj implementacja klasy Odcinek
Odcinek::Odcinek(Punkt& pkt1, Punkt& pkt2)
{
	p1.setx(pkt1.getx());
	p1.sety(pkt1.gety());
	p2.setx(pkt2.getx());
	p2.sety(pkt2.gety());
}
double odleglosc(const Odcinek& o, const Punkt& p) // JAK TO ZROBIC Z CONST ????
{
	double wynik;
	Punkt srodek;
	srodek = { (o.getp1().getx() + o.getp2().getx()) / 2,
		(o.getp1().gety() + o.getp2().gety()) / 2 };
	wynik = sqrt((srodek.getx() - p.getx()) * (srodek.getx() - p.getx()) + (srodek.gety() - p.gety()) * (srodek.gety() - p.gety()));
	return wynik;
}
ostream& operator<<(ostream& out, Odcinek& o)
{
	out << "( " << o.getp1() << "," << o.getp2() << " )";
	return out;
}