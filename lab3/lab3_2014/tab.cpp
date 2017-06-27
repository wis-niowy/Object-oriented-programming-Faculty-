 
#include "tab.h"

// TUTAJ zaimplementuj sk³adowe i funkcje zaprzyjaŸnione klasy tab
// (tylko niezbêdne)
double tab::Det() const
{
	double przek11 = w[0][0] * w[1][1] * w[2][2];
	double przek12 = w[0][1] * w[1][2] * w[2][0];
	double przek13 = w[1][0] * w[2][1] * w[0][2];
	double przek21 = w[2][0] * w[1][1] * w[0][2];
	double przek22 = w[1][0] * w[0][1] * w[2][2];
	double przek23 = w[0][0] * w[2][1] * w[1][2];
	return przek11 + przek12 + przek13 - przek21 - przek22 - przek23;
}
tab tab::Col(int i, const wek& v)
{
	tab zwroc;
	for (int k = 0; k < N; k++)
		for (int j = 0; j < N; j++)
	{
		zwroc.w[k][j] = w[k][j];
	}
	for (int j = 0; j < N; j++)
	{
		zwroc.w[j][i] = v[j];
	}
	return zwroc;
}
tab::tab(double* tab)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			w[i][j] = tab[i*N + j];
		}
}
ostream& operator<<(ostream& out, tab A)
{
	for (int i = 0; i < N; i++)
	{
		out << "| ";
		for (int j = 0; j < N; j++)
		{
			out << A.w[i][j] << " ";
		}
		out << "|" << endl;
	}
	return out;
}
wek operator*(const tab& A, const wek& v)
{
	wek wynik;
	for (int i = 0; i < N; i++)
	{
		wynik[i] = A.w[i] * v;
	}
	return wynik;
}