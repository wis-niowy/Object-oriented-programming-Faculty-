#pragma once
#include "slowo.h"

// klasa slownik - 4 pkt

class slownik{
	slowo** S;	// tablica wskaŸników slowo*
	int nS;		// rozmiar S
	int n;		// liczba s³ów

public:
	// za 2 pkt
	slownik(int _n=0, slowo* s=0);
	~slownik();
	void wstaw(const slowo& s);
	
	// za 1 pkt
	void test() const;

	// za 1 pkt
	void wypisz(ostream& out, int i) const;
	friend ostream& operator<<(ostream& out,const slownik& S);	
};

