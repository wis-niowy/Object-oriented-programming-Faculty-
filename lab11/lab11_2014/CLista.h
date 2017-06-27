#ifndef CLISTA_H
#define CLISTA_H

#include <iostream>
using namespace std;

#include "ListaWezel.h"

template<class T>
class CLista
{
public:
	CLista();
	~CLista();
	void drukuj() const; // zmienione na const, bo operator << nic nie moze zmieniac
	void wstawPoczatek(T);
	void wstawKoniec(T);
	void wstawPosortowany(T);
	T usun_co_n(int n);

	template<class T>
	friend ostream& operator<<(ostream& out, const CLista<T>& el);

protected:
	ListaWezel<T> *glowa;
	ListaWezel<T> *ogon;
	bool czyPusta() const;

};


template<class T>
CLista<T>::CLista()
{
	glowa = nullptr;
	ogon = nullptr;
}

template<class T>
CLista<T>::~CLista()
{
	if (!czyPusta())
	{
		ListaWezel<T> *bierzacy = glowa;
		ListaWezel<T> *temp;

		while (bierzacy != ogon)
		{
			temp = bierzacy;
			bierzacy = bierzacy->nastepny;
			delete temp;
		}
		delete bierzacy;
	}
}
//template<> // dla char*
//CLista<char*>::~CLista()
//{
//	if (!czyPusta())
//	{
//		ListaWezel<char*> *bierzacy = glowa;
//		ListaWezel<char*> *temp;
//
//		while (bierzacy != ogon)
//		{
//			temp = bierzacy;
//			bierzacy = bierzacy->nastepny;
//			delete temp;
//		}
//		delete bierzacy;
//	}
//}

template<class T>
bool CLista<T>::czyPusta() const
{
	if (glowa == nullptr && ogon == nullptr)
		return 1;
	else
		return 0;
}

template<class T>
void CLista<T>::wstawPoczatek(T _dane)
{
	if (czyPusta())
	{
		ListaWezel<T> *nowy_wezel = new ListaWezel<T>(_dane);
		glowa = nowy_wezel;
		ogon = nowy_wezel;
		ogon->nastepny = glowa;
	}
	else
	{
		ListaWezel<T> *nowy_wezel = new ListaWezel<T>(_dane);
		nowy_wezel->nastepny = glowa;
		glowa = nowy_wezel;
		ogon->nastepny = glowa;
	}
}

//template<> // dla char*
//void CLista<char*>::wstawPoczatek(char* _dane)
//{
//	if (czyPusta())
//	{
//		ListaWezel<char*> *nowy_wezel = new ListaWezel<char*>(_dane);
//		glowa = nowy_wezel;
//		ogon = nowy_wezel;
//		ogon->nastepny = glowa;
//	}
//	else
//	{
//		ListaWezel<char*> *nowy_wezel = new ListaWezel<char*>(_dane);
//		nowy_wezel->nastepny = glowa;
//		glowa = nowy_wezel;
//		ogon->nastepny = glowa;
//	}
//}

template<class T>
void CLista<T>::wstawKoniec(T _dane)
{
	if (czyPusta())
	{
		ListaWezel<T> *nowy_wezel = new ListaWezel<T>(_dane);
		glowa = nowy_wezel;
		ogon = nowy_wezel;
		ogon->nastepny = glowa;
	}
	else
	{
		ListaWezel<T> *nowy_wezel = new ListaWezel<T>(_dane);
		ogon->nastepny = nowy_wezel;
		ogon = nowy_wezel;
		ogon->nastepny = glowa;
	}
}
//template<> // dla char*
//void CLista<char*>::wstawKoniec(char* _dane)
//{
//	if (czyPusta())
//	{
//		ListaWezel<char*> *nowy_wezel = new ListaWezel<char*>(_dane);
//		glowa = nowy_wezel;
//		ogon = nowy_wezel;
//		ogon->nastepny = glowa;
//	}
//	else
//	{
//		ListaWezel<char*> *nowy_wezel = new ListaWezel<char*>(_dane);
//		ogon->nastepny = nowy_wezel;
//		ogon = nowy_wezel;
//		ogon->nastepny = glowa;
//	}
//}

template<class T>
void CLista<T>::wstawPosortowany(T _dane)
{
	if (czyPusta())
	{
		wstawPoczatek(_dane);
	}
	else
	{
		if (_dane < glowa->dane)
		{
			wstawPoczatek(_dane);
		}
		else if (_dane >= ogon->dane)
		{
			wstawKoniec(_dane);
		}
		else
		{
			ListaWezel<T> * bierzacy = glowa;
			ListaWezel<T> *nowy_wezel = new ListaWezel<T>(_dane);
			while (bierzacy != ogon)
			{
				if ((nowy_wezel->dane < bierzacy->nastepny->dane) && (nowy_wezel->dane >= bierzacy->dane))
				{
					ListaWezel<T> *next_node = bierzacy->nastepny;
					bierzacy->nastepny = nowy_wezel;
					nowy_wezel->nastepny = next_node;
					break;
				}
				bierzacy = bierzacy->nastepny;
			}
		}
	}
}

template<> // dla char*
void CLista<char*>::wstawPosortowany(char* _dane)
{
	if (czyPusta())
	{
		wstawPoczatek(_dane);
	}
	else
	{
		if (strcmp(_dane, glowa->dane) < 0)
		{
			wstawPoczatek(_dane);
		}
		else if (strcmp(_dane, ogon->dane) >= 0)
		{
			wstawKoniec(_dane);
		}
		else
		{
			ListaWezel<char*> * bierzacy = glowa;
			ListaWezel<char*> *nowy_wezel = new ListaWezel<char*>(_dane);
			while (bierzacy != ogon)
			{
				if (strcmp(nowy_wezel->dane, bierzacy->nastepny->dane) < 0 && strcmp(nowy_wezel->dane, bierzacy->dane) >= 0)
				{
					ListaWezel<char*> *next_node = bierzacy->nastepny;
					bierzacy->nastepny = nowy_wezel;
					nowy_wezel->nastepny = next_node;
					break;
				}
				bierzacy = bierzacy->nastepny;
			}
		}
	}
}

template<class T>
void CLista<T>::drukuj() const
{
	if (czyPusta())
	{
		cout << "Lista jest pusta" << endl;

	}
	else
	{
		ListaWezel<T> *bierzacy = glowa;

		cout << "Zawartosc listy: ";
		while (bierzacy != ogon)
		{
			cout << bierzacy->dane << ' ';
			bierzacy = bierzacy->nastepny;
		}
		cout << bierzacy->dane << endl;
	}
}

	template<class T>
	ostream& operator<<(ostream& out, const CLista<T>& el)
	{
		el.drukuj();
		return out;
	}

template<class T>
T CLista<T>::usun_co_n(int n)
{
	if (czyPusta())
	{
		cout << "Lista jest pusta" << endl;
	}
	else
	{
		ListaWezel<T> *biezacy = glowa;
		int licznik = 0;
		n--;
		while (glowa != ogon)
		{
			while (licznik < n)
			{
				biezacy = biezacy->nastepny;
				licznik++;
				if (biezacy->nastepny == nullptr && licznik < n)
				{
					biezacy = glowa;
					licznik++;
				}
			}
			ListaWezel<T>* do_usuniecia = biezacy->nastepny;
			licznik = 0;
			if (do_usuniecia == glowa) // glowa do usuniecia
			{
				do_usuniecia = glowa;
				glowa = glowa->nastepny;
				ogon->nastepny = glowa;
				delete do_usuniecia;
			}
			else if (do_usuniecia == ogon) // ogon do usuniecia
			{
				ogon = biezacy;
				ogon->nastepny = glowa;
				delete do_usuniecia;
			}
			else // usuwanie ze srodka
			{
				biezacy->nastepny = do_usuniecia->nastepny;
				delete do_usuniecia;
			}
		}
	}
	return glowa->dane;
}
#endif
