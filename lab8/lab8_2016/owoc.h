#include "produkt.h"

class owoc: public produkt
{
	double* ceny;
	int ile_cen;

	void konwertuj_ceny(string napis);
	void init_ceny(int ile_cen=0, double* ceny=nullptr);
	
public:
	owoc(const char* nazwa="", const char* kraj="", string napis="");

	owoc(const owoc& st);
	owoc& operator=(const owoc&);
	//~owoc();
		
	double srednia_cena() const;

	//byæ mo¿e coœ jeszcze?
	friend ostream& operator<<(ostream& out, const owoc& pr);
	void wypisz(ostream& out) const; // wirtualna
	virtual ~owoc();
};