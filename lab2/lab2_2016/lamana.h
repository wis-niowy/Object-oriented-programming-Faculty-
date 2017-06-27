#pragma once
#include <iostream> 
using namespace std;
#include "punkt.h"

const int num = 5;

class Lamana
{
	Odcinek ol[num];
	int number;

public:
	Lamana() { };
	Lamana(int number);
	Lamana(Odcinek*, int number); 
	friend Lamana operator+(const Lamana&, const Lamana&);
	friend ostream& operator<<(ostream&, const Lamana&);
	Odcinek getol(int indeks) const { return ol[indeks]; };
	void setol(Odcinek p, int i);
	int getnumber() const { return number; };
	void setnumber(int a) { number = a; };
};


