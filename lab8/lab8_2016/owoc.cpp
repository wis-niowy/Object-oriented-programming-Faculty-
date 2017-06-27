#include <iomanip>
#include "owoc.h"

void owoc::konwertuj_ceny(string napis)
{
	string sep("/");
	size_t k = napis.find(sep);
	int ile = 0;
	while (k != string::npos)
	{
		ile++;
		k = napis.find(sep, k + 1);
	}
	ile++; // ilosc cen w stringu
	double *_ceny = new double[ile];
	int i = 0; // iterator po tablicy double
	k = 0;
	size_t l = napis.find(sep);
	while (l != string::npos)
	{
		int dlugosc = l - k;
		string temp(napis, k, dlugosc);
		_ceny[i] = stod(temp);
		k = l + 1;
		l = napis.find(sep, k);
		i++;
	}
	string ostatni(napis, k);
	_ceny[i] = stod(ostatni);

	init_ceny(ile, _ceny);
}
//-----------------------------------------------------------------
void owoc::init_ceny(int ile_cen, double* ceny)
{
	this->ile_cen=0;
	this->ceny=nullptr;
	if (ile_cen>0)
	{
		this->ceny=new (nothrow) double[ile_cen];
		if (!this->ceny) return;

		this->ile_cen=ile_cen;
		for (int i=0;i<ile_cen;i++)
			this->ceny[i]=ceny? ceny[i]:0;
	}
}
//--------------------------------------------------------------------
owoc::owoc(const char* nazwa, const char* kraj, string napis)
{
	(produkt&)*this = produkt(nazwa, kraj);
	if (!napis.empty())
	this->konwertuj_ceny(napis);
}
//-------------------------------------------------------------
owoc::~owoc()
{
	delete[] ceny;
}
//------------------------------------------------------------
owoc::owoc(const owoc& o)
{
	(produkt&)*this = (produkt&)o;
	this->init_ceny(o.ile_cen, o.ceny);
}
//------------------------------------------------------------
owoc& owoc::operator=(const owoc& o)
{
	if (this != &o)
	{
		delete[] this->ceny;
		(produkt&)*this = (produkt&)o;
		this->init_ceny(o.ile_cen, o.ceny);
	}
	
	return *this;
}
//------------------------------------------------------------
double owoc::srednia_cena() const
{
	double sr=0;
	if (ile_cen > 1)
	{
		for (int i = 0; i < ile_cen; i++)
		{
			sr = sr + ceny[i];
		}
		sr = sr / ile_cen;
	}

	return sr;
}
//-----------------------------------------------------------

void owoc::wypisz(ostream& out) const
{
	produkt::wypisz(out);
	//out << (produkt&)*this; // DLACZRGO NIE DZIALA ??
	out << "   - srednia cena: " << this->srednia_cena() << " ceny: [ ";
	for (int i = 0; i < this->ile_cen; i++)
	{
		out << fixed << setprecision(2) << this->ceny[i] << " ";
	}
	out << "]";
}

ostream& operator<<(ostream& out, const owoc& pr)
{
	// dla obiektow typu owoc, na ktore wskazuje ptr typu produkt
	// ten oper. wgl nie bedzie wywolany !!!

	// out << (produkt&)pr; /////  operator nie jest wirtualny !!!
	pr.wypisz(out);
	return out;
}


