#include <iostream> 
using namespace std; 
#include "punkt.h"
#include "odcinek.h"
#include "lamana.h"

int main()
{
	cout << "************** ETAP 1 **************" << endl;
	Punkt p1;
	cout << p1 << endl;
	cin >> p1;
	cout << p1 << endl;
	Punkt p2(0,1);
	cout << p2 << endl;
	Punkt p3(p2);
	cout << p2 << endl;

	p3.przesun(1,-1);
	cout << p3 << endl;
	cout << "Odleglosc p2 od p3 wynosi: " << odleglosc(p2,p3) << endl;

	cout << "************** ETAP 2 **************" << endl;
	Odcinek o1;
	cout << o1 << endl;
	Odcinek o2(p2,p3);
	cout << o2 << endl;
	cout << "Odleglosc srodka odcinka " << o2 << " od punktu P(1,1) wynosi: " << odleglosc(o2,Punkt(1,1)) << endl;

	cout << "************** ETAP 3 **************" << endl;
	Odcinek odcinki1[2] = {Odcinek(Punkt(0,0),Punkt(2,3)) , Odcinek(Punkt(2,3),Punkt(5,2))};
	Odcinek odcinki2[2] = {Odcinek(Punkt(5,2),Punkt(8,8)), Odcinek(Punkt(8,8),Punkt(9,3))};
	
	Lamana l1(5);
	cout << l1 << endl;
	Lamana l2(odcinki1,2);
	Lamana l3(odcinki2,2);
	cout << l2 << endl;
	cout << l3 << endl;
	l1 = l2 + l3;
	cout << l1 << endl;
	l1 = l2 + l2;
	cout << l1 << endl;

	system("PAUSE");
	return 0;
}