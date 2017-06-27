#include "Gra.h"
#include <ctime>
#include <string>
using namespace std;

// tutaj zaimplementuj binarny predykat dl_napisu

class dl_napisu
{
public:
	bool operator()(const string& s1, const string& s2) const
	{
		return s1.size() < s2.size();
	};
};

// tutaj zaimplementuj konstruktor Gra(const Talia& t)

Gra::Gra(const Talia& t): Talia(t)
{

}

void Gra::rozdaj()
{
	int kolejka = 0;
	while (!karty.empty())
	{
		if (kolejka % 2 == 0)
		{
			osoba.push_front(karty.back());
		}
		else if (kolejka % 2 == 1)
		{
			komputer.push_front(karty.back());
		}
		karty.pop_back();
		kolejka++;
	}
}

void Gra::wyswietl_karty_gracza(list<string>& k)
{

	for (list<string>::iterator it = k.begin(); it != k.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void Gra::wyswietl_karty()
{
	cout << "Twoje karty:\n";
	wyswietl_karty_gracza(osoba);
	cout << "Karty komputera:\n";
	wyswietl_karty_gracza(komputer);
}

void Gra::odrzuc_pary_gracza(list<string>& k)
{
	list<string>::iterator it1 = k.begin(), it2;
	bool flag = true;
	for (it1; it1 != k.end(); )
	{
		it2 = it1; it2++;
		for (it2; it2 != k.end(); ++it2)
		{
			if (*it1 == *it2)
			{
				it2 = k.erase(it2);
				it1 = k.erase(it1); // w odwrotenj kolejnosci uniewazni it1 !!!
				flag = false;
				break;
			}
		} // for
		if (flag)
		{
			++it1;
		}
		flag = true;
	} // for

}

void Gra::odrzuc_pary()
{
	odrzuc_pary_gracza(osoba);
	odrzuc_pary_gracza(komputer);
}

void Gra::ukladaj(char ch)
{
	switch (ch)
	{
	case 'a': 
		osoba.sort();
		komputer.sort();
		break;
	case 'd':
		osoba.sort(dl_napisu());
		komputer.sort(dl_napisu());
		break;
	case 'o':
		osoba.reverse();
		komputer.reverse();
		break;
	default:
		break;
	};
	

}


void Gra::wyciagnij_karte(list<string>& k1, list<string>& k2)
{
	int ile = k2.size();
	int przesun = rand() % ile;
	list<string>::iterator it = k2.begin();
	advance(it, przesun);
	if (*it == "Gargamel")
	{
		k1.splice(k1.end(), k2, it);
	}
	else
	{
		k1.remove(*it);
		k2.remove(*it);
	}
}

void Gra::wybiera_czlowiek()
{
	wyciagnij_karte(osoba, komputer);

}


void Gra::wybiera_komputer()
{
	wyciagnij_karte(komputer, osoba);

}

void Gra::rozgrywka()
{
	bool czlowiek = false;
	// ustal kto zaczyna - ten kto ma mniej kart
	if (osoba.size() < komputer.size())
		czlowiek = true;

	// dopoki nie zostanie ktos z piotrusiem (czyli ktoœ nie ma ju¿ kart) - ci¹gnij na zmianê
	int tura = 1;
	while(!osoba.empty() && !komputer.empty())
	{
		if (czlowiek)
		{
			cout << "TURA " << tura++ << endl;
			wybiera_czlowiek();
			wyswietl_karty();
			czlowiek = false; 
		}
		else
		{
			cout << "TURA " << tura++ << endl;
			wybiera_komputer();
			wyswietl_karty();
			czlowiek = true;
		}
	}

	if (osoba.empty())
		cout << "WYGRALES!!!" << endl;
	else
		cout << "PRZEGRANA - WYGRAL KOMPUTER" << endl;

}

/////////////////////////

