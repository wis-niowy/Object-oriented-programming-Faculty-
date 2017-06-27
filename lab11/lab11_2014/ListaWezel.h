#define _CRT_SECURE_NO_WARNINGS
#ifndef LISTA_WEZEL_H
#define LISTA_WEZEL_H
#include<string.h>

// tutaj definicja szablonu klasy ListaWezel (elementu listy)

template<class T>
class CLista;

template<class Q>
class ListaWezel
{
	friend class CLista<Q>;

public:
	ListaWezel(Q);
	Q pobierzDane();

private:
	Q dane;
	ListaWezel<Q>* nastepny;
};

template<class Q>
ListaWezel<Q>::ListaWezel(Q _dane)
{
	dane = _dane;
	nastepny = nullptr;
}

template<class Q>
Q ListaWezel<Q>::pobierzDane()
{
	return dane;
}

//// specjalizacja dla char* ////////////////////////////////////

template<>
class ListaWezel<char*>
{
	friend class CLista<char*>;

public:
	ListaWezel(char*);
	~ListaWezel();
	char* pobierzDane();

private:
	char* dane;
	ListaWezel<char*>* nastepny;
};

ListaWezel<char*>::ListaWezel(char* _wejscie)
{
	int dlugosc = strlen(_wejscie);
	dane = new char[dlugosc + 1];
	strcpy(dane, _wejscie);
	dane[dlugosc] = 0;
	nastepny = nullptr;
}

ListaWezel<char*>::~ListaWezel()
{
	delete[] dane;
}

char* ListaWezel<char*>::pobierzDane()
{
	return dane;
}
#endif
