#include <iostream> 
using namespace std;
#include "maska.h"

// zaimplementuj



ostream& operator<<(ostream& out, const Maska& m) 
{ 
	out << "Maska o rozmiarze " << m.rozmiar << " i wspolczynnikach [";
	if (m.wspolczynniki)
		for (int i = 0; i < m.rozmiar; i++)
			out << "  " << m.wspolczynniki[i] << " ";
	out << " ]";
	return out; 
}
//////////////////////////// 2 ETAP ///////////////////////////////////
Maska::Maska(int ile, double* _wspolczynniki)
{
	if (ile < 3 || ile % 2 == 0) return;
	rozmiar = ile;
	
	if (!_wspolczynniki)
		return;
	else
		wspolczynniki = new double[ile];
		for (int i = 0; i < ile; i++)
		{
			wspolczynniki[i] = _wspolczynniki[i];
		}
}
double Maska::operator()()
{
	double suma = 0;
	for (int i = 0; i < rozmiar; i++)
	{
		suma = suma + wspolczynniki[i];
	}
	return suma;
}