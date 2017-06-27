
#pragma once

#include <iostream>
#include <string>
using namespace std;

class produkt 
{
	string	nazwa;
	string  kraj;	//kraj pochodzenia

public:
	produkt(const char* nazwa="", const char* kraj="");
		
	// zaimplementuj tylko niezbêdne sk³adowe

	// byæ mo¿e w kolejnych etapach zadania trzeba bêdzie coœ poprawiæ w implementacji tej klasy?

	friend ostream& operator<<(ostream& out, const produkt& pr);

	virtual double srednia_cena() { return 0; };
	virtual void wypisz(ostream& out) const;
	virtual ~produkt() {};

	string getnazwa() const { return nazwa; };
	string getkraj() const { return kraj; };
};
