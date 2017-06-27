#include "fun.h"
#include "Slowo.h"


bool otworz(fstream& wejscie)
{
	cout << "Podaj nazwe pliku binarnego do otwarcia: ";
	char nazwa_pliku[N];
	cin >> nazwa_pliku;
	//wejscie = fstream(nazwa_pliku, ios::in/* | ios::binary*/);
	wejscie.open(nazwa_pliku, ios::in | ios::out | ios::binary);
		if (!wejscie) return false;
		else return true;
}


bool dopisz(fstream& plik, Slowo& slowo)
{
	plik.seekp(ios::end);
	plik.write((char*)&slowo, sizeof(slowo));
	if (plik.fail())
	{
		plik.clear();
		return false;
	}
	else
	{
		plik.clear();
		return true;
	}
}

bool wypisz(fstream& plik)
{
	Slowo do_wypisania;
	plik.seekg(ios::beg);
	while (plik.read((char*)&do_wypisania, sizeof(do_wypisania)))
	{
		cout << /*(Slowo&)*/do_wypisania; // trzeba bylo spowrotem rzutowac na (slowo&)
		if (plik.fail())
		{
			plik.clear();
			return false;
		}
	}
	plik.clear();
	return true;
}

bool modyfikuj(fstream& plik, int ind)
{
	Slowo do_zmiany;
	plik.seekg((ind-1)*sizeof(Slowo),ios::beg);
	if (plik.read((char*)&do_zmiany, sizeof(Slowo)))
	{
		cout << "Wybrany element do modyfikacji: " << endl;
		cout << /*(Slowo&)*/do_zmiany;
	}
	else
	{
		plik.clear();
		return false;
	}
	cout << "Podaj nowe slowo (lub wprowadz drobne modyfikacje): ";
	cin >> do_zmiany;
	plik.seekp((ind - 1)*sizeof(Slowo), ios::beg);
	if (plik.write((char*)&do_zmiany, sizeof(Slowo)))
	{
		cout << "Dane zmienione!" << endl;
		plik.clear();
		return true;
	}
	else
	{
		plik.clear();
		return false;
	}
}

//bool szukaj(/* uzupe³nij */){
//	//UZUPELNIJ
//}
