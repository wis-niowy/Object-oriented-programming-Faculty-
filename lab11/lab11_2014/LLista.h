#ifndef LLISTA_H
#define LLISTA_H

#include <iostream>
using namespace std;

#include "LListaWezel.h"

class CLista 
{
public:
	CLista();
	~CLista();
	void drukuj(); 
	void wstawPoczatek(int);
	void wstawKoniec(int); 
	void wstawPosortowane(int); 

protected:
	ListaWezel *glowa; 
	ListaWezel *ogon; 
	bool czyPusta() const; 

};

#endif