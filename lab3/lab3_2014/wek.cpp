
#include "wek.h"

// TUTAJ zaimplementuj sk³adowe i potrzebne funkcje wspomagaj¹ce dla klasy wek
wek::wek(double a, double b, double c)
{
	int temp[3] = { a, b, c, };
	for (int i = 0; i < N; i++)
		x[i] = temp[i];
}
wek::wek(double* a) // konstruktor kopiujacy
{
	cout << sizeof(a) << endl;
	for (int i = 0; i < N; i++)
	{
		x[i] = a[i];
	}
}
double wek::operator*(const wek& b) const
{
	double suma = 0;
	for (int i = 0; i < N; i++)
	{
		int temp = x[i] * b.x[i];
		suma = suma + temp;
	}
	return suma;
}
double& wek::operator[](int i)
{
	return x[i];
}
double wek::operator[](int i) const
{
	return x[i];
}
bool operator==(const wek& w1, const wek& w2)
{
	bool check = true;
	for (int i = 0; i < N; i++)
	{
		if (!(w1.x[i] == w2.x[i]))
		{
			check = false;
			break;
		}
	}
	return check;
}
ostream& operator<<(ostream& out, const wek& v)
{
	out << "[ ";
	for (int i = 0; i < N; i++)
	{
		out << v.x[i] << " ";
	}
	out << "]";
	return out;
}
