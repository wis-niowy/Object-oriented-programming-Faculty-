
#include "wek.h"

class tab  //tablica 3x3
{
    wek w[N];     //w[i] jest i-tym wierszem tablicy
public:
	// TUTAJ podaj deklaracje tylko potrzebnych sk≥adowych i funkcji zaprzyjaünionych
	double Det() const;
	tab(){};
	tab Col(int i, const wek& v);
	tab(double*);
	friend ostream& operator<<(ostream&, tab);
	friend wek operator*(const tab&, const wek&);
};



