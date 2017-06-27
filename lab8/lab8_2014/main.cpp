#include <iostream>
#include <time.h>
using namespace std;

#include "Tablica.h"
#include "Obraz.h"
#include "Histogram.h"


int main()
{
	// Etap 1
	cout << " ************** Etap 1 ************** " << endl;

	int arr[] = {1,2,3,4,5,6,7,8};

	Tablica t1;
	cout << t1 << endl;
	
	Tablica t2(8, arr);
	cout << t2 << endl;

	Tablica t3(t2);
	t3.ogranicz_min_max(2, 5);
	cout << t3 << endl;

	t1 = --t2 + t3;
	cout << t1 << endl;

	cout << endl << endl;
	
	// Etap 2
	cout << " ************** Etap 2 ************** " << endl;

	int arr2[] = {1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};

	Obraz o1;
	cout << o1 << endl;

	Obraz o2(8, 8, 8, arr2);
	cout << o2 << endl;

	Obraz o3(o2);
	o3.ogranicz_min_max(2, 5);
	cout << o3 << endl;

	o1 = --o2 + o3;
	cout << o1 << endl;
	
	cout << endl << endl;

	// Etap 3
	cout << " ************** Etap 3 ************** " << endl;

	Histogram h1;
	cout << h1 << endl;

	Histogram h2(8);
	cout << h2 << endl;

	Histogram h3(h1);
	h3.oblicz(o2);
	cout << o2 << endl << h3 << endl;

	h1.oblicz(o1);
	cout << o1 << endl << h1 << endl;

	cout << endl << endl;

	system("PAUSE");
	return 0;
}