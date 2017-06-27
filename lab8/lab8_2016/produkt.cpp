#include <iomanip>
#include "produkt.h"

produkt::produkt(const char* nazwa, const char* kraj)
{
	if (nazwa)
	{
		this->nazwa = string(nazwa);
	}
	else this->nazwa = string(" ");
	if (kraj)
	{
		this->kraj = string(kraj);
	}
	else this->kraj = string(" ");
}

ostream& operator<<(ostream& out, const produkt& pr)
{
	pr.wypisz(out);
	cout << endl;
	return out;
}

/////////////////////////////////////

void produkt::wypisz(ostream& out) const
{
	out << endl << this->nazwa << "  " << this->kraj;
}
