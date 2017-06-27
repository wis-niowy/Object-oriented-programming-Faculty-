#include "wektor.h"
//----------------------------------------------------
void wektor::init(int _m, char* _t)
{
	m = _m;
	t = new char[_m * _m + 1];
	if (!_t)
	{
		for (int i = 0; i < _m * _m + 1; i++)
		{
			t[i] = 0;
		}
	}
	else
	{
		for (int i = 0; i < _m * _m; i++)
		{
			t[i] = _t[i];
		}
		t[_m * _m] = 0;
	}
}
//----------------------------------------------------
void wektor::zwolnij()
{
	delete[] t;
}
//----------------------------------------------------
wektor::wektor(int m)
{
	init(m);	//wyzerowana tablica
}
//----------------------------------------------------
wektor::wektor(const wektor& P)
{
	init( P.m, P.t);
}
//----------------------------------------------------
wektor& wektor::operator=(const wektor& P)
{
	if (this!=&P)
	{
		zwolnij();
		init( P.m, P.t);
	}

	return *this;
}
//----------------------------------------------------
wektor::~wektor()
{
	zwolnij();
}
//----------------------------------------------------
