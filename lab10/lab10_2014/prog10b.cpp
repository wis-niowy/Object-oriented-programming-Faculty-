
#include <iostream>
using namespace std;
#include "wielomian.h"
#include "cosinus.h"
#include "funkcja.h"
#include "cmplx.h"

const double EPS=1e-6;	//dokladnosc poszukiwania pierwiastka wielomianu
const int MAX_ITER=50;	//maksymalna liczba iteracji


//------------------------------------------------

//template<class P, template <class > class WIEL> // szablon WIEL przekazany do szablonu
//P pierwiastek(WIEL<P> wiel, P start, int& iter)

	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// jesli COSINUS to zwykla klasa to dziala tylko ta nizsza deklaracja szablonu
	// jesli COSINUS to szablon dzedziczacy szablon wielomian
	// to dziala wyzsza deklaracja szablonu przyjmujaca jako argument inny szablon
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

template<class P, class WIEL>
P pierwiastek(WIEL wiel, P start, int& iter)
	{
		P wynik = start;
		for (iter = 0; iter < MAX_ITER; iter++)
		{
			wynik = wynik - (wiel(wynik) / wiel(wynik, 1));
			if (abs(wiel(wynik)) <= EPS)
			{
				iter++;
				break;
			}
		}
		return wynik;
	}


//------------------------------------------------

double f1(double x)
{
	return 2 + sin(x) - exp(x);
}

//-------------------------------------------------

double f2(double x)
{
	return 2 + x + x*x*x;
}

//-------------------------------------------------
int main()
{
    cout<<"----------------   ETAP 1   (3 pkt) ------------------------"<<endl;
   
    double tab[3+1] = { 2, 1, 0, 1};
    wielomian<double> P(3,tab);

    cout<<"wielomian P(x): "<< P;		
    cout<<"pochodna P(x): "<< P.Pochodna(); 
		
    double x = 2;
	cout<<"wartosc wielomianu P dla x="<<x<<" wynosi: "<<P(x)<<endl;
	cout<<"wartosc pochodnej P dla x="<<x<<" wynosi: "<<P(x,1)<<endl;


	CMPLX tab_CMPLX[4+1]={CMPLX(2,-1),CMPLX(1,2),CMPLX(0,0),CMPLX(1,-10),CMPLX(10,-40)};
	wielomian<CMPLX> W_CMPLX(4,tab_CMPLX);
	CMPLX z=CMPLX(2,1);
	cout<<"wartosc wielomianu W_CMPLX dla z="<<z<<" wynosi: "<<W_CMPLX(z)<<endl;
	cout<<"wartosc pochodnej W_CMPLX dla z="<<z<<" wynosi: "<<W_CMPLX(z,1)<<endl;
		
		
	cout<<"----------------   ETAP 2  (2 pkt) ------------------------"<<endl;
	
	
	double start1=2, zero1;
	int iter1;

	zero1=pierwiastek(P, start1, iter1);
	cout<<"Znalezione zero: "<<zero1<<endl;
	cout<<"Liczba iteracji: "<<iter1<<endl;
	cout<<"Sprawdzenie r-nia: "<<P(zero1)<<endl;
	
	//----------------------------------------------------------
	
	CMPLX start2=CMPLX(4,2), zero2;
	int iter2;

	zero2=pierwiastek(W_CMPLX, start2, iter2);
	cout<<"Znalezione zero: "<<zero2<<endl;
	cout<<"Liczba iteracji: "<<iter2<<endl;
	cout<<"Sprawdzenie r-nia: "<<W_CMPLX(zero2)<<endl;
	
    cout<<"----------------   ETAP 3  (1 pkt) ------------------------"<<endl;
	
	double start3=2, zero3;
	int iter3;
	COSINUS<double> c;
		
	zero3=pierwiastek(c, start3, iter3);
	cout<<"Znalezione zero: "<<zero3<<endl;
	cout<<"Liczba iteracji: "<<iter3<<endl;
	cout<<"Sprawdzenie r-nia: "<<c(zero3)<<endl;
	
	cout<<"----------------   ETAP 4  (2 pkt) ------------------------"<<endl;
	
	double start4=2, zero4;
	int iter4;

	FUNKCJA<f1> fun1;
	zero4=pierwiastek(fun1, start4, iter4);
	cout<<"Znalezione zero: "<<zero4<<endl;
	cout<<"Liczba iteracji: "<<iter4<<endl;
	cout<<"Sprawdzenie r-nia: "<<fun1(zero4)<<endl;
	
    //----------------------------------------------------------
	
	FUNKCJA<f2> fun2;
	zero4=pierwiastek(fun2, start4, iter4);
	cout<<"Znalezione zero: "<<zero4<<endl;
	cout<<"Liczba iteracji: "<<iter4<<endl;
	cout<<"Sprawdzenie r-nia: "<<fun2(zero4)<<endl;
	
	cout<<"----------------   KONIEC   ------------------------"<<endl;
	system("PAUSE");
}

/* WYNIKI
----------------   ETAP 1   (3 pkt) ------------------------
wielomian P(x): 2+1*x^1+0*x^2+1*x^3
pochodna P(x): 1+0*x^1+3*x^2
wartosc wielomianu P dla x=2 wynosi: 12
wartosc pochodnej P dla x=2 wynosi: 13
wartosc wielomianu W_CMPLX dla z=(2,1) wynosi: (1004,515)
wartosc pochodnej W_CMPLX dla z=(2,1) wynosi: (1970,44)
----------------   ETAP 2  (2 pkt) ------------------------
Znalezione zero: -1
Liczba iteracji: 8
Sprawdzenie r-nia: -1.85965e-010
Znalezione zero: (0.154924,0.375197)
Liczba iteracji: 15
Sprawdzenie r-nia: (9.6068e-007,1.60761e-007)
----------------   ETAP 3  (1 pkt) ------------------------
Znalezione zero: 1.5708
Liczba iteracji: 3
Sprawdzenie r-nia: 6.12323e-017
----------------   ETAP 4  (2 pkt) ------------------------
Znalezione zero: 1.05413
Liczba iteracji: 5
Sprawdzenie r-nia: -5.60244e-010
Znalezione zero: -1
Liczba iteracji: 8
Sprawdzenie r-nia: -1.93871e-010
----------------   KONIEC   ------------------------
Aby kontynuowaæ, naciœnij dowolny klawisz . . .
*/