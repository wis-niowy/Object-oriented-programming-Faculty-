#include <iostream>
#include "CLista.h"
#include "ListaWezel.h"
using namespace std;

// tutaj definicja szablonu funkcji KtoPrzezyje (etap 5)
template<template <class S> class T, class S>
void KtoPrzezyje(S tab[], int _roz, int n, S& kto)
{
	T<S> Lista;
	for (int i = 0; i < _roz; i++)
	{
		Lista.wstawPosortowany(tab[i]);
	}
	kto = Lista.usun_co_n(n);
	int yolo = 70;
}

int main()
{
	const int rozmiar = 8;
	int numer[rozmiar] = {5, 1, 4, 8, 6, 2, 7, 3};
	char* imie[rozmiar] = {"Powstaniec5", "Powstaniec1", "Powstaniec4", "Powstaniec8", "Powstaniec6", "Powstaniec2", "Powstaniec7", "Powstaniec3"};

	cout << " ****************** Etap 1 ****************** " << endl << endl;

	CLista<int> intLista;

	for(int i = 0; i <= rozmiar-1;  i++)
	{
		intLista.wstawPosortowany(numer[i]); 
	}

	intLista.drukuj();
	cout << endl;

	CLista<char*> chLista;

	for(int i = 0; i <= rozmiar-1;  i++)
	{
		chLista.wstawPosortowany(imie[i]); 
	}

	chLista.drukuj();
	cout << endl;

	cout << " ****************** Etap 2 ****************** " << endl << endl;

	cout << "Wypisanie listy typu <int> za pomoac zaprzyjaznionego operatora <<: " << endl; 
	cout << intLista << endl;

	cout << " ****************** Etap 3 ****************** " << endl << endl;

	CLista<char*> chsLista;

	for(int i = 0; i <= rozmiar-1;  i++)
	{
		chsLista.wstawPosortowany(imie[i]); 
	}

	cout << chsLista << endl;

	cout << " ****************** Etap 4 ****************** " << endl << endl;
	
	int n = 3; // ginie co trzeci

	cout << "Posortowana lista typu <int> (np. numer): " << endl << intLista << endl;
	cout << "Ocalaly: " << intLista.usun_co_n(n);
	cout << endl << endl;
	
	cout << "Posortowana lista typu <*char> (np. imie): " << endl << chsLista << endl;
	cout << "Ocalaly: " << chsLista.usun_co_n(n);
	cout << endl << endl;
	
	cout << " ****************** Etap 5 ****************** " << endl << endl;

	int i_kto;
	KtoPrzezyje<CLista, int>(numer, rozmiar, n, i_kto);
	cout << "Ocalaly: " << i_kto << endl;
	char* ch_kto;
	KtoPrzezyje<CLista, char*>(imie, rozmiar, n, ch_kto);
	cout << "Ocalaly: " << ch_kto << endl;

	system("PAUSE");
	return 0;
}