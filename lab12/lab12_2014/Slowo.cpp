
#include <iomanip>
#include <iostream>
#include <cstring>
#include "Slowo.h"

Slowo::Slowo(char _pol[], char _ang[] , float _trud): trud(_trud)
{
	strcpy(pol, _pol);
	strcpy(ang, _ang);
}

Slowo::Slowo(): trud(0)
{
	strcpy(pol, "Brak slowa po polsku");
	strcpy(ang, "Brak slowa po angielsku");
}

bool operator==(const Slowo& s1, const Slowo & s2)
{
	if (strcmp(s1.pol, s2.pol) == 0 && strcmp(s1.ang, s2.ang) == 0 && s1.trud == s2.trud)
		return true;
	else return false;
}

ostream& operator<<(ostream & out, const Slowo & s)
{
	out << "Slowo:" << endl;
	out << setw(15) << "polski:" << s.pol << endl;
	out << setw(15) << "angielski:" << s.ang << endl;
	out << setw(15) << "Trudnosc:" << s.trud << endl;
	return out;
}


istream& operator>>(istream & in, Slowo & s)
{
	cout << "Podaj slowo:" << endl;
	cout << "Po polsku:";
	in >> s.pol;
	cout << "Po angielsku:";
	in >> s.ang;
	cout << "Poziom trudnosci: ";
	in >> s.trud;
	return in;
}
