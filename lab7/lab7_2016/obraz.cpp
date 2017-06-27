#include <Windows.h>
#include "obraz.h"

//----------------------------------------------------
void obraz::init_kolory(int _n, int* _kolory)	//ZAIMPLEMENTOWANA!
{
	n=0; kolory=nullptr;

	if (_n>0)
	{
		kolory=new (nothrow) int[_n];
		if (!kolory)  return;

		n=_n;
		if(_kolory)
			for (int i=0; i<n; i++) kolory[i]=_kolory[i];
		else
			for (int i=0; i<n; i++) kolory[i]=15;	//BIA£Y
	}
}
//----------------------------------------------------
obraz::obraz()
{
	init_kolory(0);
}
//----------------------------------------------------
obraz::obraz(int m, int n, dane* d): wektor(m) //38 //219 //D[]
{
	int max_kod_znaku = 0;
	int kol = 0, wier = 0; // iteratory
	for (int i = 0; i < n; i++) // dla kazdego elemetnu D[]
	{
		//--------------- // szukanie max_kod_znaku
		if (max_kod_znaku < d[i].kod_znaku) max_kod_znaku = d[i].kod_znaku;
		//---------------
		if (d[i].kod_znaku == 0)
		{
			wier = wier + d[i].n; // przeskoczenie do nast wierszy
			kol = 0;
		}
		for (int j = 0; j < d[i].n; j++, kol++)
		{
			wektor::operator()(wier, kol) = d[i].kod_znaku;
		}
	}
	max_kod_znaku++;
	init_kolory(max_kod_znaku);
}
//----------------------------------------------------
void obraz::skaluj(int k)
{
	int wier = 0, kol = 0; // iteratory
	if (k < 0)
	{
		wektor powiekszony(2 * wymiar());
		for (int i = 0; i < powiekszony.wymiar(); i = i + 2, wier++)
		{
			for (int j = 0; j < powiekszony.wymiar(); j = j + 2, kol++)
			{
				powiekszony(i, j) = wektor::operator()(wier, kol);
				powiekszony(i, j + 1) = wektor::operator()(wier, kol);
				powiekszony(i + 1, j) = wektor::operator()(wier, kol);
				powiekszony(i + 1, j + 1) = wektor::operator()(wier, kol);
				//powiekszony(i + 1, j + 1) = (*this)(wier, kol);
			}
			kol = 0;
		}
		powiekszony(powiekszony.wymiar(), powiekszony.wymiar()) = 0;
		/*init(powiekszony.wymiar());
		for (int i = 0; i < powiekszony.wymiar(); i++)
			for (int j = 0; j < powiekszony.wymiar(); j++)
			{
				wektor::operator()(i, j) = powiekszony(i, j);
			}
		wektor::operator()(powiekszony.wymiar(), powiekszony.wymiar()) = 0;*/
		(wektor&)*this = powiekszony; // troche krotsze niz to co wyzej w komencie ...
	}
	if (k > 0)
	{
		wektor pomniejszony(wymiar() / 2);
		for (int i = 0; i < pomniejszony.wymiar(); i++, wier = wier + 2)
		{
			for (int j = 0; j < pomniejszony.wymiar(); j++, kol = kol + 2)
			{
				pomniejszony(i, j) = wektor::operator()(wier, kol);
			}
			kol = 0;
		}
		pomniejszony(pomniejszony.wymiar(), pomniejszony.wymiar()) = 0;
		/*init(pomniejszony.wymiar());
		for (int i = 0; i < pomniejszony.wymiar(); i++)
			for (int j = 0; j < pomniejszony.wymiar(); j++)
			{
				wektor::operator()(i, j) = pomniejszony(i, j);
			}
		wektor::operator()(pomniejszony.wymiar(), pomniejszony.wymiar()) = 0;*/
		(wektor&)*this = pomniejszony; // krotsza wersja skomentowanego wyzej
	}
}
//----------------------------------------------------
void obraz::dodaj_kolor(char* znak, int kolor)
{
	znak[2] = 0;
	int what = 10 * (int)(znak[0] - '0') + (int)(znak[1] - '0'); // nie da sie prosciej???
	if (what > 0 && what <= n)
	{
		kolory[what] = kolor;
	}
}
//----------------------------------------------------
obraz::obraz(const obraz& P): wektor(P), n(P.n)
{
	if (P.kolory)
	{
		kolory = new int[n];
		for (int i = 0; i < n; i++)
		{
			kolory[i] = P.kolory[i];
		}
	}
}
//---------------------------------------------------
obraz& obraz::operator=(const obraz& P)
{
	if(this != &P)
	{
		(wektor&)*this = P; // nie da sie uzyc kostruktora obraz(P) ???
		n = P.n;
		kolory = new int[n];
		for (int i = 0; i < n; i++)
		{
			kolory[i] = P.kolory[i];
		}
	}
	return *this;
}
//---------------------------------------------------
obraz::~obraz()
{
	delete[] kolory;
}
//---------------------------------------------------
ostream& operator<<(ostream& out, const obraz& P)	//ZAIMPLEMENTOWANY!
{
	for (int i=0;i<P.wymiar();i++){
		for(int j=0;j<P.wymiar();j++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), P.kolory[P(i,j)]);	
			out<<P(i,j);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	
		}
		out<<endl;
	}
	return out;
}
//---------------------------------------------------