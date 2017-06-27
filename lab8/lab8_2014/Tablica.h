#pragma once
#include<iostream>
using namespace std;

class Tablica
{
protected:
	int rozmiar;
	int *tab;

public:
	Tablica(int _rozmiar=0, int *_tab=nullptr);
	Tablica(const Tablica &t);
	~Tablica();
	Tablica& operator=(const Tablica &t);

	Tablica& operator--(); // zmniejsza wartosc wszystkich elementow tablicy o 1
	void ogranicz_min_max(int min, int max); // ogranicza wartosc w tablicy od dolu i od gory odpowiednio do min i max

	friend Tablica operator+(const Tablica &t1, const Tablica &t2); // dodaje dwie tablice
	friend ostream& operator<<(ostream &out, Tablica &t); 
};
