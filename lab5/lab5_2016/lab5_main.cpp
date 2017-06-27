#include <iostream> 
using namespace std;
#include "maska.h"
#include "sygnal.h"


int main ()
{
	double f1[3] = {1, 1, 1};
	double w[8] = {1, 2, 1, 0, 1, 2, 1, 0};

	cout << endl << "*********************** Etap 1 ***********************" << endl << endl;

	Sygnal s0;
	Sygnal s1(8);
	Sygnal s2(8,w);

	cout << "Sygnal s0: " << s0 << endl;
	cout << "Sygnal s1: " << s1 << endl;
	cout << "Sygnal s2: " << s2 << endl;

	cout << endl << "*********************** Etap 2 ***********************" << endl << endl;

	Maska m0(3);
	Maska m1(3,f1);

	cout << "Maska m0: " << m0 << endl;
	cout << "Maska m1: " << m1 <<  endl;
	cout << "Suma wspolczynnikow m1: " << m1() << endl;

	cout << endl << "*********************** Etap 3 ***********************" << endl << endl;
	
	s0 = s2;
	s0.sortuj();
	cout << "Posortowany s2: " << s0 << endl;
	
	cout << "Filtracja medianowa s0 z maska m0: " << s0.filtracja_medianowa(m0) << endl;

	s0 = s2.filtracja_medianowa(m0);
	cout << "Filtracja medianowa s2 z maska m0: " << s0 << endl;

	cout << endl;

	system("PAUSE");
	return 0;
}

