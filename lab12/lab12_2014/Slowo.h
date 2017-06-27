#pragma once
#include <iostream>
using namespace std;
#include <fstream>


const int N=30; 

class Slowo{
	float trud;
	char pol[N+1];
	char ang[N+1];
public:
	Slowo(char [], char[], float);
	Slowo();

	char * Pol() {return pol;}
	char * Ang() {return ang;}
	float Trud(){return trud;}

	friend bool operator==(const Slowo&, const Slowo &);
	friend ostream& operator<<(ostream &, const Slowo &);
	friend istream& operator>>(istream &, Slowo &);
};
