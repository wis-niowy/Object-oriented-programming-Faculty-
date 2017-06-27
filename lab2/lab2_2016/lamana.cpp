#include <iostream> 
using namespace std; 
#include "odcinek.h"
#include "lamana.h"

// tutaj implementacja klasy Lamana 
Lamana::Lamana(int number1)
{
	Punkt p(0, 0);
	Odcinek o(p, p);

	for (int i = 0; i < number1; i++)
	{
		ol[i] = o;
	}
	number = number1;
}
Lamana::Lamana(Odcinek* l, int number1)
{
	for (int i = 0; i < number1; i++)
	{
		ol[i] = l[i];
	}
	number = number1;
}
void Lamana::setol(Odcinek p, int i)
{
	ol[i] = p;
}
ostream& operator<<(ostream& out, const Lamana& l)
{
	out << "[ ";
	for (int i = 0; i < l.getnumber(); i++)
	{
		out << l.getol(i) << "   ";
	}
	out << "]" << endl;
	return out;
}
Lamana operator+(const Lamana& l1, const Lamana& l2)
{
	double xl1, yl1, xl2, yl2;
	Odcinek koniecl1, poczatekl2;
	koniecl1 = l1.getol(l1.getnumber() - 1); // ostatni odcinek l1
	poczatekl2 = l2.getol(0); // pierwszy odcinek l2
	xl1 = koniecl1.getp2().getx(); // ostatnia wpsolrzedna x ostatniego odc l2 
	yl1 = koniecl1.getp2().gety();
	xl2 = poczatekl2.getp1().getx(); // pierwsza wspolrzedna x 1. odc l2
	yl2 = poczatekl2.getp1().gety();
	if (xl1 == xl2 && yl1 == yl2)
	{
		Lamana wynik;
		int wynum = l1.getnumber() + l2.getnumber();
		for (int i = 0; i < l1.getnumber(); i++)
		{
			wynik.setol(l1.getol(i), i);
		}
		for (int j = 0, i = l1.getnumber(); i < wynum; j++, i++)
		{
			wynik.setol(l2.getol(j), i);
		}
		wynik.setnumber(wynum);
		return wynik;
	}
	else cout << "Nie da sie dodac tych krzywych" << endl;
}