#include "tab.h"

wek Cramer(tab A, wek b)        //rozwiazuje uklad:  A*x = b
{
    double d = A.Det();
    return wek(A.Col(0,b).Det()/d, A.Col(1,b).Det()/d, A.Col(2,b).Det()/d);
}

double dane_A[] = { 3, 4, 1,   5, 3, 0,   2, 1, 6, };
double dane_b[] = { 70, 55, 110, };                    

int main()
{
    tab A(dane_A);
    wek b(dane_b), x;
	cout << endl;
    cout << "A="<<endl<<A << endl;
    cout << "b="<<endl<<b << endl;
	
	double d=A.Det();

	if (!d)
	{
		cout<<"Uk³ad jest sprzeczny lub nie posiada jednoznacznego rozwi¹zania !"<<endl;
		system("PAUSE");
		return 0;
	}
	
    cout <<"det = " << A.Det() << endl <<endl;
   
    x = Cramer(A,b);
    cout << "Znaleziony x= "<< x << endl;

    // sprawdzenie
    wek y = A*x;
    cout << "Obliczona prawa strona A*x= "<<y<<endl;

	if (y==b) 
		cout<<"x="<<x<<" jest poprawnym rozwiazaniem"<<endl<<endl;
	else
	{
		cout << "x=" << x << " NIESTETY w obliczeniach sa bledy !!!" << endl << endl;
	}
	system("PAUSE");
	return 0;
	
}