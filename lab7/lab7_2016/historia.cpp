
#include "historia.h"



historia::historia(const obraz& _P)
{
	int ilosc_obrazow = ile + 1;
	if (ilosc_obrazow > 0 && ilosc_obrazow <= N)
	{
		P[N - ile-1] = _P;
		ile++;
	}
	else if (ilosc_obrazow > N)
	{
		for (int i = 0; i < N - 1; i++)
		{
			P[i] = P[i + 1];
		}
		P[N - 1] = _P;
	}
	else
	{
		ile = 0;
		P[ile] = _P;
	}
}
//----------------------------------------------------	
void historia::zapisz(const obraz& _P)
{
	int ilosc_obrazow = ile + 1;
	if (ilosc_obrazow > 0 && ilosc_obrazow <= N)
	{
		P[N - ile - 1] = _P;
		ile = ile + 1;
	}
	else if (ilosc_obrazow > N)
	{
		for (int i = 0; i < N - 1; i++)
		{
			P[i] = P[i + 1];
		}
		P[N - 1] = _P;
	}
	else
	{
		ile = 0;
		P[ile] = _P;
	}
}
//----------------------------------------------------		
obraz historia::undo()
{
	if (ile > 1 && ile <= N) return P[ile - 2];
	else if (ile == 1) return P[0];
}
//----------------------------------------------------
historia::~historia()
{
	delete[] P;
}
