#pragma once
#include "Talia.h"
#include <list>

class Gra:public Talia
{
	list<string> osoba;
	list<string> komputer;
	void odrzuc_pary_gracza(list<string>& k);
	void wyswietl_karty_gracza(list<string>& k);
	void wyciagnij_karte(list<string>& k1, list<string>& k2);

public:
	Gra(const Talia& t);
	void rozdaj();
	void odrzuc_pary();
	void wybiera_czlowiek();
	void wybiera_komputer();
	void ukladaj(char ch);
	void rozgrywka();
	void wyswietl_karty();
};

